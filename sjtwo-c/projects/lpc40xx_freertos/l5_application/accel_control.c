#include "accel_control.h"

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

uint8_t acc_interpret_input(uint8_t Button_Status){
  acceleration__axis_data_s id = acceleration__get_data();
  if (id.z < 800){
    if (-400 < id.x  && id.x < 400){
      if      (id.y > 700)  { Button_Status = status_read_button_up;
                              OLED__DEBUG_PRINTF("ACC_Up\n"); }
      else if (id.y < -800) { Button_Status = status_read_button_down;
                              OLED__DEBUG_PRINTF("ACC_Down\n"); }
    }
    else if (-400 < id.y && id.y < 400){
      if      (id.x < -800) { Button_Status = status_read_button_left;
                              OLED__DEBUG_PRINTF("ACC_Left\n"); }
      else if (id.x > 800)  { Button_Status = status_read_button_right;
                              OLED__DEBUG_PRINTF("ACC_Right\n"); }
    }
    else if ((400 < id.x ) && (400 < id.y )) {
      Button_Status = status_read_button_option;
      OLED__DEBUG_PRINTF("ACC_Option\n");
    }
    else if ((id.x < -400) && (400 < id.y)) {
      Button_Status = status_read_button_back;
      OLED__DEBUG_PRINTF("ACC_Exit\n");
    }
    else if ((400 < id.x ) && (id.y < -400)) {
      Button_Status = status_read_button_play_pause;
      OLED__DEBUG_PRINTF("ACC_Play\n");
    }
  delay__ms(100);
  }
  return Button_Status;
}

// uint8_t acc_interpret_input(){
//   uint8_t Button_Status;
//   acceleration__axis_data_s id = acceleration__get_data();

//   if ((-400 < id.x < 400) && (id.y > 700) && (id.z < 800)) {
//     Button_Status = status_read_button_up;
//   }

//   else if ((-400 < id.x < 400) && (id.y < -800) && (id.z < 800)) {
//     Button_Status = status_read_button_down;
//   }

//   else if ((id.x < -800) && (-400 < id.y < 400) && (id.z < 800)) {
//     Button_Status = status_read_button_left;
//   }

//   else if ((id.x > 800) && (-400 < id.y < 400) && (id.z < 800)) {
//     Button_Status = status_read_button_right;
//   }

//   else if ((id.x < -400) && (id.y > 400) && (id.z < 800)) {
//     Button_Status = status_read_button_back;
//   }

//   else if ((id.x > 400) && (id.y > 400) && (id.z < 800)) {
//     Button_Status = status_read_button_option;
//   }

//   else if ((id.x > 400) && (id.y < -400) && (id.z < 800)) {
//     Button_Status = status_read_button_play_pause;
//   }
//   delay__ms(100); // give time for less sentive

//   return Button_Status;
// }