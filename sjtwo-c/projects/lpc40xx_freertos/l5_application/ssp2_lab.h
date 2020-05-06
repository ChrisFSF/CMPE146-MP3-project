#pragma once

#include "gpio_lab.h"
#include <stdint.h>
#include <stdlib.h>

typedef union {
  uint8_t byte;
  struct {
    uint8_t RDY_DBY; // Ready/Bussy status
    uint8_t WEL;     // Write Enable latch status
    uint8_t BP0;     // Block protection
    uint8_t RES_3;   // Reserved
    uint8_t WPP;     // Write protect pin status
    uint8_t EPE;     // Erase/Progam Error
    uint8_t RES_6;   // Reserved
    uint8_t BPL;     // R/W Block protection locked
  } __attribute__((packed));

} adesto_flash_status;

void adesto_cs(void);
void adesto_ds(void);

void ssp2_lab_init(uint32_t max_clock_mhz);
uint8_t ssp2_lab_exchange_byte(uint8_t data_out);
adesto_flash_status adesto_read_status();
uint8_t flash_read_a_page_once(uint32_t address);

void flash_erase_page(uint32_t address);
void flash_write_enable();
void flash_write_disable();
void send_flash_write_a_page_opcode(uint32_t address);