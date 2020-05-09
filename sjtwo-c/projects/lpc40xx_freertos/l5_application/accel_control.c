#include "accel_control.h"

uint8_t acc_interpret_input(uint8_t Button_Status){
  acceleration__axis_data_s id = acceleration__get_data();
  if (id.z < 800){
    if (-400 < id.x  && id.x < 400){
      if      (id.y > 700)  { Button_Status = status_read_button_up; }
      else if (id.y < -800) { Button_Status = status_read_button_down; }
    }
    else if (-400 < id.y && id.y < 400){
      if      (id.x < -800) { Button_Status = status_read_button_left; }
      else if (id.x > 800)  { Button_Status = status_read_button_right; }
    }
    else if ((400 < id.x ) && (400 < id.y )) {
      Button_Status = status_read_button_option;
    }
    else if ((id.x < -400) && (400 < id.y)) {
      Button_Status = status_read_button_back;
    }
    else if ((400 < id.x ) && (id.y < -400)) {
      Button_Status = status_read_button_play_pause;
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