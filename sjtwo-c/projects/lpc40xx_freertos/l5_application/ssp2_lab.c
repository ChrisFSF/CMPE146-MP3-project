#include "ssp2_lab.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "clock.h"
#include "lpc40xx.h"
#include "lpc_peripherals.h"

port_pin_s P1_10 = {1, 10};
void adesto_cs(void) {
  // gpio__construct_with_function(GPIO__PORT_1, 10, 0);//set as gpio
  gpiox__set_as_output(P1_10);
  gpiox__set_low(P1_10);
}

void adesto_ds(void) { gpiox__set_high(P1_10); }

void ssp2_lab_init(uint32_t max_clock_mhz) {
  // Refer to LPC User manual and setup the register bits correctly //Page601 SSP
  // a) Power on Peripheral //Page30
  // PCSSP0 = bit 21 ,PCSSP1 = bit 10, PCSSP2 = bit 20
  //   LPC_SC->PCONP |= (1 << 21); //PCSSP0
  //   LPC_SC->PCONP |= (1 << 10); //PCSSP1
  LPC_SC->PCONP |= (1 << 20);    // PCSSP2
  LPC_SC->PCLKSEL |= (0b10 < 0); // first five bit of 4:0 is PCLKDIV, chose PCLK/2 by defalut

  // b) Setup control registers CR0 and CR1
  LPC_SSP2->CR0 |= (7 << 0); // 8-bit mode, CPOL = 0, CPHA = 0, page 611
                             //   LPC_SSP2->CR0 &= ~(0xFF << 8);  // set SCR as zero in PCLK/(CPSDVSR[SCR+1])
  LPC_SSP2->CR1 |= (1 << 1); // SSP enable, set as master

  // c) Setup prescalar register to be <= max_clock_mhz
  // Keep scaling down divider until calculated is higher
  const uint32_t cpu_clk_mhz = (UINT32_C(96) * 1000 * 1000);
  uint8_t divider = 2; // even number in range 2 - 254
  while (max_clock_mhz < (cpu_clk_mhz / divider) && divider <= 254) {
    divider += 2;
  }
  LPC_SSP2->CPSR = divider;
}

uint8_t ssp2_lab_exchange_byte(uint8_t data_out) {
  // Configure the Data register(DR) to send and receive data by checking the status register
  LPC_SSP2->DR = data_out;
  while (LPC_SSP2->SR & (1 << 4)) { // compare with BSY of SR reg
    ;                               // DO NOTHING, Waiting for data_in
  }
  return (uint8_t)(LPC_SSP2->DR & 0xFF);
}

// read status reg
adesto_flash_status adesto_read_status() {
  adesto_flash_status status;
  adesto_cs();                                // chip sel to flash
  ssp2_lab_exchange_byte(0x05);               // send opcode, wait state before geting right data
  status.byte = ssp2_lab_exchange_byte(0xFF); // read manufacture_id
  ssp2_lab_exchange_byte(0xFF);

  adesto_ds(); // deselect the flash

  return status;
}

uint8_t flash_read_a_page_once(uint32_t address) {
  // opcode 33Mhz:03h, 104Mhz: 0bh
  ssp2_lab_exchange_byte(0x0b);                   // page program
  ssp2_lab_exchange_byte((address >> 16) & 0xFF); // High address
  ssp2_lab_exchange_byte((address >> 8) & 0xFF);  // middle address
  ssp2_lab_exchange_byte((address >> 0) & 0xFF);  // low address
  uint8_t data = ssp2_lab_exchange_byte(0xFF);
  return data;
}

void flash_erase_page(uint32_t address) {
  // page erase opcode 81h
  ssp2_lab_exchange_byte(0x81);                   // pagev erase
  ssp2_lab_exchange_byte((address >> 16) & 0xFF); // High address
  ssp2_lab_exchange_byte((address >> 8) & 0xFF);  // middle address
  ssp2_lab_exchange_byte((address >> 0) & 0xFF);  // low address
}

void flash_write_enable() {
  ssp2_lab_exchange_byte(0x06); // write enable
}

void flash_write_disable() {
  ssp2_lab_exchange_byte(0x04); // write disable
}
void send_flash_write_a_page_opcode(uint32_t address) {
  // opcode 02h for page program
  ssp2_lab_exchange_byte(0x02);                   // page program
  ssp2_lab_exchange_byte((address >> 16) & 0xFF); // High address
  ssp2_lab_exchange_byte((address >> 8) & 0xFF);  // middle address
  ssp2_lab_exchange_byte((address >> 0) & 0xFF);  // low address
}
