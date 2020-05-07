#include "Control_Button.h"
#include "gpio_lab.h"
#include "lpc40xx.h"

/*************************************************************************
 *
 *                  Control Buttons
 * Layout:
 *         Back          Up             Option
 *         Left        Play/Pause       Right
 *                       Down
 * ***********************************************************************/
// Use LPC_GPIOINT to check Interrupt
const port_pin_s Button_left_PIN = {2, 9};
const port_pin_s Btton_play_pause_PIN = {2, 8};
const port_pin_s Button_right_PIN = {2, 7};
const port_pin_s Button_up_PIN = {2, 6};
const port_pin_s Button_down_PIN = {2, 5};
const port_pin_s Button_back_PIN = {2, 4};
const port_pin_s Button_option_PIN = {2, 1};
const port_pin_s Read_ACC_CTL_PIN = {2, 2};

bool read_ACC_CTL_PIN() {
  gpiox__set_as_input(Read_ACC_CTL_PIN);
  return gpiox__get_level(Read_ACC_CTL_PIN);
}

bool read_button_left() {
  gpiox__set_as_input(Button_left_PIN);
  return gpiox__get_level(Button_left_PIN);
}

bool read_button_play_pause() {
  gpiox__set_as_input(Btton_play_pause_PIN);
  return gpiox__get_level(Btton_play_pause_PIN);
}

bool read_button_right() {
  gpiox__set_as_input(Button_right_PIN);
  return gpiox__get_level(Button_right_PIN);
}

bool read_button_up() {
  gpiox__set_as_input(Button_up_PIN);
  return gpiox__get_level(Button_up_PIN);
}

bool read_button_down() {
  gpiox__set_as_input(Button_down_PIN);
  return gpiox__get_level(Button_down_PIN);
}

bool read_button_back() {
  gpiox__set_as_input(Button_back_PIN);
  return gpiox__get_level(Button_back_PIN);
}

bool read_button_option() {
  gpiox__set_as_input(Button_option_PIN);
  return gpiox__get_level(Button_option_PIN);
}

port_pin_s get_button_val(uint8_t index) {
  switch (index) {
  case 0:
    return Button_back_PIN;
    break;

  case 1:
    return Button_up_PIN;
    break;

  case 2:
    return Button_option_PIN;
    break;

  case 3:
    return Button_left_PIN;
    break;
  case 4:
    return Btton_play_pause_PIN;
    break;

  case 5:
    return Button_right_PIN;
    break;

  case 6:
    return Button_down_PIN;
    break;

  case 7:
    return Read_ACC_CTL_PIN;

  default:
    return Button_back_PIN;
    break;
  }
  return Button_left_PIN;
}
