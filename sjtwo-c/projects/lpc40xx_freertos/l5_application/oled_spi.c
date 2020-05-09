#include "oled_spi.h"
#include "Control_Button.h"
#include "delay.h"
#include "ff.h"
#include "font8x8_basic.h"
// #include "ssp2_lab.h"
#include "ssp0.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <stddef.h>
#include "FreeRTOS.h"
#include "acceleration.h"
#include "audio_decoder.h"
#include "queue.h"
#include <math.h>

/// Set to non-zero to enable debugging, and then you can use OLED__DEBUG_PRINTF()
#define OLED__ENABLE_DEBUGGING 1

#if OLED__ENABLE_DEBUGGING
#include <stdio.h>
#define OLED__DEBUG_PRINTF(f_, ...)                                                                                    \
  do {                                                                                                                 \
    fprintf(stderr, "OLED:");                                                                                          \
    fprintf(stderr, (f_), ##__VA_ARGS__);                                                                              \
    fprintf(stderr, "\n");                                                                                             \
  } while (0)
#else
#define OLED__DEBUG_PRINTF(f_, ...)
#endif

// D0 -> SPI_CLK, D1 -> SPI_MOSI, VCC 3.3 -5V
// 8 pages of address
static port_pin_s OLED_RST_pin = {1, 30};
static port_pin_s OLED_DC_pin = {0, 26}; // choose data or command line
static port_pin_s OLED_CS_pin = {0, 25};

// Private Variable for GUI
static uint8_t Button_Status = 0;
static uint8_t OLED_GUI_Next_Pos = 0;
static bool OLED_GUI_Play_Status = false;
static bool ACC_CTL_MODE = false;

static char Current_play_song_name[16];
static uint32_t Current_song_total_size = 1;
static uint32_t Current_song_sent_size = 0;
static int Current_play_volumn = 0;
static uint8_t Arrow_index = 0;         // this is index of song list
static uint8_t Current_Arrow_index = 1; // this is the index correspronse to each page's arrow
static bool Get_new_song_play = false;
static bool play_first_song = false;
// for playing options page
static bool Bass_status = false;
static bool Treble_status = false;
static int Option_arrow_index = 1;
static int Treble_Amplitude_index = 8;
static int Treble_Frequency_index = 2;
static int Bass_Amplitude_index = 2;
static int Bass_Frequency_index = 2;

static char Treble_F[16] = "TF+------------ ";
static char Treble_A[16] = "TA------+------ ";

static char Bass_F[16] = "BF+------------ ";
static char Bass_A[16] = "BA+------------ ";

// For File scanning
// Private functions

TaskHandle_t task_handle__player;

typedef char song_memory_t[32]; // size of song name

typedef enum song_format {
  _MP3 = 0,
  _WAV = 1,
  _FLAC = 2,
  _Unknown = 3,
};

typedef struct {
  song_memory_t song_name;
  enum song_format song_type;
  uint32_t song_size; // need to divide 1024 to get unit of KB

} song_info;

static song_info list_of_songs[32]; // list of song
static uint8_t number_of_songs = 0; // only support 255 songs

void OLED_CS() {
  gpiox__set_as_output(OLED_CS_pin);
  gpiox__set_low(OLED_CS_pin);
  // delay__us(1);
}
void OLED_DS() {
  gpiox__set_as_output(OLED_CS_pin);
  gpiox__set_high(OLED_CS_pin);
  // delay__us(1);
}
void OLED_DC(bool cmd) {
  gpiox__set_as_output(OLED_DC_pin);
  if (cmd) { // data
    gpiox__set_high(OLED_DC_pin);
  } else { // command
    gpiox__set_low(OLED_DC_pin);
  }
  // delay__us(1);
}
void OLED_RST() {
  gpiox__set_as_output(OLED_RST_pin);
  gpiox__set_high(OLED_RST_pin);
  delay__us(1);

  gpiox__set_low(OLED_RST_pin);
  delay__us(5);

  gpiox__set_high(OLED_RST_pin);
}

void OLED_Send_Data(uint8_t data) {
  OLED_DC(1);
  OLED_CS();
  ssp0__exchange_byte_lab(data);
  OLED_DS();
}

void OLED_Send_Command(uint8_t cmd) {
  OLED_DC(0);
  OLED_CS();
  ssp0__exchange_byte_lab(cmd);
  OLED_DS();
}

void OLED_CLR_Screen() {
  OLED_Send_Command(OLED_Set_Mem_Addr_Mode);
  OLED_Send_Command(0x02); // choose Page Addressing Mode(Reset)

  for (int page = 0; page < 8; page++) {
    OLED_Send_Command(OLED_Set_Display_Start_Line);
    OLED_Send_Command(OLED_Set_Page_Start_Addr_for_Page_mode + page); // 0xB0
    for (int higher_col = 0; higher_col < 8; higher_col++) {
      OLED_Send_Command(OLED_Set_Page_Higher_Column_offset + higher_col); // 0x10
      for (int lower_col = 0; lower_col < 16; lower_col++) {
        OLED_Send_Command(OLED_Set_Page_Lower_Column_offset + lower_col); // 0x00
        OLED_Send_Data(0x00);
      }
    }
  }
}

void OLED_Send_oneChar(uint8_t data) {
  uint8_t bit_map[8][8];
  uint8_t result[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  for (int j = 0; j < 8; j++) {
    for (int i = 0; i < 8; i++) {
      uint8_t temp = font8x8_basic[data][i];
      bit_map[j][i] = (temp >> j) & ~(0xFE);
    }
  }

  int res_index = 0;
  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j < 8; j++) {
      result[res_index] |= bit_map[i][j] << j;
    }
    res_index++;
  }

  for (int i = 7; i >= 0; i--) {
    OLED_Send_Data(result[i]);
  }
}

void OLED_print_string(uint8_t page, uint8_t start_x, uint8_t start_y, uint8_t *data, int length) {
  OLED_Send_Command(OLED_Set_Mem_Addr_Mode);
  OLED_Send_Command(0x02); // choose Page Addressing Mode(Reset)

  OLED_Send_Command(OLED_Set_Display_Start_Line);
  OLED_Send_Command(OLED_Set_Page_Start_Addr_for_Page_mode + page); // 0xB0
  OLED_Send_Command(OLED_Set_Page_Lower_Column_offset + start_y);   // 0x00 - 0x0F
  OLED_Send_Command(OLED_Set_Page_Higher_Column_offset + start_x);  // 0x10 - 0x1F
  for (int i = 0; i < length; i++) {
    OLED_Send_oneChar(data[i]);
  }
}

void OLED_Vertical_Scroll(uint8_t start_page, uint8_t end_page, uint8_t frame_frequency,
                          uint8_t vertical_scrolling_offset, uint8_t Up_Down, bool auto_function) {
  /*
start page and end page from 0 - 7
time interval between each scroll step in terms of frame frequency:
                  0 - 5 frames,  1 - 64 frames,  2 - 128 frames,  3 - 256 frames,
                  4 - 3 frames,  5 - 4 frames,  6 - 25 frames,  7 - 2 frames,
                  lower the faster
vertical_scrolling_offset 0 - 3F --> 0 to 63 rows
*/
  OLED_Send_Command(OLED_Activate_Scroll);
  OLED_Send_Command(Up_Down); // OLED_Vertical_Up_Scroll / OLED_Vertical_Down_Scroll

  if (end_page <= start_page) {
    end_page = start_page;
  }
  OLED_Send_Command(0x00); // A[7:0], Dummpy byte
  OLED_Send_Command(start_page & 0x07);
  OLED_Send_Command(frame_frequency & 0x07);
  OLED_Send_Command(end_page & 0x07);
  OLED_Send_Command(vertical_scrolling_offset); // Dummy Byte

  if (auto_function == true) {
    /// do nothing
  } else {
    OLED_Send_Command(OLED_Deactivate_Scroll);
  }
}

static int time_consume = 0;
void OLED_Horizontal_Scroll(uint8_t start_page, uint8_t end_page, uint8_t frame_frequency, uint8_t Right_Left,
                            bool auto_function) {
  /*
   start page and end page from 0 - 7
   time interval between each scroll step in terms of frame frequency:
                    0 - 5 frames,  1 - 64 frames,  2 - 128 frames,  3 - 256 frames,
                    4 - 3 frames,  5 - 4 frames,  6 - 25 frames,  7 - 2 frames,
                    lower the faster
  */
  OLED_Send_Command(OLED_Activate_Scroll);
  OLED_Send_Command(Right_Left);

  if (end_page <= start_page) {
    end_page = start_page;
  }
  OLED_Send_Command(0x00); // A[7:0], Dummpy byte
  OLED_Send_Command(start_page & 0x07);
  OLED_Send_Command(frame_frequency & 0x07);
  OLED_Send_Command(end_page & 0x07);
  OLED_Send_Command(0x00); // Dummy Byte
  OLED_Send_Command(0xFF); // Dummy Byte

  if (auto_function == true) {
    /// do nothing
  } else {
    while (1) {
      if (time_consume > 29) {
        OLED_Send_Command(OLED_Deactivate_Scroll);
        break;
      } else {
        time_consume++;
        delay__ms(100);
      }
    }
    time_consume = 0;
  }
}

/***********************************************************************************
 *                      SD card file scanning                                      *
 *                                                                                 *
 * ********************************************************************************/

const char *song_list_get_name_for_item(uint8_t item_number) {
  const char *return_pointer = "";
  if (item_number >= number_of_songs) {
    return_pointer = "";
  } else {
    return_pointer = list_of_songs[item_number].song_name;
  }
  return return_pointer;
}

uint8_t get_song_list_item_count() { return number_of_songs; }

// void initlize_SD_Music_file_dir() {} // create a music folder if it doesnt exist

static void remove_suffix_of_filename(char *filename, int starting_index) {
  for (int i = starting_index; i < sizeof(song_memory_t); i++) {
    filename[i] = '\0';
  }
}
static void song_list_handle_filename(const char *filename, uint32_t file_size) {
  int dot_index = 0;
  while (filename[dot_index] != '.') {
    dot_index++;
  }
  // OLED__DEBUG_PRINTF("get . at %i\n", dot_index);
  // OLED__DEBUG_PRINTF("File size %u KB\n", file_size / 1024);
  // OLED__DEBUG_PRINTF("Unknown File name: %s\n", filename);
  // "/music"
  if (NULL != strstr(filename, ".mp3")) {
    remove_suffix_of_filename(filename, dot_index);
    strncpy(list_of_songs[number_of_songs].song_name, filename, sizeof(song_memory_t) - 1);

    list_of_songs[number_of_songs].song_type = _MP3;
    list_of_songs[number_of_songs].song_size = file_size / 1024;
    number_of_songs++;
  } else if (NULL != strstr(filename, ".WAV")) {
    remove_suffix_of_filename(filename, dot_index);
    strncpy(list_of_songs[number_of_songs].song_name, filename, sizeof(song_memory_t) - 1);
    list_of_songs[number_of_songs].song_type = _WAV;
    list_of_songs[number_of_songs].song_size = file_size / 1024;
    number_of_songs++;
  } else if (NULL != strstr(filename, ".flac")) {
    remove_suffix_of_filename(filename, dot_index);
    strncpy(list_of_songs[number_of_songs].song_name, filename, sizeof(song_memory_t) - 1);
    list_of_songs[number_of_songs].song_type = _FLAC;
    list_of_songs[number_of_songs].song_size = file_size / 1024;
    number_of_songs++;
  } else {
    remove_suffix_of_filename(filename, dot_index);
    strncpy(list_of_songs[number_of_songs].song_name, filename, sizeof(song_memory_t) - 1);
    list_of_songs[number_of_songs].song_type = _Unknown;
    list_of_songs[number_of_songs].song_size = file_size / 1024;
    number_of_songs++;
  }
}

void Read_SD_Music_file() {
  char path[256];
  FRESULT res;
  DIR dir;
  UINT i;
  static FILINFO f_info;
  char *defalut_dir = "/music";
  strncpy(path, defalut_dir, sizeof(path) - 1);
  res = f_opendir(&dir, path);
  if (res == FR_OK) {
    while (1) {
      res = f_readdir(&dir, &f_info);
      if (res != FR_OK || f_info.fname[0] == 0)
        break;
      if (f_info.fattrib & AM_DIR) {
        i = strlen(path);
        song_list_handle_filename(f_info.fname, f_info.fsize);
        path[i] = 0;
      } else {
        song_list_handle_filename(f_info.fname, f_info.fsize);
      }
    }
    f_closedir(&dir);
  }

  // print song name for checking
  for (int ind = 0; ind < get_song_list_item_count(); ind++) {
    OLED__DEBUG_PRINTF("/%s\n", list_of_songs[ind].song_name);
  }
}

/**********************************************************************
                         G U I
**********************************************************************/

void OLED_GUI_Home_Page(uint8_t position, bool playing_status) {
  /**********************************
   *         __   __
   *       | 00 | 01 |
   *         __   __
   *       | 10 | 11 |
   *         --   --
   ********************************/
  OLED_print_string(0, 0, 0, "--Suny Walkman--", 16);
  // OLED_print_string(1, 0, 0, "Limited  Edition", 16);
  // Print Layout
  switch (position) {
  case 0:
    OLED_print_string(3, 0, 0, "|RecPlay|Folder ", 16);
    OLED_print_string(4, 0, 0, " ---*---        ", 16);
    OLED_print_string(5, 0, 0, " ACC_M   Sleep  ", 16);
    OLED_print_string(6, 0, 0, "                ", 16);

    break;
  case 1:
    OLED_print_string(3, 0, 0, " RecPlay|Folder|", 16);
    OLED_print_string(4, 0, 0, "         ---*---", 16);
    OLED_print_string(5, 0, 0, " ACC_M   Sleep  ", 16);
    OLED_print_string(6, 0, 0, "                ", 16);
    break;

  case 2:
    OLED_print_string(3, 0, 0, " RecPlay Folder ", 16);
    OLED_print_string(4, 0, 0, "                ", 16);
    OLED_print_string(5, 0, 0, "|ACC_M  |Sleep  ", 16);
    OLED_print_string(6, 0, 0, " ---*---        ", 16);
    break;

  case 3:
    OLED_print_string(3, 0, 0, " RecPlay Folder ", 16);
    OLED_print_string(4, 0, 0, "                ", 16);
    OLED_print_string(5, 0, 0, " ACC_M  |Sleep |", 16);
    OLED_print_string(6, 0, 0, "         ---*---", 16);
    break;

  default:
    OLED_print_string(3, 0, 0, "|RecPlay|Folder ", 16);
    OLED_print_string(4, 0, 0, " ---*---        ", 16);
    OLED_print_string(5, 0, 0, " ACC_M   Sleep  ", 16);
    OLED_print_string(6, 0, 0, "                ", 16);
    break;
  }

  if (playing_status) {
    OLED_print_string(7, 0, 0, "Playing Now     ", 16);
    OLED_Horizontal_Scroll(7, 7, 7, OLED_Left_Horizontal_Scroll, 1);
  } else {
    OLED_print_string(7, 0, 0, "No Song to Play!", 16);
  }
  // OLED_Horizontal_Scroll(0, 0, 7, OLED_Left_Horizontal_Scroll, 1);
  delay__ms(50); // set sensitive level
}

void OLED_init() {
  OLED_RST();
  // OLED_Send_Command(OLED_Display_OFF_Sleep_Mode);

  OLED_Send_Command(OLED_Set_Multiplex_Ratio);
  OLED_Send_Command(0x3F);

  OLED_Send_Command(OLED_Set_Display_Offset);
  OLED_Send_Command(0x00);

  OLED_Send_Command(OLED_Set_Display_Start_Line); // Display Starting Line 40-7F

  OLED_Send_Command(OLED_Set_Segment_Remap);

  OLED_Send_Command(0xC8); // Set COM output

  OLED_Send_Command(0xDA); // Set COM Pins Hardware Configuration
  OLED_Send_Command(0x12); // 0x12

  OLED_Send_Command(OLED_Set_Contrast);
  OLED_Send_Command(0x7F);

  OLED_Send_Command(OLED_Display_ALL_ON_Resume);

  OLED_Send_Command(OLED_Display_Normal);

  OLED_Send_Command(0xD5); // Display Clock Divide Ratio / Oscillator Frequency
  OLED_Send_Command(0x10); // set CLK Fre, 0xF0 maximum frequency

  OLED_Send_Command(0x8D); // charge pump setting
  OLED_Send_Command(0x14);

  OLED_CLR_Screen();

  // reset all variable value
  // For GUI
  Button_Status = 0;
  OLED_GUI_Next_Pos = 0;
  OLED_GUI_Play_Status = false;
  play_first_song = false;
  ACC_CTL_MODE = false;

  strncpy(Current_play_song_name, "                ", 15);
  Current_song_total_size = 1;
  Current_song_sent_size = 0;

  Current_play_volumn = 5;

  number_of_songs = 0;
  Arrow_index = 0;
  Current_Arrow_index = 1;
  Get_new_song_play = false;
  Bass_status = false;
  Treble_status = false;
  Option_arrow_index = 1;
  Treble_Amplitude_index = 8;
  Treble_Frequency_index = 2;
  Bass_Amplitude_index = 2;
  Bass_Frequency_index = 2;

  task_handle__player = xTaskGetHandle("song_player");
  OLED_print_string(0, 0, 0, "--Suny Walkman--", 16);
  OLED_GUI_Home_Page(0, OLED_GUI_Play_Status);

  OLED_Send_Command(OLED_Display_ON_Normal_Mode);

  dec_set_VOLUME_(Current_play_volumn);
  delay__ms(101);
  // wait for 100ms
  //   OLED__DEBUG_PRINTF("OLED Finished init\n");
}

uint8_t OLED_GUI_Read_Button_Status() {
  /*************************************************************
   * button_back:            0x01     read_button_up:    0x02
   * read_button_option :    0x04     read_button_left:  0x08
   * read_button_play_pause: 0x10     read_button_right: 0x20
   * read_button_down:       0x40
   *
   * **********************************************************/

  Button_Status = 0; // reset status value

  if (!read_button_left()) {
    Button_Status = status_read_button_left;
    OLED__DEBUG_PRINTF("Button Left\n");
  }

  else if (!read_button_play_pause()) {
    Button_Status = status_read_button_play_pause;
    OLED__DEBUG_PRINTF("Button play pause\n");

  }

  else if (!read_button_right()) {
    Button_Status = status_read_button_right;
    OLED__DEBUG_PRINTF("Button Right\n");

  }

  else if (!read_button_up()) {
    Button_Status = status_read_button_up;
    OLED__DEBUG_PRINTF("Button Up\n");

  }

  else if (!read_button_down()) {
    Button_Status = status_read_button_down;
    OLED__DEBUG_PRINTF("Button Down\n");

  }

  else if (!read_button_back()) {
    Button_Status = status_read_button_back;
    OLED__DEBUG_PRINTF("Button Back\n");

  }

  else if (!read_button_option()) {
    Button_Status = status_read_button_option;
    OLED__DEBUG_PRINTF("Button Option\n");
  }

  // For ACC CTL
  else if (!read_ACC_CTL_PIN() && ACC_CTL_MODE) {
    Button_Status = acc_interpret_input(Button_Status);

    // acceleration__axis_data_s id = acceleration__get_data();

    // if ((-400 < id.x < 400) && (id.y > 700) && (id.z < 800)) {
    //   Button_Status = status_read_button_up;
    //   OLED__DEBUG_PRINTF("ACC_Up\n");
    // }

    // else if ((-400 < id.x < 400) && (id.y < -800) && (id.z < 800)) {
    //   Button_Status = status_read_button_down;
    //   OLED__DEBUG_PRINTF("ACC_Down\n");
    // }

    // else if ((id.x < -800) && (-400 < id.y < 400) && (id.z < 800)) {
    //   Button_Status = status_read_button_left;
    //   OLED__DEBUG_PRINTF("ACC_Left\n");
    // }

    // else if ((id.x > 800) && (-400 < id.y < 400) && (id.z < 800)) {
    //   Button_Status = status_read_button_right;
    //   OLED__DEBUG_PRINTF("ACC_Right\n");
    // }

    // else if ((id.x < -400) && (id.y > 400) && (id.z < 800)) {
    //   Button_Status = status_read_button_back;
    //   OLED__DEBUG_PRINTF("ACC_Exit\n");
    // }

    // else if ((id.x > 400) && (id.y > 400) && (id.z < 800)) {
    //   Button_Status = status_read_button_option;
    //   OLED__DEBUG_PRINTF("ACC_Option\n");
    // }

    // else if ((id.x > 400) && (id.y < -400) && (id.z < 800)) {
    //   Button_Status = status_read_button_play_pause;
    //   OLED__DEBUG_PRINTF("ACC_Play\n");
    // }
    // delay__ms(100); // give time for less sentive
  }
  delay__ms(50);
  return Button_Status;
}

void OLED_GUI_Sleep_mode() {

  uint8_t status_read_in_sleep_mode = 0x00;
  OLED__DEBUG_PRINTF("Enter Sleep Mode\n");
  OLED_print_string(0, 0, 0, "---Sleep Mode---", 16);
  while (1) {
    status_read_in_sleep_mode = OLED_GUI_Read_Button_Status();
    if (status_read_in_sleep_mode == status_read_button_back) {
      // OLED_print_string(0, 0, 0, "--Suny Walkman--", 16);
      break;
    } else {

      for (int i = 0; i < 7; i++) {
        status_read_in_sleep_mode = OLED_GUI_Read_Button_Status();
        switch (i) {
        case 0:
          if (status_read_in_sleep_mode == status_read_button_back) { break; }
          OLED_print_string(6, 1, 0, "     *", 6);
          OLED_print_string(7, 1, 0, " ^^^^^^^^^^", 11);
          break;

        case 1:
          if (status_read_in_sleep_mode == status_read_button_back) { break; }
          OLED_print_string(5, 1, 0, "     *", 6);
          OLED_print_string(6, 1, 0, "     |", 6);
          break;

        case 2:
          if (status_read_in_sleep_mode == status_read_button_back) { break; }
          OLED_print_string(5, 1, 0, "    (*)", 7);
          break;

        case 3:
          if (status_read_in_sleep_mode == status_read_button_back) { break; }
          OLED_print_string(4, 1, 0, "    ^^^", 7);
          OLED_print_string(5, 1, 0, "   <(*)>", 8);
          break;

        case 4:
          if (status_read_in_sleep_mode == status_read_button_back) { break; }
          OLED_print_string(3, 1, 0, "     ^", 6);
          break;

        case 5:
          if (status_read_in_sleep_mode == status_read_button_back) { break; }
          OLED_print_string(5, 1, 0, "  Supreme", 9);
          break;

        case 6:
          if (status_read_in_sleep_mode == status_read_button_back) { break; }
          OLED_print_string(3, 1, 0, "       ", 7);
          OLED_print_string(4, 1, 0, "        ", 8);
          OLED_print_string(5, 1, 0, "         ", 9);
          OLED_print_string(6, 1, 0, "      ", 6);
          OLED_print_string(7, 1, 0, " ^^^^^^^^^^", 11);
          break;
        }
        OLED_Horizontal_Scroll(0, 0, 7, OLED_Left_Horizontal_Scroll, 0);
      }
    }
  }
  OLED__DEBUG_PRINTF("Exit Sleep Mode\n");
}

void OLED_Get_sent_song_update(uint32_t data_size) {
  Current_song_sent_size += data_size;
  // OLED__DEBUG_PRINTF("sent update after add: %u\n", Current_song_sent_size);
}

void OLED_print_updated_volumn() {
  // print volumn page
  OLED__DEBUG_PRINTF("Updata Vol\n");
  char volume[16] = "Vol:            ";
  char temp[3] = "";
  itoa(Current_play_volumn, temp, 10);
  for (int i = 4; i < Current_play_volumn + 4; i++) {
    volume[i] = '-';
  }
  int j = 0;
  for (int i = 13; i < 16; i++) {
    volume[i] = temp[j];
    j++;
  }
  OLED_print_string(4, 0, 0, volume, 16);
  delay__ms(100); //////// need to change to LPC->time to calculate
  OLED_print_string(4, 0, 0, "                ", 16);
}

void OLED_GUI_play_status_and_source(bool playing_status) {

  if (playing_status) {
    OLED_print_string(7, 0, 0, "Playing Now     ", 16);
    OLED_Send_Command(OLED_Activate_Scroll);
    OLED__DEBUG_PRINTF("Active scroll\n");
    OLED_Horizontal_Scroll(7, 7, 7, OLED_Left_Horizontal_Scroll, 1);
  } else {
    OLED_Send_Command(OLED_Deactivate_Scroll);
    OLED__DEBUG_PRINTF("DeActive scroll\n");
    OLED_print_string(7, 0, 0, "No Song to Play!", 16);
  }
}

void OLED_GUI_Now_prograss_bar() {
  /****************************************
   *      percen trange:0-10              *
   *  Use page 6 to print prograss
   * **************************************/
  int percent = 0;
  float temp1 = Current_song_sent_size;
  float temp2 = Current_song_total_size;
  float res = (temp1 / temp2) * 10;
  percent = res;

  // OLED_update_progress();
  OLED__DEBUG_PRINTF("percent: %i0%\n", percent);

  switch (percent) {
  case 0:
    OLED_print_string(6, 0, 0, "0%              ", 16);
    break;
  case 1:
    OLED_print_string(6, 0, 0, "-10%", 4);
    break;
  case 2:
    OLED_print_string(6, 0, 0, "--20%", 5);
    break;
  case 3:
    OLED_print_string(6, 0, 0, "---30%", 6);
    break;
  case 4:
    OLED_print_string(6, 0, 0, "----40%", 7);
    break;
  case 5:
    OLED_print_string(6, 0, 0, "-----50%", 8);
    break;
  case 6:
    OLED_print_string(6, 0, 0, "------60%", 9);
    break;
  case 7:
    OLED_print_string(6, 0, 0, "-------70%", 10);
    break;
  case 8:
    OLED_print_string(6, 0, 0, "--------80%", 11);
    break;
  case 9:
    OLED_print_string(6, 0, 0, "---------90%", 12);
    break;
  case 10:
    OLED_print_string(6, 0, 0, "----------100%", 13);
    break;

  default:
    break;
  }
  // delay__ms(50);
}

void OLED_GUI_Send_New_Song() {
  song_name_t final_song_name = "music/";
  strcat(final_song_name, list_of_songs[Arrow_index].song_name);
  strcat(final_song_name, ".mp3");

  OLED__DEBUG_PRINTF("Get song:%s\n", final_song_name);
  Current_song_sent_size = 0;
  Current_song_total_size = list_of_songs[Arrow_index].song_size * 1024;
  OLED__DEBUG_PRINTF("Update total size from new song: %u\n", Current_song_total_size);

  xQueueSend(queue_song_name, final_song_name, portMAX_DELAY);
}

void OLED_GUI_NowPlay_Page(uint8_t position) {
  /**********************************
   * 0    --Now  Playing--
   * 1
   * 2      Music Name
   * 3  Previous  Play/Pause   Next
   * 4  |<<     ~>/||       >>|
   * 5  Vol:---               3
   * 6  ---30%
   * 7  Play song Status, sources
   ********************************/
  // Current_play_song_name = "rain.mp3       ";
  // char name[16] = "";
  // OLED__DEBUG_PRINTF("recent song play: %s\n", list_of_songs[Arrow_index]);
  OLED_print_string(0, 0, 0, "--Now  Playing--", 16);
  strncpy(Current_play_song_name, list_of_songs[Arrow_index].song_name, 16);
  OLED_print_string(2, 0, 0, Current_play_song_name, 16);
  // Print Layout
  switch (position) {
  case 0:
    OLED_print_string(4, 0, 0, "       |>       ", 16);

    break;
  case 1:
    OLED_print_string(4, 0, 0, "       ||       ", 16);
    break;

  case 2:
    OLED_print_string(4, 0, 0, "|<<             ", 16);
    break;

  case 3:
    OLED_print_string(4, 0, 0, "             >>|", 16);
    break;

  default:
    OLED_print_string(4, 0, 0, "                ", 16);
    break;
  }

  delay__ms(100);
}

void reverse(char *str, int len) {
  int i = 0, j = len - 1, temp;
  while (i < j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}

static int intToStr(int x, char str[], int d) {
  int i = 0;
  while (x) {
    str[i++] = (x % 10) + '0';
    x = x / 10;
  }
  while (i < d)
    str[i++] = '0';

  reverse(str, i);
  str[i] = '\0';
  return i;
}

// Converts a floating-point/double number to a string.
static void ftoa(float n, char *res, int afterpoint) {
  int ipart = (int)n;

  float fpart = n - (float)ipart;
  int i = intToStr(ipart, res, 0);
  if (afterpoint != 0) {
    res[i] = '.'; // add dot
    fpart = fpart * pow(10, afterpoint);

    intToStr((int)fpart, res + i + 1, afterpoint);
  }
}

void OLED_GUI_NowPlay_Option_Page(uint8_t up_down, uint8_t Left_Right) {
  /**********************************
   * 0     Playing Options
   * 1  TF+------------*
   * 2  TA------+------*
   * 3  BF+------------*
   * 4  BA+------------*
   * 5      Music Info.
   * 6  Format    MP3/WAV/FLAC
   * 7  Size      XXXMB
   ********************************/
  //  int Treble_Amplitude_index = 6;
  //  int Treble_Frequency_index = 0;
  //  int Bass_Amplitude_index = 0;
  //  int Bass_Frequency_index = 0;
  // Option_arrow_index : 0 - 3
  // Print Layout
  // OLED_print_string(0, 0, 0, " Playing Options", 16);
  if (Option_arrow_index == 0) {
    Option_arrow_index = 1;
  }
  int previous_index = Option_arrow_index;
  if (up_down == 1) { // go down
    Option_arrow_index++;
    OLED__DEBUG_PRINTF("INC\n");

    if (Option_arrow_index > 4) {
      Option_arrow_index = 1;
    }
  } else if (up_down == 0) { // go up
    Option_arrow_index--;
    OLED__DEBUG_PRINTF("DEC\n");

    if (Option_arrow_index < 1) {
      Option_arrow_index = 4;
    }
  }

  OLED__DEBUG_PRINTF("curr_opt arrow_ind %i\n", Option_arrow_index);

  // clear previous *
  switch (previous_index) {
  case 1:
    Treble_F[15] = ' ';
    break;

  case 2:
    Treble_A[15] = ' ';
    break;

  case 3:
    Bass_F[15] = ' ';
    break;

  case 4:
    Bass_A[15] = ' ';
    break;
  default:
    break;
  }

  // update * and +
  switch (Option_arrow_index) {
  case 1: // Treble F
    OLED__DEBUG_PRINTF("Enter Treble_F\n");

    Treble_F[15] = '*';
    switch (Left_Right) {
    case 0: // left
      Treble_Frequency_index--;
      if (Treble_Frequency_index < 2) {
        Treble_Frequency_index = 2;
      }
      Treble_F[Treble_Frequency_index] = '+';
      Treble_F[Treble_Frequency_index + 1] = '-';
      break;

    case 1: // right
      Treble_Frequency_index++;
      if (Treble_Frequency_index > 14) {
        Treble_Frequency_index = 14;
      }
      Treble_F[Treble_Frequency_index] = '+';
      Treble_F[Treble_Frequency_index - 1] = '-';
      break;

    default: // no move
      break;
    }
    break;

  case 2: // Treble A
    Treble_A[15] = '*';
    OLED__DEBUG_PRINTF("Enter Treble_A\n");
    switch (Left_Right) {
    case 0: // left
      Treble_Amplitude_index--;
      if (Treble_Amplitude_index < 2) {
        Treble_Amplitude_index = 2;
      }
      Treble_A[Treble_Amplitude_index] = '+';
      Treble_A[Treble_Amplitude_index + 1] = '-';
      break;

    case 1: // right
      Treble_Amplitude_index++;
      if (Treble_Amplitude_index > 14) {
        Treble_Amplitude_index = 14;
      }
      Treble_A[Treble_Amplitude_index] = '+';
      Treble_A[Treble_Amplitude_index - 1] = '-';
      break;

    default: // no move
      break;
    }
    break;

  case 3: // Bass F
    OLED__DEBUG_PRINTF("Enter Basss_F\n");

    Bass_F[15] = '*';
    switch (Left_Right) {
    case 0: // left
      Bass_Frequency_index--;
      if (Bass_Frequency_index < 2) {
        Bass_Frequency_index = 2;
      }
      Bass_F[Bass_Frequency_index] = '+';
      Bass_F[Bass_Frequency_index + 1] = '-';
      break;

    case 1: // right
      Bass_Frequency_index++;
      if (Bass_Frequency_index > 14) {
        Bass_Frequency_index = 14;
      }
      Bass_F[Bass_Frequency_index] = '+';
      Bass_F[Bass_Frequency_index - 1] = '-';
      break;

    default: // no move
      break;
    }
    break;

  case 4: // Bass A
    OLED__DEBUG_PRINTF("Enter Bass_A\n");

    Bass_A[15] = '*';
    switch (Left_Right) {
    case 0: // left
      Bass_Amplitude_index--;
      if (Bass_Amplitude_index < 2) {
        Bass_Amplitude_index = 2;
      }
      Bass_A[Bass_Amplitude_index] = '+';
      Bass_A[Bass_Amplitude_index + 1] = '-';
      break;

    case 1: // right
      Bass_Amplitude_index++;
      if (Bass_Amplitude_index > 14) {
        Bass_Amplitude_index = 14;
      }
      Bass_A[Bass_Amplitude_index] = '+';
      Bass_A[Bass_Amplitude_index - 1] = '-';
      break;

    default: // no move
      break;
    }
    break;

  default:
    break;
  }
  dec_set_BASS_TREBLE(Treble_Amplitude_index, Treble_Frequency_index, Bass_Amplitude_index, Bass_Frequency_index);
  OLED__DEBUG_PRINTF("Update Treble/Bass\n");

  OLED_print_string(1, 0, 0, Treble_F, 16);
  OLED_print_string(2, 0, 0, Treble_A, 16);
  OLED_print_string(3, 0, 0, Bass_F, 16);
  OLED_print_string(4, 0, 0, Bass_A, 16);

  OLED_print_string(5, 0, 0, "   Music Info.  ", 16);

  char Format_MP3[16] = "Format:     MP3 ";
  char Format_WAV[16] = "Format:     WAV ";
  char Format_FLAC[16] = "Format:     FLAC";

  if (list_of_songs[Arrow_index].song_type == _MP3) {
    OLED_print_string(6, 0, 0, Format_MP3, 16);
  } else if (list_of_songs[Arrow_index].song_type == _WAV) {
    OLED_print_string(6, 0, 0, Format_WAV, 16);
  } else if (list_of_songs[Arrow_index].song_type == _FLAC) {
    OLED_print_string(6, 0, 0, Format_FLAC, 16);
  }
  char res[5];
  float size = list_of_songs[Arrow_index].song_size / 1024;
  ftoa(size, res, 2);

  char Print_size[16] = "Size:         MB";

  int j = 0;
  for (int i = 9; i <= 13; i++) {
    Print_size[i] = res[j];
    j++;
  }

  OLED_print_string(7, 0, 0, Print_size, 16);
  delay__ms(30);
}

void OLED_GUI_NowPlay_Option() {

  uint8_t status_read_in_Option = 0x00;
  OLED_print_string(0, 0, 0, " Playing Options", 16);
  OLED_print_string(1, 0, 0, "                ", 16);
  OLED_print_string(2, 0, 0, "                ", 16);
  OLED_print_string(3, 0, 0, "                ", 16);
  OLED_print_string(4, 0, 0, "                ", 16);
  OLED_print_string(5, 0, 0, "                ", 16);
  OLED_print_string(6, 0, 0, "                ", 16);

  dec_set_BASS_TREBLE(Treble_Amplitude_index, Treble_Frequency_index, Bass_Amplitude_index, Bass_Frequency_index);

  enum {
    Up = 0,
    Down = 1,
    Left = 0,
    Right = 1,
    Up_Down_No_move = 2,
    Left_Rights_No_move = 2,
  };
  OLED__DEBUG_PRINTF("Enter Options\n");
  OLED_GUI_NowPlay_Option_Page(Up_Down_No_move, Left_Rights_No_move);

  delay__ms(100); // give delay for input to avoid Accidental touch
  while (1) {
    status_read_in_Option = OLED_GUI_Read_Button_Status();
    if (status_read_in_Option == status_read_button_back) {
      OLED_print_string(0, 0, 0, "--Now  Playing--", 16);
      OLED_print_string(2, 0, 0, "                ", 16);
      OLED_print_string(3, 0, 0, "                ", 16);
      break;
    } else {
      switch (status_read_in_Option) // make decision of the next move
      {
      case status_read_button_back: // back
        OLED__DEBUG_PRINTF("back to previous page\n");
        break;

      case status_read_button_up: // up
        OLED_GUI_NowPlay_Option_Page(Up, Left_Rights_No_move);
        break;

      case status_read_button_option: // option
        OLED__DEBUG_PRINTF("Do nothing\n");
        break;

      case status_read_button_left: // left
        OLED_GUI_NowPlay_Option_Page(Up_Down_No_move, Left);
        break;

      case status_read_button_play_pause: // play/pause
        OLED__DEBUG_PRINTF("Update display\n");
        if (Option_arrow_index == 0) {
          Bass_status = !Bass_status;
        } else if (Option_arrow_index == 1) {
          Treble_status = !Treble_status;
        }
        OLED_GUI_NowPlay_Option_Page(Up_Down_No_move, Left_Rights_No_move);
        break;

      case status_read_button_right: // right
        OLED_GUI_NowPlay_Option_Page(Up_Down_No_move, Right);
        break;

      case status_read_button_down: // down
        OLED_GUI_NowPlay_Option_Page(Down, Left_Rights_No_move);
        break;

      default: // button_press return val is 0x00
        // OLED_GUI_NowPlay_Option_Page(Up_Down_No_move, Left_Rights_No_move);
        // OLED__DEBUG_PRINTF("Do nothing\n");
        break;
      }
    }
    delay__ms(50); // give time to send the mp3 data if needed
  }

  Option_arrow_index = 1;
  Treble_Amplitude_index = 8;
  Treble_Frequency_index = 2;
  Bass_Amplitude_index = 2;
  Bass_Frequency_index = 2;

  strcpy(Treble_F, "TF+------------ ");
  strcpy(Treble_A, "TA------+------ ");
  strcpy(Bass_F, "BF+------------ ");
  strcpy(Bass_A, "BA+------------ ");

  OLED__DEBUG_PRINTF("Exit Option Page\n");
  // OLED_print_string(1, 0, 0, "                ", 16); // clear the line 1
}

void OLED_GUI_NowPlay() {
  uint8_t status_read_in_RecPlay = 0x00;
  int counter = 0;
  OLED_print_string(0, 0, 0, "--Now  Playing--", 16);
  OLED_print_string(1, 0, 0, "                ", 16);
  OLED_print_string(2, 0, 0, "                ", 16);
  OLED_print_string(3, 0, 0, "                ", 16);
  OLED_print_string(4, 0, 0, "                ", 16);
  OLED_print_string(5, 0, 0, "                ", 16);
  OLED_print_string(6, 0, 0, "                ", 16);

  OLED_GUI_Now_prograss_bar();
  OLED_GUI_NowPlay_Page(4);
  OLED_GUI_play_status_and_source(OLED_GUI_Play_Status);

  enum {
    play_next = 0,
    play_previous = 1,
  };
  delay__ms(50); // give time for avoiding accidential click
  OLED__DEBUG_PRINTF("Enter RecPlay Mode\n");
  while (1) {
    status_read_in_RecPlay = OLED_GUI_Read_Button_Status();
    if (status_read_in_RecPlay == status_read_button_back) {
      OLED_print_string(2, 0, 0, "                ", 16); // clear the line 2
      break;
    } else {
      switch (status_read_in_RecPlay) // make decision of the next move
      {
      case status_read_button_back: // back
        OLED_GUI_NowPlay_Page(4);   // default page
        OLED_GUI_play_status_and_source(OLED_GUI_Play_Status);
        OLED__DEBUG_PRINTF("back to previous page\n");
        break;

      case status_read_button_up: // up
        Current_play_volumn++;
        if (Current_play_volumn > 10) {
          Current_play_volumn = 10;
        }
        dec_set_VOLUME_(Current_play_volumn);

        OLED_print_updated_volumn();
        OLED_GUI_NowPlay_Page(4);

        OLED_GUI_Now_prograss_bar();
        OLED_GUI_play_status_and_source(OLED_GUI_Play_Status);

        // need to send volumn up command to decoder
        break;

      case status_read_button_option:           // option
        OLED__DEBUG_PRINTF("to option page\n"); // might go to the bass page
        OLED_GUI_NowPlay_Option();
        OLED_GUI_NowPlay_Page(6); // default page
        strncpy(Current_play_song_name, list_of_songs[Arrow_index].song_name, 16);
        OLED_print_string(1, 0, 0, "                ", 16);
        OLED_print_string(2, 0, 0, Current_play_song_name, 16);
        OLED_print_string(3, 0, 0, "                ", 16);
        OLED_print_string(4, 0, 0, "                ", 16);
        OLED_print_string(5, 0, 0, "                ", 16);
        OLED_print_string(6, 0, 0, "                ", 16);

        OLED_GUI_Now_prograss_bar();
        OLED_GUI_play_status_and_source(OLED_GUI_Play_Status);

        Option_arrow_index = 0; // reset arrow starting point

        OLED_GUI_NowPlay_Page(4);
        OLED_GUI_play_status_and_source(OLED_GUI_Play_Status);

        break;

      case status_read_button_left: // left
        OLED_GUI_NowPlay_Page(2);   // previous
        OLED_GUI_play_left_right(play_previous);
        OLED_GUI_Send_New_Song();
        OLED_GUI_NowPlay_Page(4);

        OLED_GUI_Now_prograss_bar();
        OLED_GUI_play_status_and_source(OLED_GUI_Play_Status);

        break;

      case status_read_button_play_pause: // play/pause
        // flip play status
        OLED_GUI_Play_Status = !OLED_GUI_Play_Status;

        if (OLED_GUI_Play_Status) {
          OLED_GUI_NowPlay_Page(0); // play
          if (play_first_song == false) {
            OLED_GUI_Send_New_Song();
            play_first_song = true;
          } else {
            vTaskResume(task_handle__player);
            OLED__DEBUG_PRINTF("Music Resume\n");
          }

          OLED_GUI_NowPlay_Page(4);

          OLED_GUI_Now_prograss_bar();
          OLED_GUI_play_status_and_source(OLED_GUI_Play_Status);
        } else {
          OLED_GUI_NowPlay_Page(1); // pause
          OLED_GUI_NowPlay_Page(4);

          OLED_GUI_Now_prograss_bar();
          OLED_GUI_play_status_and_source(OLED_GUI_Play_Status);

          vTaskSuspend(task_handle__player);
          OLED__DEBUG_PRINTF("Music Pause!\n");
        }
        break;

      case status_read_button_right: // right
        OLED_GUI_NowPlay_Page(3);    // to top right
        OLED_GUI_play_left_right(play_next);
        OLED_GUI_Send_New_Song();
        OLED_GUI_NowPlay_Page(4);

        OLED_GUI_Now_prograss_bar();
        OLED_GUI_play_status_and_source(OLED_GUI_Play_Status);

        break;

      case status_read_button_down: // down
        Current_play_volumn--;
        if (Current_play_volumn < 0) {
          Current_play_volumn = 0;
        }
        dec_set_VOLUME_(Current_play_volumn);

        OLED_print_updated_volumn();
        OLED_GUI_NowPlay_Page(4);

        OLED_GUI_Now_prograss_bar();
        OLED_GUI_play_status_and_source(OLED_GUI_Play_Status);

        // need to send volumn down command to decoder
        break;

      default: // button_press return val is 0x00
        if (counter == 0) {
          counter++;
          if (Get_new_song_play) {
            OLED_GUI_Send_New_Song();
            OLED_GUI_Play_Status = true;
            Get_new_song_play = false;
          }
          OLED_GUI_NowPlay_Page(4);

          OLED_GUI_Now_prograss_bar();
          OLED_GUI_play_status_and_source(OLED_GUI_Play_Status);
        }

        break;
      }
    }
    // delay__ms(80); // give time to send the mp3 data if needed
  }
  OLED__DEBUG_PRINTF("Exit RecPlay Mode\n");
}

void OLED_GUI_Folder_Page(uint8_t inc_dec) {
  // in the future, the void might change to pointer that return the recent song play name
  // or might not need to return the song name, becasue we know the index of the song that
  // we need to play next
  /**********************************
   * 0     ----Folder----
   * 1 ^
   * 2 *  Music Name1     <--1
   * 3 *  Music Name2         2
   * 4 *  Music Name3           3
   * 5 *  Music Name4             4
   * 6 *  Music Name5               5
   * 7 v
   ********************************/
  // Current_play_song_name = "rain.mp3       ";
  // OLED_print_string(0, 0, 0, " ----Folder---- ", 16);
  char temp_name[16] = "                "; // used to format the input music name
  char arrow[3] = "<--";                   // copy from index 13 of the temp_name
  char page_number[16] = "          Page  ";
  char num = '-';

  int curr_page = Arrow_index / 5;
  int total_pages = (number_of_songs - 1) / 5;

  Current_Arrow_index = (Arrow_index + 1) - curr_page * 5;

  uint8_t determine_num_of_song_in_this_page = 0;

  if (inc_dec == 1) { // down
    Arrow_index++;
    Current_Arrow_index++;
    if (Arrow_index > 4) { // one one page
      if (total_pages == 0) {
        Arrow_index = 0;
        Current_Arrow_index = 1;
      } else { // page > 0, more than 1 page
        if (Arrow_index % 5 == 0) {
          curr_page = curr_page + 1;
          Current_Arrow_index = 1;
        }
        if (Arrow_index > number_of_songs - 1) {
          curr_page = 0;
          Arrow_index = 0;
          Current_Arrow_index = 1;
        }
      }
    }
  } else if (inc_dec == 0) { // up
    Arrow_index--;
    Current_Arrow_index--;
    if (Current_Arrow_index == 0) { // line number
      if (total_pages == 0) {
        Arrow_index = number_of_songs - 1;
        Current_Arrow_index = number_of_songs;
      } else {                     // more than 1 page
        curr_page = curr_page - 1; // go to previous page
        Current_Arrow_index = 5;
        if (curr_page < 0) {
          curr_page = total_pages; // go to the last page
          Arrow_index = number_of_songs - 1;
          Current_Arrow_index = 5;
        }
      }
    }
  }

  num = curr_page + 48;
  page_number[15] = num; // get page number

  determine_num_of_song_in_this_page = curr_page * 5 + 5;
  if (determine_num_of_song_in_this_page > number_of_songs) {
    determine_num_of_song_in_this_page = number_of_songs % 5;
  }
  OLED__DEBUG_PRINTF("page: %i, index_arr: %i, curr_arrow: %i\n", total_pages, Arrow_index, Current_Arrow_index);

  OLED_print_string(1, 0, 0, "^               ", 16);
  if (determine_num_of_song_in_this_page == 5) {
    for (int i = 2 + curr_page * 5; i < 2 + curr_page * 5 + determine_num_of_song_in_this_page; i++) {
      strncpy(temp_name, list_of_songs[i - 2].song_name, 16); // get song name

      if ((i - 1 - curr_page * 5) == Current_Arrow_index) {
        int j = 0;                      // for copying the arrow
        for (int k = 13; k < 16; k++) { // copying the arrow to the end of the song name
          temp_name[k] = arrow[j];
          j++;
        }
        OLED_print_string(i - curr_page * 5, 0, 0, temp_name, 16);
      } else {
        OLED_print_string(i - curr_page * 5, 0, 0, temp_name, 16);
      }
    }
  } else { // less than 5 songs in a page
    uint8_t oled_page_counter = 1;
    for (int i = 2 + curr_page * 5; i < 2 + curr_page * 5 + determine_num_of_song_in_this_page; i++) {
      strncpy(temp_name, list_of_songs[i - 2].song_name, 16); // get song name
      oled_page_counter++;
      if ((i - 1 - curr_page * 5) == Current_Arrow_index) {
        int j = 0;                      // for copying the arrow
        for (int k = 13; k < 16; k++) { // copying the arrow to the end of the song name
          temp_name[k] = arrow[j];
          j++;
        }
        OLED_print_string(i - curr_page * 5, 0, 0, temp_name, 16);
      } else {
        OLED_print_string(i - curr_page * 5, 0, 0, temp_name, 16);
      }
    }

    for (int i = oled_page_counter + 1; i < 7; i++) {
      OLED_print_string(i, 0, 0, "                ", 16);
    }
  }

  OLED_print_string(7, 0, 0, page_number, 16);
  delay__ms(80);
}

void OLED_GUI_Folder() {
  uint8_t status_read_in_Folder = 0x00;
  OLED_print_string(0, 0, 0, " ----Folder---- ", 16);
  OLED_print_string(1, 0, 0, "                ", 16);
  OLED_print_string(2, 0, 0, "                ", 16);
  OLED_print_string(3, 0, 0, "                ", 16);
  OLED_print_string(4, 0, 0, "                ", 16);
  OLED_print_string(5, 0, 0, "                ", 16);
  OLED_print_string(6, 0, 0, "                ", 16);
  enum {
    Inc_arrow = 1,
    Dec_arrow = 0,
    No_move = 2,
  };
  OLED__DEBUG_PRINTF("Enter Folder\n");
  OLED_GUI_Folder_Page(No_move);
  delay__ms(100);
  while (1) {
    status_read_in_Folder = OLED_GUI_Read_Button_Status();
    if (status_read_in_Folder == status_read_button_back) {
      // OLED_print_string(0, 0, 0, "--Suny Walkman--", 16);
      OLED_print_string(2, 0, 0, "                ", 16);
      OLED_print_string(3, 0, 0, "                ", 16);
      break;
    } else if (Get_new_song_play == true) {
      break;
    } else {

      switch (status_read_in_Folder) // make decision of the next move
      {
      case status_read_button_back: // back
        OLED__DEBUG_PRINTF("back to previous page\n");
        break;

      case status_read_button_up: // up
        OLED_GUI_Folder_Page(Dec_arrow);
        break;

      case status_read_button_option: // option
        OLED__DEBUG_PRINTF("Do nothing\n");
        break;

      case status_read_button_left: // left
        OLED__DEBUG_PRINTF("Do nothing\n");
        break;

      case status_read_button_play_pause: // play/pause
        OLED__DEBUG_PRINTF("Update recent song play\n");
        Get_new_song_play = true;
        break;

      case status_read_button_right: // right
        OLED__DEBUG_PRINTF("Do nothing\n");
        break;

      case status_read_button_down: // down
        OLED_GUI_Folder_Page(Inc_arrow);
        break;

      default: // button_press return val is 0x00
        // OLED_GUI_Folder_Page(No_move);
        // OLED__DEBUG_PRINTF("Do nothing\n");
        break;
      }
    }
  }
  OLED__DEBUG_PRINTF("Exit Folder Page\n");
  OLED_print_string(1, 0, 0, "                ", 16); // clear the line 1
}

void OLED_GUI_play_left_right(bool left_right) {
  if (left_right) { // play previous
    if (Arrow_index == 0) {
      Arrow_index = number_of_songs - 1;
    } else {
      Arrow_index--;
    }

  } else { // play next
    if (Arrow_index == number_of_songs - 1) {
      Arrow_index = 0;
    } else {
      Arrow_index++;
    }
  }
}

void OLED_ACC_CTL_Page(bool turn_on_off) {
  /**********************************
   * 0  ----ACC  CTL----
   * 1
   * 2    -Mode Status-
   * 3       ON/OFF
   * 4
   * 5     Have  Fun~
   * 6
   * 7
   ********************************/
  OLED_print_string(0, 0, 0, "----ACC  CTL----", 16);
  OLED_print_string(2, 0, 0, "  -Mode Status- ", 16);
  OLED_print_string(5, 0, 0, "    Have Fun~   ", 16);

  if (turn_on_off) {
    OLED_print_string(3, 0, 0, "       ON       ", 16);
    OLED_Horizontal_Scroll(5, 5, 7, OLED_Left_Horizontal_Scroll, 1);

  } else {
    OLED_print_string(3, 0, 0, "       OFF       ", 16);
  }
}
void OLED_ACC_CTL_MODE() {

  uint8_t status_read_in_ACC = 0x00;
  OLED_print_string(0, 0, 0, "----ACC  CTL----", 16);
  OLED_print_string(1, 0, 0, "                ", 16);
  OLED_print_string(3, 0, 0, "                ", 16);
  OLED_print_string(4, 0, 0, "                ", 16);
  OLED_print_string(6, 0, 0, "                ", 16);
  OLED_print_string(7, 0, 0, "                ", 16);
  OLED_ACC_CTL_Page(false);

  OLED__DEBUG_PRINTF("Enter ACC MODE\n");
  delay__ms(100); // give delay for input to avoid Accidental touch
  while (1) {
    status_read_in_ACC = OLED_GUI_Read_Button_Status();
    if (status_read_in_ACC == status_read_button_back) {
      break;
    } else {
      switch (status_read_in_ACC) // make decision of the next move
      {
      case status_read_button_play_pause: // play/pause
        ACC_CTL_MODE = !ACC_CTL_MODE;
        OLED_ACC_CTL_Page(ACC_CTL_MODE);
        delay__ms(100);
        OLED__DEBUG_PRINTF("Update Mode Status\n");
        break;

      default: // button_press return val is 0x00
        break;
      }
    }
  }
  OLED_print_string(2, 0, 0, "                ", 16);
  delay__ms(50); // give time to send the mp3 data if needed
}

bool Get_OLED_GUI_Play_Status() { return OLED_GUI_Play_Status; }
void Flip_Play_status() { OLED_GUI_Play_Status = !OLED_GUI_Play_Status; }

void OLED_GUI_Move_decision() {
  uint8_t button_next_move = OLED_GUI_Read_Button_Status();
  OLED__DEBUG_PRINTF("Next position: %d\n", OLED_GUI_Next_Pos);

  switch (OLED_GUI_Next_Pos) {
  case 0:                     // top left------------------------------>Recplay page
    switch (button_next_move) // make decision of the next move
    {
    case status_read_button_back: // back
      // OLED_print_string(0, 0, 0, "--Suny Walkman--", 16);
      OLED_GUI_Next_Pos = 0;
      OLED_GUI_Home_Page(OLED_GUI_Next_Pos, OLED_GUI_Play_Status);
      OLED__DEBUG_PRINTF("back to previous page\n");
      break;

    case status_read_button_up:                    // up
      OLED_GUI_Home_Page(2, OLED_GUI_Play_Status); // go to botton left
      OLED_GUI_Next_Pos = 2;
      break;

    case status_read_button_option: // option
      OLED__DEBUG_PRINTF("to option page\n");
      break;

    case status_read_button_left:                  // left
      OLED_GUI_Home_Page(3, OLED_GUI_Play_Status); // to button right
      OLED_GUI_Next_Pos = 3;
      break;

    case status_read_button_play_pause: // play/pause
      OLED_GUI_NowPlay();
      // resume the page
      // OLED_print_string(0, 0, 0, "--Suny Walkman--", 16);
      OLED_GUI_Home_Page(0, OLED_GUI_Play_Status);
      OLED_GUI_Next_Pos = 0;

      break;

    case status_read_button_right:                 // right
      OLED_GUI_Home_Page(1, OLED_GUI_Play_Status); // to top right
      OLED_GUI_Next_Pos = 1;
      break;

    case status_read_button_down:                  // down
      OLED_GUI_Home_Page(2, OLED_GUI_Play_Status); // go to botton left
      OLED_GUI_Next_Pos = 2;
      break;

    default: // button_press return val is 0x00
      // OLED_print_string(0, 0, 0, "--Suny Walkman--", 16);
      // OLED_GUI_Home_Page(OLED_GUI_Next_Pos, OLED_GUI_Play_Status);
      break;
    }
    break;

  case 1:                     // top right------------------------------>Folder page
    switch (button_next_move) // make decision of the next move
    {
    case status_read_button_back: // back
      OLED_GUI_Next_Pos = 0;
      OLED_GUI_Home_Page(OLED_GUI_Next_Pos, OLED_GUI_Play_Status);
      OLED__DEBUG_PRINTF("back to previous page\n");
      break;

    case status_read_button_up:                    // up
      OLED_GUI_Home_Page(3, OLED_GUI_Play_Status); // go to botton right
      OLED_GUI_Next_Pos = 3;
      break;

    case status_read_button_option: // option
      OLED__DEBUG_PRINTF("to option page\n");
      break;

    case status_read_button_left:                  // left
      OLED_GUI_Home_Page(0, OLED_GUI_Play_Status); // to top left
      OLED_GUI_Next_Pos = 0;
      break;

    case status_read_button_play_pause: // play/pause
      OLED_Send_Command(OLED_Deactivate_Scroll);
      OLED_GUI_Folder(); // go to floder page logic

      if (Get_new_song_play == true) {
        // OLED_GUI_Send_New_Song();
        OLED_GUI_Play_Status = true;
        OLED_GUI_NowPlay(); // enter now playing page
      }
      OLED_GUI_Home_Page(0, OLED_GUI_Play_Status); // to top left
      OLED_GUI_Next_Pos = 0;
      break;

    case status_read_button_right:                 // right
      OLED_GUI_Home_Page(2, OLED_GUI_Play_Status); // to button left
      OLED_GUI_Next_Pos = 2;
      break;

    case status_read_button_down:                  // down
      OLED_GUI_Home_Page(3, OLED_GUI_Play_Status); // go to botton right
      OLED_GUI_Next_Pos = 3;
      break;

    default: // button_press return val is 0x00
      // OLED_print_string(0, 0, 0, "--Suny Walkman--", 16);
      // OLED_GUI_Home_Page(OLED_GUI_Next_Pos, OLED_GUI_Play_Status);
      break;
    }
    break;

  case 2:                     // button left------------------------------>ACC CTL page
    switch (button_next_move) // make decision of the next move
    {
    case status_read_button_back: // back
      OLED_GUI_Next_Pos = 0;
      OLED_GUI_Home_Page(OLED_GUI_Next_Pos, OLED_GUI_Play_Status);
      OLED__DEBUG_PRINTF("back to previous page\n");
      break;

    case status_read_button_up:                    // up
      OLED_GUI_Home_Page(0, OLED_GUI_Play_Status); // go to top left
      OLED_GUI_Next_Pos = 0;
      break;

    case status_read_button_option: // option
      OLED__DEBUG_PRINTF("to option page\n");
      OLED_GUI_Next_Pos = 0;
      break;

    case status_read_button_left:                  // left
      OLED_GUI_Home_Page(1, OLED_GUI_Play_Status); // to top right
      OLED_GUI_Next_Pos = 1;
      break;

    case status_read_button_play_pause: // play/pause
      OLED_ACC_CTL_MODE();
      OLED_GUI_Home_Page(0, OLED_GUI_Play_Status); // to top left
      OLED_GUI_Next_Pos = 0;
      break;

    case status_read_button_right:                 // right
      OLED_GUI_Home_Page(3, OLED_GUI_Play_Status); // to button right
      OLED_GUI_Next_Pos = 3;
      break;

    case status_read_button_down:                  // down
      OLED_GUI_Home_Page(0, OLED_GUI_Play_Status); // go to top left
      OLED_GUI_Next_Pos = 0;
      break;

    default: // button_press return val is 0x00
      // OLED_print_string(0, 0, 0, "--Suny Walkman--", 16);
      // OLED_GUI_Home_Page(OLED_GUI_Next_Pos, OLED_GUI_Play_Status);
      break;
    }
    break;

  case 3:                     // button right------------------------------>Sleep mode page
    switch (button_next_move) // make decision of the next move
    {
    case status_read_button_back: // back
      OLED_GUI_Next_Pos = 0;
      OLED_GUI_Home_Page(OLED_GUI_Next_Pos, OLED_GUI_Play_Status);
      OLED__DEBUG_PRINTF("back to previous page\n");
      break;

    case status_read_button_up:                    // up
      OLED_GUI_Home_Page(1, OLED_GUI_Play_Status); // go to top right
      OLED_GUI_Next_Pos = 1;
      break;

    case status_read_button_option: // option
      OLED__DEBUG_PRINTF("to option page\n");
      break;

    case status_read_button_left:                  // left
      OLED_GUI_Home_Page(2, OLED_GUI_Play_Status); // to button left
      OLED_GUI_Next_Pos = 2;
      break;

    case status_read_button_play_pause: // play/pause
      vTaskSuspend(task_handle__player);
      OLED_print_string(1, 0, 0, "                ", 16);
      OLED_print_string(2, 0, 0, "                ", 16);
      OLED_print_string(3, 0, 0, "                ", 16);
      OLED_print_string(4, 0, 0, "                ", 16);
      OLED_print_string(5, 0, 0, "                ", 16);
      OLED_print_string(6, 0, 0, "                ", 16);
      OLED_print_string(7, 0, 0, "                ", 16);
      OLED_GUI_Sleep_mode();
      vTaskResume(task_handle__player);

      // resume the page
      // OLED_print_string(0, 0, 0, "--Suny Walkman--", 16);
      OLED_GUI_Home_Page(0, OLED_GUI_Play_Status); // to top left
      OLED_GUI_Next_Pos = 0;
      break;

    case status_read_button_right:                 // right
      OLED_GUI_Home_Page(0, OLED_GUI_Play_Status); // to top left
      OLED_GUI_Next_Pos = 0;
      break;

    case status_read_button_down:                  // down
      OLED_GUI_Home_Page(1, OLED_GUI_Play_Status); // go to top right
      OLED_GUI_Next_Pos = 1;
      break;

    default:
      // button_press return val is 0x00, the music will be paused if oled tasks is
      // higher priority than reader tasks
      // OLED_print_string(0, 0, 0, "--Suny Walkman--", 16);
      // OLED_GUI_Home_Page(OLED_GUI_Next_Pos, OLED_GUI_Play_Status);
      break;
    }
    break;

  default: // default of recent page position, but it should not enter here
    // OLED_print_string(0, 0, 0, "--Suny Walkman--", 16);
    // OLED_GUI_Home_Page(OLED_GUI_Next_Pos, OLED_GUI_Play_Status);
    break;
  }
}
