#include "gpio_lab.h"
#include <stdbool.h>
#include <stdint.h>
/*****************************************************************************************************
 *                                          Oled_display                                              *
 *                                                                                                    *
 ******************************************************************************************************/

// D0 -> SPI_CLK, D1 -> SPI_MOSI, VCC 3.3 -5V
// 8 pages of address
// port_pin_s OLED_RST_pin = {0, 8};
// port_pin_s OLED_DC_pin = {0, 26}; // choose data or command line
// port_pin_s OLED_CS_pin = {0, 25};

void OLED_CS();
void OLED_DS();
void OLED_DC(bool cmd);
void OLED_RST();

void OLED_init();
void OLED_Send_Data(uint8_t data);
void OLED_Send_Command(uint8_t cmd);

// useful function
void OLED_Power_Off();
void OLED_CLR_Screen();
void OLED_print_string(uint8_t page, uint8_t start_x, uint8_t start_y, uint8_t *data, int length);
void OLED_Send_oneChar(uint8_t data);

// Scrolling
void OLED_Vertical_Scroll(uint8_t start_page, uint8_t end_page, uint8_t frame_frequency,
                          uint8_t vertical_scrolling_offset, uint8_t Up0_Down1, bool auto_function);
void OLED_Horizontal_Scroll(uint8_t start_page, uint8_t end_page, uint8_t frame_frequency, uint8_t Right_Left,
                            bool auto_function);

// Fundamental Command Table
#define OLED_Set_Contrast 0x81
#define OLED_Display_ALL_ON_Resume 0xA4 // output follows RAM content
#define OLED_Display_ON 0xA5            // not used
#define OLED_Display_Normal 0xA6
#define OLED_Display_Inverse 0xA7
#define OLED_Display_OFF_Sleep_Mode 0xAE // display off
#define OLED_Display_ON_Normal_Mode 0xAF // turn on the display **IMPORTANT**

// Scrolling Command Table
#define OLED_Right_Horizontal_Scroll 0x26
#define OLED_Left_Horizontal_Scroll 0x27
#define OLED_Vertical_Up_Scroll 0x29
#define OLED_Vertical_Down_Scroll 0x2A

#define OLED_Deactivate_Scroll 0x2E
#define OLED_Activate_Scroll 0x2F
#define OLED_Set_Vertical_Scroll 0xA3

// Addressing Setting Command Table
#define OLED_Set_Mem_Addr_Mode 0x20
#define OLED_Set_Page_Start_Addr_for_Page_mode 0xB0 // B0 - B7
#define OLED_Set_Page_Lower_Column_offset 0x00      // 0x00 - 0x0F
#define OLED_Set_Page_Higher_Column_offset 0x10     // 0x10 - 0x1F

// Hardware Configuration Command Table
#define OLED_Set_Multiplex_Ratio 0xA8
#define OLED_Set_Display_Offset 0xD3
#define OLED_Set_Display_Start_Line 0x40 // 40 - 7F
#define OLED_Set_Segment_Remap 0xA1

// Timing & Driving Sceme Setting Command Table

/**********************************************************************
                         G U I
**********************************************************************/
// button control status
enum {
  status_read_button_back = 0x01,
  status_read_button_up = 0x02,
  status_read_button_option = 0x04,
  status_read_button_left = 0x08,
  status_read_button_play_pause = 0x10,
  status_read_button_right = 0x20,
  status_read_button_down = 0x40,
};

// Core Funtion
void OLED_GUI_Move_decision();

// Pages
void OLED_GUI_Home_Page(uint8_t position, bool playing_status);

// Recent play page
void OLED_GUI_NowPlay_Page(uint8_t position);
void OLED_GUI_NowPlay();
void OLED_GUI_play_status_and_source(bool playing_status);

void OLED_GUI_Now_prograss_bar();
void OLED_Get_sent_song_update(uint32_t data_size);

void OLED_print_updated_volumn();
void OLED_GUI_play_left_right(bool left_right);
bool Get_OLED_GUI_Play_Status();
void Flip_Play_status();

// option page for now playing
void OLED_GUI_NowPlay_Option_Page(uint8_t up_down, uint8_t Left_Right);
void OLED_GUI_NowPlay_Option();
void OLED_GUI_Send_New_Song();

// Folder page
void OLED_GUI_Folder_Page(uint8_t inc_dec);
void OLED_GUI_Folder();

// ACC ctl page
void OLED_ACC_CTL_Page(bool turn_on_off);
void OLED_ACC_CTL_MODE();

// Accelerator control mode
void OLED_GUI_Sleep_mode();
uint8_t OLED_GUI_Read_Button_Status();

/***********************************************************************************
 *                      SD card file scanning                                      *
 *                                                                                 *
 * ********************************************************************************/
// For Reading the SD card
// USE FOR SONG NAME

void Read_SD_Music_file();
uint8_t get_song_list_item_count();
const char *song_list_get_name_for_item(uint8_t item_number);