#include "ssp1.h"
#include "lpc40xx.h"

void ssp1_pin_init() {
  LPC_IOCON->P0_6 &= ~(7 << 0); // FUNC clear
  // LPC_IOCON->P0_6 |= (2 << 0);  // FUNC 010 SSP1_SSEL

  LPC_IOCON->P0_7 &= ~(7 << 0); // FUNC clear
  LPC_IOCON->P0_7 |= (2 << 0);  // FUNC 010 SSP1_SCK

  LPC_IOCON->P0_8 &= ~(7 << 0); // FUNC clear
  LPC_IOCON->P0_8 |= (2 << 0);  // FUNC 010 SSP1_MISO

  LPC_IOCON->P0_9 &= ~(7 << 0); // FUNC clear
  LPC_IOCON->P0_9 |= (2 << 0);  // FUNC 010 SSP1_MOSI
}

void ssp1__init_lab(uint32_t max_clock_mhz) {
  // Refer to LPC User manual and setup the register bits correctly
  // a) Power on Peripheral
  // Power Control for Peripherals register (PCONP)
  // Table 16, Bit[21]: PCSSP1, SSP1 interface power/clock control bit.
  ssp1_pin_init();
  LPC_SC->PCONP |= (1 << 10);

  // b) Setup control registers CR0 and CR1
  LPC_SSP1->CR0 |= (7 << 0);  // Table 483, Bit[3:0], Data Size Select: 0111 8-bit transfer
  LPC_SSP1->CR1 |= (1 << 1);  // Table 484, Bit[1], SSP Enable: 1 SSP controller is enabled
  LPC_SSP1->CR1 &= ~(1 << 2); // Table 484, Bit[2], 0=Master mode, 1=Slave mode

  // c) Setup prescalar register to be <= max_clock_mhz
  uint8_t divisor = (uint8_t)(96U / max_clock_mhz);
  if (divisor > 254) {
    divisor = 254U;
  }
  LPC_SSP1->CPSR = divisor; // Table 487 Clock Prescale Register(CPSR), [7:0] CPSDVSR
}

void ssp1__init_max_clock() {
  // Refer to LPC User manual and setup the register bits correctly
  // a) Power on Peripheral
  // Power Control for Peripherals register (PCONP)
  // Table 16, Bit[21]: PCSSP1, SSP1 interface power/clock control bit.
  ssp1_pin_init();
  LPC_SC->PCONP |= (1 << 10);

  // b) Setup control registers CR0 and CR1
  LPC_SSP1->CR0 |= (7 << 0);  // Table 483, Bit[3:0], Data Size Select: 0111 8-bit transfer
  LPC_SSP1->CR1 |= (1 << 1);  // Table 484, Bit[1], SSP Enable: 1 SSP controller is enabled
  LPC_SSP1->CR1 &= ~(1 << 2); // Table 484, Bit[2], 0=Master mode, 1=Slave mode

  // c) Setup prescalar register to be <= max_clock_mhz
  uint8_t divisor = 4;
  LPC_SSP1->CPSR = divisor; // Table 487 Clock Prescale Register(CPSR), [7:0] CPSDVSR
}

uint8_t ssp1__exchange_byte_lab(uint8_t data_out) {
  // Configure the Data register(DR) to send and receive data by checking the SPI peripheral status register
  // Table 486, Status Register(SR)(read only)
  // Table 485, Data Register(DR)
  LPC_SSP1->DR = (uint16_t)data_out; // assume Tx FIFO alwasys empty at this point

  while (LPC_SSP1->SR & (1 << 4)) { // Bit 4 BSY: 1=busy, 0=idle
    ;
  }

  return (uint8_t)(LPC_SSP1->DR & 0xFF);
}