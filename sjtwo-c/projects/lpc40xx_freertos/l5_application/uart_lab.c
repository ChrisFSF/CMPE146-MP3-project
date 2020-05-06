#include "uart_lab.h"

#include "FreeRTOS.h"
#include "task.h"

#include "lpc40xx.h"
#include "lpc_peripherals.h"

// static init_status UART_check_init = {0, 0};
void uart_lab__init(uart__num_e uart, uint32_t peripheral_clk, uint32_t baud_rate) {
  // Page492
  // set up clk div

  const uint16_t divider = (uint16_t)(peripheral_clk / (16 * baud_rate) + 0.5f);

  // FDR 3:0 DIV, 7:4 MUL
  const uint8_t data_length = 3;            // 8 bit mode
  const uint8_t num_of_stop_bit = (0 << 2); // 1 stop bit
                                            //   const uint8_t parity_en = (0 << 3);       // parity disable
  // a) Power on Peripheral
  // UART 0: bit 3; 1: bit 4;  2: bit 24; 3: bit 25;
  switch (uart) {
  case UART_lab_2:
    LPC_SC->PCONP |= (1 << 24); // turn on UART2
    // fprintf(stderr, "At line %d\n", __LINE__);

    LPC_UART2->LCR = (1 << 7); // enable Divisor Latches
    // FDR 3:0 DIV, 7:4 MUL
    LPC_UART2->FDR = (1 << 4); // set div and mul value

    LPC_UART2->DLM = (divider >> 8) & 0xFF;
    LPC_UART2->DLL = (divider >> 0) & 0xFF;
    LPC_UART2->LCR &= ~(1 << 7);                    // disable Divisor Latches
    LPC_UART2->LCR = data_length | num_of_stop_bit; // set bit length to 8 bit,

    // UART_check_init.UART2_init = 1;
    break;

  case UART_lab_3:
    LPC_SC->PCONP |= (1 << 25); // turn on UART3
    LPC_UART3->LCR = (1 << 7);  // enable Divisor Latches
    // FDR 3:0 DIV, 7:4 MUL
    LPC_UART3->FDR = (1 << 4); // set div and mul value

    LPC_UART3->DLM = (divider >> 8) & 0xFF;
    LPC_UART3->DLL = (divider >> 0) & 0xFF;
    LPC_UART3->LCR &= ~(1 << 7); // disable Divisor Latches

    LPC_UART3->LCR = data_length | num_of_stop_bit; // set bit length to 8 bit,
    // UART_check_init.UART3_init = 1;
    break;
  default:
    fprintf(stderr, "Fail to init\n");
    break;
  }
  fprintf(stderr, "UART init end!\n");
}

bool uart_lab__polled_get(uart__num_e uart, char *input_byte) {
  // a) Check LSR for Receive Data Ready
  bool status = false;
  switch (uart) {
  case UART_lab_2:
    while (!(LPC_UART2->LSR & (1 << 0))) { // wait for receive data ready
    }
    *input_byte = LPC_UART2->RBR;
    status = true;
    break;

  case UART_lab_3:
    while (!(LPC_UART3->LSR & (1 << 0))) {
    }
    *input_byte = LPC_UART3->RBR;
    status = true;
    break;
  }
  //   fprintf(stderr, "Uart Read: %c", *input_byte);
  return status;
}

bool uart_lab__polled_put(uart__num_e uart, char output_byte) {
  // a) Check LSR for Transmit Hold Register Empty

  // b) Copy output_byte to THR register
  bool status = false;
  const uint32_t transmitter_empty = (1 << 5);
  //   fprintf(stderr, "put %s\n", output_byte);

  switch (uart) {
  case UART_lab_2:
    LPC_UART2->LCR &= ~(1 << 7);
    while (!(LPC_UART2->LSR & transmitter_empty)) { // check transmit data is empty, THER
    }
    // fprintf(stderr, "At line %d\n", __LINE__);
    LPC_UART2->THR = output_byte;
    while (!(LPC_UART2->LSR & transmitter_empty)) {
    }
    status = true;
    break;

  case UART_lab_3:
    LPC_UART3->LCR &= ~(1 << 7);
    while (!(LPC_UART3->LSR & transmitter_empty)) {
    }
    LPC_UART3->THR = output_byte;
    while (!(LPC_UART3->LSR & transmitter_empty)) {
    }
    status = true;
    break;
  }

  //   fprintf(stderr, "At line %d\n", __LINE__);

  return status;
}

// for queue
static QueueHandle_t chris_uart_rx_queue;
static void chris_receive_interrupt_UART2(void) {
  // TODO: Read the IIR register to figure out why you got interrupted
  // TODO: Based on IIR status, read the LSR register to confirm if there is data to be read
  // TODO: Based on LSR status, read the RBR register and input the data to the RX Queue

  // int status, 0: int is pending, 1: not int; 0x2 of IIR[3:1] is receive data available
  if (LPC_UART2->IIR & (2 << 1)) {
    // while (!(LPC_UART2->LSR & (1 << 0))) { // RDR is not empty?
    // }
    if (LPC_UART2->LSR & (1 << 0)) {
      const char data_chris = LPC_UART2->RBR; // set data from RBR reg
                                              //   fprintf(stderr, "Uart_int Read: %c\n", data_chris);

      xQueueSendFromISR(chris_uart_rx_queue, &data_chris, NULL);
    }
  } else {
    fprintf(stderr, "Int no reading\n");
  }
}

static void chris_receive_interrupt_UART3(void) {
  if (LPC_UART3->IIR & (2 << 1)) {
    if (LPC_UART3->LSR & (1 << 0)) {
      const char data_chris = LPC_UART3->RBR; // set data from RBR reg
                                              //   fprintf(stderr, "Uart_int Read: %c\n", data_chris);

      xQueueSendFromISR(chris_uart_rx_queue, &data_chris, NULL);
    }
  } else {
    fprintf(stderr, "Int no reading\n");
  }
}

void uart__enable_receive_interrupt(uart__num_e uart) {
  // TODO: Use lpc_peripherals.h to attach your interrupt

  // TODO: Enable UART receive interrupt by reading the LPC User manual
  // Hint: Read about the IER register

  switch (uart) {
  case UART_lab_2:
    NVIC_EnableIRQ(UART2_IRQn);
    lpc_peripheral__enable_interrupt(UART2_IRQn, chris_receive_interrupt_UART2, "UART__lab_2");

    LPC_UART2->IER |= (1 << 0);
    break;
  case UART_lab_3:
    NVIC_EnableIRQ(UART3_IRQn);
    lpc_peripheral__enable_interrupt(UART3_IRQn, chris_receive_interrupt_UART3, "UART__lab_3");
    LPC_UART3->IER |= (1 << 0);
    break;
  }
  // TODO: Create your RX queue
  chris_uart_rx_queue = xQueueCreate(10, sizeof(char));
}

bool uart_lab_get_char_from_queue(char *input_byte, uint32_t timeout) {
  return xQueueReceive(chris_uart_rx_queue, input_byte, timeout);
}
