#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FreeRTOS.h"
// #include "semphr.h"

#include "adc.h"
#include "cli_handlers.h" // for mp3 cli handler testing
#include "common_macros.h"
#include "delay.h"
#include "gpio.h"
#include "gpio_isr.h"
#include "gpio_lab.h"
#include "lpc40xx.h"
#include "lpc_peripherals.h"
#include "queue.h"
#include "sj2_cli.h"
#include "task.h"
#include "uart_printf.h"
// #include "event_groups.h"
#include "Control_Button.h"
#include "acceleration.h"
#include "audio_decoder.h"
#include "ff.h"
#include "oled_spi.h"
#include "ssp0.h"
#include "ssp1.h"
#include "ssp2_lab.h"
#include "uart_lab.h"

// scons --no-float-format -j4
// rain.mp3, good.mp3

#define OLED_TEST 1
#define DECODER_TEST 1
#define ACC_CTL_TEST 0
#if OLED_TEST // Oled code

// For Controling Buttons Test
// Use Interrupt to get the interrupt signal
static SemaphoreHandle_t Button_Pressed_Interrupt_Signal;
static SemaphoreHandle_t Give_time_for_OLED_print;
static SemaphoreHandle_t Song_play_pause_status;

void Control_Button_GPIO2_Interrupt(void) {
  xSemaphoreGiveFromISR(Give_time_for_OLED_print, NULL);
  xSemaphoreGiveFromISR(Button_Pressed_Interrupt_Signal, NULL);
}

void oled_print(void *p) {

  while (1) {
    if (xSemaphoreTake(Button_Pressed_Interrupt_Signal, 0)) {
      OLED_GUI_Move_decision();
    }
  }
}

#endif

app_cli_status_e cli__playsong(app_cli__argument_t argument, sl_string_t user_input_minus_command_name,
                               app_cli__print_string_function cli_output) {
  song_name_t song_name = {0};

  if (sl_string__get_length(user_input_minus_command_name) > sizeof(song_name)) {
    puts("User input song name too long");
  } else {
    // strcpy(song_name, user_input_minus_command_name);
    strncpy(song_name, user_input_minus_command_name, sizeof(song_name) - 1);
    printf("Sending input \"%s\" to queue\n", song_name);
    xQueueSend(queue_song_name, song_name, portMAX_DELAY);
  }

  return APP_CLI_STATUS__SUCCESS;
}

#if DECODER_TEST

void song_reader_task(void *p) {
  song_name_t song_name;
  song_data_block_t song_data_block;
  FIL file;
  UINT bytes_read;

  while (1) {
    if (xQueueReceive(queue_song_name, &song_name, portMAX_DELAY)) {
      // printf("\nReader received file name \"%s\" for playback\n", song_name);
      int res = f_open(&file, song_name, FA_READ);
      if (FR_OK == res) {
        bytes_read = 0;
        while (f_eof(&file) == 0) {

          f_read(&file, song_data_block, sizeof(song_data_block), &bytes_read);
          if (bytes_read == 0)
            break;
          xQueueSend(queue_song_data_block, song_data_block, portMAX_DELAY);
          f_read(&file, song_data_block, sizeof(song_data_block), &bytes_read);
          if (bytes_read == 0)
            break;
          xQueueSend(queue_song_data_block, song_data_block, portMAX_DELAY);

          if (xSemaphoreTake(Give_time_for_OLED_print, 1)) {
            // delay__us(800);
            delay__ms(1);
          }

          if (uxQueueMessagesWaiting(queue_song_name)) {
            // puts("New song request received");
            break;
          }
        }
        f_close(&file);
        // INC_Current_song_play_index();
        // // Play_next_song();
        // xSemaphoreGive(Button_Pressed_Interrupt_Signal);
        // OLED_GUI_Send_New_Song();

      } else {
        printf("ERROR: failed to open %s\n", song_name);
      }
    }
  }
}

void spi_send_song_byte(uint8_t byte) { printf("%X ", byte); }

void song_player_task(void *p) {
  song_data_block_t song_data_block;
  size_t spi_send_size = 32;

  while (1) {

    if (xQueueReceive(queue_song_data_block, &song_data_block, portMAX_DELAY)) {
      // if (xSemaphoreTake(OLED_Song_Reader_task_swtich, 100)) {
      // puts("\nPlayer task received song data block");
      uint32_t byte_sent_counter = 0;
      while (byte_sent_counter < sizeof(song_data_block)) {

        while (!decoder_needs_data()) {
          delay__ms(2);
        }
        dec_dcs();
        for (uint32_t byte = byte_sent_counter; byte < (byte_sent_counter + spi_send_size); byte++) {
          ssp1__exchange_byte_lab(song_data_block[byte]);

          // 32 loops * 1 byte
        }
        byte_sent_counter += spi_send_size;
        dec_dds();
      }
      OLED_Get_sent_song_update(byte_sent_counter);
      //   xSemaphoreGive(OLED_Song_Reader_task_swtich);
      // }
    }
  }
}

void task_spi_task(void *p) {
  dec_spi_4bytes_t id = {0x01, 0x02, 0x03, 0x04};
  vTaskDelay(1000);
  dec_init();

  for (uint8_t i = 0; i < 16; i++) {
    id = dec_write_read(0x03, i, 0x12, 0x34);
    // printf("dec_write: %x, %x, %x, %x\n", id.first_byte, id.second_byte, id.third_byte, id.forth_byte);
    vTaskDelay(1);
  }
  while (1) {
    vTaskDelay(portMAX_DELAY);
  }
}

#endif

#if ACC_CTL_TEST
void acc_task(void *p) {
  while (1) {
    acceleration__axis_data_s id = acceleration__get_data();
    printf("\nX = %d", id.x);
    printf("  Y = %d", id.y);
    printf("  Z = %d", id.z);

    if (id.z < 950) { // when tilted more than 30 degree, 1023 * cos(30) = 886
      if (-350 < id.x && id.x < 350) {
        if (350 < id.y && id.y < 1050) {
          printf("ACC_Up\n");
        } else if (-1050 < id.y && id.y < -350) {
          printf("ACC_Down\n");
        }
      } else if (-350 < id.y && id.y < 350) {
        if (350 < id.x && id.x < 1050) {
          printf("ACC_Right\n");
        } else if (-1050 < id.x && id.x < -350) {
          printf("ACC_Left\n");
        }
      } else if (350 < id.y && id.y < 1050) {
        if (350 < id.x && id.x < 1050) {
          printf("ACC_Option\n");
        } else if (-1050 < id.x && id.x < -350) {
          printf("ACC_Exit\n");
        }
      } else if (350 < id.x && id.x < 1050 && -1050 < id.y && id.y < -350) {
        printf("ACC_Play\n");
      }
    }
    vTaskDelay(100);
  }
}
#endif

// RTOS trace: Failed to write page

int main(void) {

#if ACC_CTL_TEST
  acceleration__init();
  xTaskCreate(acc_task, "task_spi_task", (2000 / sizeof(void *)), NULL, 5, NULL);

#endif

#if DECODER_TEST
  queue_song_name = xQueueCreate(1, sizeof(song_name_t));
  queue_song_data_block = xQueueCreate(2, sizeof(song_data_block_t));
  xSemaphore_mutex_spi = xSemaphoreCreateMutex();
  Song_play_pause_status = xSemaphoreCreateBinary();

  const uint32_t spi_clock_mhz = 1;
  ssp1__init_lab(spi_clock_mhz);

  xTaskCreate(song_reader_task, "song_reader", (2000 + sizeof(song_data_block_t)) / sizeof(void *), NULL, 2, NULL);
  xTaskCreate(song_player_task, "song_player", (2000 + sizeof(song_data_block_t)) / sizeof(void *), NULL, 3, NULL);
  xTaskCreate(task_spi_task, "task_spi_task", (2000 / sizeof(void *)), NULL, 5, NULL);
#endif

#if OLED_TEST // oled
              // for Control Button Setting
  Button_Pressed_Interrupt_Signal = xSemaphoreCreateBinary();
  Give_time_for_OLED_print = xSemaphoreCreateBinary();

  gpiox__attach_interrupt(get_button_val(0), GPIOx_INTR_FALLING_EDGE, Control_Button_GPIO2_Interrupt);
  gpiox__attach_interrupt(get_button_val(1), GPIOx_INTR_FALLING_EDGE, Control_Button_GPIO2_Interrupt);
  gpiox__attach_interrupt(get_button_val(2), GPIOx_INTR_FALLING_EDGE, Control_Button_GPIO2_Interrupt);
  gpiox__attach_interrupt(get_button_val(3), GPIOx_INTR_FALLING_EDGE, Control_Button_GPIO2_Interrupt);
  gpiox__attach_interrupt(get_button_val(4), GPIOx_INTR_FALLING_EDGE, Control_Button_GPIO2_Interrupt);
  gpiox__attach_interrupt(get_button_val(5), GPIOx_INTR_FALLING_EDGE, Control_Button_GPIO2_Interrupt);
  gpiox__attach_interrupt(get_button_val(6), GPIOx_INTR_FALLING_EDGE, Control_Button_GPIO2_Interrupt);
  gpiox__attach_interrupt(get_button_val(7), GPIOx_INTR_FALLING_EDGE, Control_Button_GPIO2_Interrupt);

  NVIC_EnableIRQ(GPIO_IRQn);
  lpc_peripheral__enable_interrupt(GPIO_IRQn, gpiox__interrupt_dispatcher, "Control Button Interrupt Check");

  // for Oled setting
  ssp0__init_lab(24);
  acceleration__init(); // for ACC CTL input
  OLED_init();
  Scan_SD_Music_file();

  xTaskCreate(oled_print, "oled_task", (512U * 8) / sizeof(void *), NULL, 2, NULL);
#endif

  // Q_songname = xQueueCreate(1, sizeof(songname_t));
  // Q_songdata = xQueueCreate(2, sizeof(songdata_t));
  // reset_decoder();
  // xTaskCreate(mp3_reader_task, "mp3_reader_task", (512U * 8 + sizeof(songdata_t)) / sizeof(void *), NULL,
  //             PRIORITY_MEDIUM, NULL);
  // xTaskCreate(mp3_player_task, "mp3_player_task", (512U * 8 + sizeof(songdata_t)) / sizeof(void *), NULL,
  // PRIORITY_HIGH,
  //             NULL);

  sj2_cli__init();
  puts("Starting RTOS");
  vTaskStartScheduler(); // This function never returns unless RTOS scheduler runs out of memory and fails
  return 0;
}
