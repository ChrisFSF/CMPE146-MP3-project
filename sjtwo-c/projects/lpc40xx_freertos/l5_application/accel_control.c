#include "accel_control.h"
#include <stdbool.h>

#define OLED__ENABLE_DEBUGGING 0

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

uint8_t acc_interpret_input(uint8_t Button_Status) {
  acceleration__axis_data_s id = acceleration__get_data();
  bool is_X_stable = (-350 < id.x && id.x < 350);
  bool is_Y_stable = (-350 < id.y && id.y < 350);
  bool is_X_positive = (350 < id.x && id.x < 1050);
  bool is_X_negative = (-1050 < id.x && id.x < -350);
  bool is_Y_positive = (350 < id.y && id.y < 1050);
  bool is_Y_negative = (-1050 < id.y && id.y < -350);

  if (id.z < 950) {
    if (is_X_stable) {
      if (is_Y_positive) {
        Button_Status = status_read_button_up;
        OLED__DEBUG_PRINTF("ACC_Up\n");
      } else if (is_Y_negative) {
        Button_Status = status_read_button_down;
        OLED__DEBUG_PRINTF("ACC_Down\n");
      }
    } else if (is_Y_stable) {
      if (is_X_positive) {
        Button_Status = status_read_button_right;
        OLED__DEBUG_PRINTF("ACC_Right\n");
      } else if (is_X_negative) {
        Button_Status = status_read_button_left;
        OLED__DEBUG_PRINTF("ACC_Left\n");
      }
    } else if (is_Y_positive) {
      if (is_X_positive) {
        Button_Status = status_read_button_option;
        OLED__DEBUG_PRINTF("ACC_Option\n");
      } else if (is_X_negative) {
        Button_Status = status_read_button_back;
        OLED__DEBUG_PRINTF("ACC_Exit\n");
      }
    } else if (is_X_positive && is_Y_negative) {
      Button_Status = status_read_button_play_pause;
      OLED__DEBUG_PRINTF("ACC_Play\n");
    }
    delay__ms(100);
  }
  return Button_Status;
}