// @file gpio_isr.c
#include "gpio_isr.h"
#include <stdio.h>
// #include "stdint.h"

// Note: You may want another separate array for falling vs. rising edge callbacks
static function_pointer_t gpio0_callbacks_falling[32];
static function_pointer_t gpio0_callbacks_rising[32];
static function_pointer_t gpio2_callbacks_falling[32];
static function_pointer_t gpio2_callbacks_rising[32];

void gpiox__attach_interrupt(port_pin_s gpio, gpio_interrupt_e interrupt_type, function_pointer_t callback) {
  // 1) Store the callback based on the pin at gpio0_callbacks

  // 2) Configure GPIO 0 pin for rising or falling edge
  if (gpio.port != 0 && gpio.port != 2) {
    fprintf(stderr, "gpiox__attach_interrupt: Wrong Port number input!\n");
  } else {
    // fprintf(stderr, "Set gpiox__attach_interrupt\n");

    switch (interrupt_type) { // selsect trigger level
    case GPIOx_INTR_FALLING_EDGE:
      switch (gpio.port) { // selecet port
      case 0:
        gpio0_callbacks_falling[gpio.pin] = callback;
        // fprintf(stderr, "FALLING attach pin: %d\n", gpio.pin);
        break;

      case 2:
        gpio2_callbacks_falling[gpio.pin] = callback;
        // fprintf(stderr, "FALLING attach pin: %d\n", gpio.pin);
        break;
      }
      gpiox__setINT_Trigger_level(gpio, 0); // set trigger level as falling edge
      break;
    case GPIOx_INTR_RISING_EDGE:
      switch (gpio.port) {
      case 0:
        gpio0_callbacks_rising[gpio.pin] = callback;
        // fprintf(stderr, "RISING attach pin: %u\n", gpio.pin);
        break;

      case 2:
        gpio2_callbacks_rising[gpio.pin] = callback;
        // fprintf(stderr, "RISING attach pin: %u\n", gpio.pin);
        break;
      }
      gpiox__setINT_Trigger_level(gpio, 1); // set trigger level as rising edge

      break;
    } // end of outter switch
  }   // end of else
} // end of function

port_pin_trigger check_all_int_pin() {

  port_pin_s temp_gpio = {0, 0};
  port_pin_trigger save_pin_trigger_level = {temp_gpio, 0};
  // check for port0 falling.............................................
  if (Check_all_Int_Status()) {

    for (int i = 0; i <= 31; i++) {
      // fprintf(stderr, "Recent int port pin: p%u_%u\n", temp_gpio.port, temp_gpio.pin);

      if (Check_signle_Int_Status(temp_gpio, 0) == 1) {
        // fprintf(stderr, "Port0: Found interrupt from Falling Edge!\n");
        save_pin_trigger_level.trigger = 0;
        save_pin_trigger_level.port_pin = temp_gpio;

        return save_pin_trigger_level;
      }
      temp_gpio.pin++;
    }

    // check for port0 rising
    temp_gpio.pin = 0; // reset pin number
    for (int i = 0; i <= 31; i++) {
      // fprintf(stderr, "Recent int port pin: p%u_%u\n", temp_gpio.port, temp_gpio.pin);

      if (Check_signle_Int_Status(temp_gpio, 1) == 1) {

        // fprintf(stderr, "Port0: Found interrupt from Rising Edge!\n");
        save_pin_trigger_level.trigger = 1;
        save_pin_trigger_level.port_pin = temp_gpio;

        return save_pin_trigger_level;
      }
      temp_gpio.pin++;
    }
    // check for port2.....................................................
    temp_gpio.port = 2; // reset and prepare for port2
    temp_gpio.pin = 0;
    // check for port2 falling
    for (int i = 0; i <= 31; i++) {
      // fprintf(stderr, "Recent int port pin: p%u_%u\n", temp_gpio.port, temp_gpio.pin);

      if (Check_signle_Int_Status(temp_gpio, 0) == 1) {

        // fprintf(stderr, "Port2: Found interrupt from Falling Edge!\n");
        save_pin_trigger_level.trigger = 0;
        save_pin_trigger_level.port_pin = temp_gpio;

        return save_pin_trigger_level;
      }
      temp_gpio.pin++;
    }

    // check for port2 rising
    temp_gpio.pin = 0; // reset pin number
    for (int i = 0; i <= 31; i++) {
      // fprintf(stderr, "Recent int port pin: p%u_%u\n", temp_gpio.port, temp_gpio.pin);

      if (Check_signle_Int_Status(temp_gpio, 1) == 1) {

        // fprintf(stderr, "Port2: Found interrupt from Rising Edge!\n");
        save_pin_trigger_level.trigger = 1;
        save_pin_trigger_level.port_pin = temp_gpio;

        return save_pin_trigger_level;
      }
      temp_gpio.pin++;
    }

  } else {
    fprintf(stderr, "Interrput No Found!!\n");
  }

  return save_pin_trigger_level;
}

// We wrote some of the implementation for you
void gpiox__interrupt_dispatcher(void) {
  // Check which pin generated the interrupt
  port_pin_trigger temp_gpio_status; /// pin, trigger level
  function_pointer_t attached_user_handler;

  temp_gpio_status = check_all_int_pin();

  const int pin_that_generated_interrupt = temp_gpio_status.port_pin.pin;
  const int port_that_generated_interrupt = temp_gpio_status.port_pin.port;

  // select function pointer
  if (port_that_generated_interrupt != 0 && port_that_generated_interrupt != 2) {
    fprintf(stderr, "gpiox__interrupt_dispatcher: Wrong Port number input!\n");
  } else {
    // fprintf(stderr, "Getting the attached_user_handler\n");

    switch (temp_gpio_status.trigger) {        // selsect trigger level
    case 0:                                    // falling edge
      switch (port_that_generated_interrupt) { // selecet port
      case 0:                                  // port 0 for falling edge
        attached_user_handler = gpio0_callbacks_falling[pin_that_generated_interrupt];
        break;

      case 2: // port 2 for falling edge
        attached_user_handler = gpio2_callbacks_falling[pin_that_generated_interrupt];
        break;
      }
      break;
    case 1: // rising edge
      switch (port_that_generated_interrupt) {
      case 0: // port 0 for rising edge
        attached_user_handler = gpio0_callbacks_rising[pin_that_generated_interrupt];
        break;

      case 2: // port 2 for rising edge
        attached_user_handler = gpio2_callbacks_rising[pin_that_generated_interrupt];
        break;
      }
      break;
    } // end of outter switch
  }   // end of else
  // Invoke the user registered callback, and then clear the interrupt
  // Clear_Int(temp_gpio_status.port_pin);
  attached_user_handler();

  Clear_Int(temp_gpio_status.port_pin);
}