#include "gpio_lab.h"
#include <stdbool.h>

port_pin_s get_button_val(uint8_t index);

bool read_button_left();
bool read_button_play_pause();
bool read_button_right();
bool read_button_up();
bool read_button_down();
bool read_button_back();
bool read_button_option();
bool read_ACC_CTL_PIN();