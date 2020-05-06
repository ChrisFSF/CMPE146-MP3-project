//@file gpio_isr.h
#pragma once
#include "gpio_lab.h"

typedef enum {
  GPIOx_INTR_FALLING_EDGE,
  GPIOx_INTR_RISING_EDGE,
} gpio_interrupt_e;

typedef struct {
  port_pin_s port_pin;
  int trigger;
} port_pin_trigger;

// function pointer type
typedef void (*function_pointer_t)(void);

// allow the user to attach their callbacks
void gpiox__attach_interrupt(port_pin_s gpio, gpio_interrupt_e interrupt_type, function_pointer_t callback);

// Our main() should configure interrupts to invoke this dispatcher where we will invoke user attached callbacks
// You can hijack 'interrupt_vector_table.c' or use API at lpc_peripherals.h
port_pin_trigger check_all_int_pin();

void gpiox__interrupt_dispatcher(void);