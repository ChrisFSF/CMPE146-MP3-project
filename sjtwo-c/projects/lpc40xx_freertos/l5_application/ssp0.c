#include "ssp0.h"
#include "lpc40xx.h"

void ssp0_pin_init() {
  LPC_IOCON->P0_15 &= ~(7 << 0); // FUNC clear
  LPC_IOCON->P0_15 |= (2 << 0);  // FUNC 010 ssp0_SCK

  LPC_IOCON->P0_17 &= ~(7 << 0); // FUNC clear
  LPC_IOCON->P0_17 |= (2 << 0);  // FUNC 010 ssp0_MISO

  LPC_IOCON->P0_18 &= ~(7 << 0); // FUNC clear
  LPC_IOCON->P0_18 |= (2 << 0);  // FUNC 010 ssp0_MOSI
}

void ssp0__init_lab(uint32_t max_clock_mhz) {
  // Table 16, Bit[21]: PCssp0, ssp0 interface power/clock control bit.
  ssp0_pin_init();
  LPC_SC->PCONP |= (1 << 21);

  LPC_SSP0->CR0 |= (7 << 0);  // Table 483, Bit[3:0], Data Size Select: 0111 8-bit transfer
  LPC_SSP0->CR1 |= (1 << 1);  // Table 484, Bit[1], SSP Enable: 1 SSP controller is enabled
  LPC_SSP0->CR1 &= ~(1 << 2); // Table 484, Bit[2], 0=Master mode, 1=Slave mode

  // c) Setup prescalar register to be <= max_clock_mhz
  uint8_t divisor = (uint8_t)(96U / max_clock_mhz);
  if (divisor > 254) {
    divisor = 254U;
  }
  LPC_SSP0->CPSR = divisor; // Table 487 Clock Prescale Register(CPSR), [7:0] CPSDVSR
}

uint8_t ssp0__exchange_byte_lab(uint8_t data_out) {
  // Configure the Data register(DR) to send and receive data by checking the SPI peripheral status register
  // Table 486, Status Register(SR)(read only)
  // Table 485, Data Register(DR)
  LPC_SSP0->DR = (uint16_t)data_out; // assume Tx FIFO alwasys empty at this point

  while (LPC_SSP0->SR & (1 << 4)) { // Bit 4 BSY: 1=busy, 0=idle
    ;
  }

  return (uint8_t)(LPC_SSP0->DR & 0xFF);
}