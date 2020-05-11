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
  if (id.z < 950){  // when tilted more than 30 degree, 1023 * cos(30) = 886
    if (3750 < id.x  || id.x < 350){ 
      if      (350 < id.y && id.y < 1000) { Button_Status = status_read_button_up;
                                            OLED__DEBUG_PRINTF("ACC_Up\n"); }
      else if (3100 < id.y && id.y < 3750){ Button_Status = status_read_button_down;
                                            OLED__DEBUG_PRINTF("ACC_Down\n"); }
    }
    else if (3750 < id.y || id.y < 350){
      if      (350 < id.x && id.x < 1000) { Button_Status = status_read_button_right;
                                            OLED__DEBUG_PRINTF("ACC_Right\n"); }
      else if (3100 < id.x && id.x < 3750){ Button_Status = status_read_button_left;
                                            OLED__DEBUG_PRINTF("ACC_Left\n"); }
    }
    else if (350 < id.y && id.y < 1000){
      if      (350 < id.x  && id.x < 1000){ Button_Status = status_read_button_option;
                                            OLED__DEBUG_PRINTF("ACC_Option\n"); }
      else if (3100 < id.x && id.x < 3750){ Button_Status = status_read_button_back;
                                            OLED__DEBUG_PRINTF("ACC_Exit\n"); }
    }
    else if (350 < id.x  && id.x < 1000 && 
             3100 < id.y && id.y < 3750)  { Button_Status = status_read_button_play_pause;
                                            OLED__DEBUG_PRINTF("ACC_Play\n"); }
  delay__ms(100);
  }
  return Button_Status;
}