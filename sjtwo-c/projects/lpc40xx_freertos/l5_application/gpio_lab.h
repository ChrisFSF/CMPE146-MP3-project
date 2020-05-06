// file gpio_lab.h
#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct {
  uint8_t port;
  uint8_t pin;
} port_pin_s;

bool check_pin(port_pin_s pin_num);
void func_set_gpiox__iocon(port_pin_s gpio, uint8_t port);

/// Should alter the hardware registers to set the pin as input
void gpiox__set_as_input(port_pin_s pin_num);

/// Should alter the hardware registers to set the pin as output
void gpiox__set_as_output(port_pin_s pin_num);

/// Should alter the hardware registers to set the pin as high
void gpiox__set_high(port_pin_s pin_num);

/// Should alter the hardware registers to set the pin as low
void gpiox__set_low(port_pin_s pin_num);

/**
 * Should alter the hardware registers to set the pin as low
 *
 * @param {bool} high - true => set pin high, false => set pin low
 */
void gpiox__set(port_pin_s pin_num, bool high);

/**
 * Should return the state of the pin (input or output, doesn't matter)
 *
 * @return {bool} level of pin high => true, low => false
 */
bool gpiox__get_level(port_pin_s func);

///////////////for Interrupt///////////////////
/**
 *@param {int} Rising_or_Falling - 1 => set Rising edge, 0 => Falling edge
 */
void gpiox__setINT_Trigger_level(port_pin_s gpio, int Rising_or_Falling);

/**
 *@param {int} Rising_or_Falling - 1 => set Rising edge, 0 => Falling edge
 */
bool Check_signle_Int_Status(port_pin_s gpio, int Rising_or_Falling);

bool Check_all_Int_Status();

void Clear_Int(port_pin_s gpio);