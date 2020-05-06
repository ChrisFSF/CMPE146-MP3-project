#pragma once

#include "FreeRTOS.h"
#include "queue.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef enum {
  //   UART_0,
  //   UART_1,
  UART_lab_2,
  UART_lab_3,
} uart__num_e;

void uart_lab__init(uart__num_e uart, uint32_t peripheral_clk, uint32_t baud_rate);
bool uart_lab__polled_put(uart__num_e uart, char output_byte);
bool uart_lab__polled_get(uart__num_e uart, char *input_byte);

void uart__enable_receive_interrupt(uart__num_e uart);
bool uart_lab_get_char_from_queue(char *input_byte, uint32_t timeout);
/* Page492
P0_0:***
    - 100 U0_TXD
P0_1:***
    - 100 U0_RXD

P0_15:***
    - 001 U1_TXD
P0_16:***
    - 001 U1_RXD

P2_8:***
    - 010 U2_TXD
P2_9:***
    - 010 U2_RXD

P0_25:***
    - 011 U3_TXD
P0_26:***
    - 011 U3_RXD
*/
