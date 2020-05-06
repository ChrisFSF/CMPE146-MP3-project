#include <stdio.h>

#include "lpc40xx.h"

#include "FreeRTOS.h"
#include "semphr.h"

#include "audio_decoder.h"
#include "ssp1.h"
// decoder xcs  = P0.6
// decoder rst  = P1.14
// decoder dreg = P4.28
// decoder xdcs = P4.29

bool mp3_dreq_getLevel(void) { return ((LPC_GPIO4->PIN >> 28) & 1); }

bool decoder_needs_data() { return mp3_dreq_getLevel(); }

uint16_t mp3_SCI_read(uint8_t address) {
  dec_cs();
  ssp1__exchange_byte_lab(READ);
  ssp1__exchange_byte_lab(address);
  uint16_t dataUpper = ssp1__exchange_byte_lab(0);
  uint8_t dataLower = ssp1__exchange_byte_lab(0);
  dec_ds();
  dataUpper = (dataUpper << 8 | dataLower);
  return dataUpper;
}

void mp3_writeRequest(uint8_t address, uint16_t data) {
  while (!mp3_dreq_getLevel())
    ;
  dec_cs(); // do a chip select
  ssp1__exchange_byte_lab(WRITE);
  ssp1__exchange_byte_lab(address);
  uint8_t dataUpper = (data >> 8 & 0xFF);
  uint8_t dataLower = (data & 0xFF);
  ssp1__exchange_byte_lab(dataUpper);
  ssp1__exchange_byte_lab(dataLower);
  while (!mp3_dreq_getLevel())
    ;       // dreq should go high indicating transfer complete
  dec_ds(); // Assert a HIGH signal to de-assert the CS
}

void mp3_pause() { mp3_writeRequest(SCI_MODE, 0x0808); }

void mp3_resume() { mp3_writeRequest(SCI_MODE, 0x0800); }

void mp3_initDecoder() {
  // mp3_writeRequest(SCI_MODE, MODE);
  // FA0
  mp3_writeRequest(SCI_MODE, 0x0800);
  mp3_writeRequest(SCI_CLOCKF, 0xC000);

  // mp3_writeRequest(SCI_CLOCKF, 0x8BE8); // XTALI = 12Mhz
  mp3_writeRequest(SCI_VOL, 0x3232);

  mp3_writeRequest(SCI_BASS, 0x10f0);
  mp3_writeRequest(SCI_AUDATA, AUDATA);

  // mp3_writeRequest(SCI_AICTRL0, 0x7000);
  // mp3_writeRequest(SCI_AICTRL1, 0x7000);

  // mp3_writeRequest(SCI_AIADDR, 0x4020);
}

void mp3_set_VOL(uint16_t value) { mp3_writeRequest(SCI_VOL, value); }

// decoder xcs  = P0.6
void dec_cs(void) {
  if (xSemaphoreTake(xSemaphore_mutex_spi, 100000) == pdTRUE) {
    LPC_IOCON->P0_6 &= ~(7 << 0);
    LPC_GPIO0->DIR |= (1 << 6);
    LPC_GPIO0->CLR |= (1 << 6);
  }
}

// decoder xcs  = P0.6
void dec_ds(void) {
  LPC_IOCON->P0_6 &= ~(7 << 0);
  LPC_GPIO0->DIR |= (1 << 6);
  LPC_GPIO0->SET |= (1 << 6);
  xSemaphoreGive(xSemaphore_mutex_spi);
}

// decoder xdcs = P4.29
void dec_dcs(void) {

  if (xSemaphoreTake(xSemaphore_mutex_spi, 100000) == pdTRUE) {
    LPC_IOCON->P4_29 &= ~(7 << 0);
    LPC_GPIO4->DIR |= (1 << 29);
    LPC_GPIO4->CLR |= (1 << 29);
  }
}

// decoder xdcs = P4.29
void dec_dds(void) {
  LPC_IOCON->P4_29 &= ~(7 << 0);
  LPC_GPIO4->DIR |= (1 << 29);
  LPC_GPIO4->SET |= (1 << 29);

  xSemaphoreGive(xSemaphore_mutex_spi);
}

// decoder rst  = P1.14
void dec_rst(void) {
  LPC_IOCON->P1_14 &= ~(7 << 0);
  LPC_GPIO1->DIR |= (1 << 14);
  LPC_GPIO1->CLR |= (1 << 14);

  vTaskDelay(100);
  LPC_GPIO1->SET |= (1 << 14);
  vTaskDelay(1);
}

// decoder dreg = P4.28
void dec_dreq_set_as_input(void) {
  LPC_IOCON->P4_28 &= ~(0x7 << 0);
  LPC_GPIO4->DIR &= ~(1 << 28);
}

void dec_init() {
  dec_dreq_set_as_input();

  dec_ds();
  dec_dds();

  vTaskDelay(1);
  dec_rst();

  vTaskDelay(100);
  puts("mp3_initDecoder");
  mp3_initDecoder();
  uint8_t divisor = (uint8_t)(96U / 8);
  LPC_SSP1->CPSR = divisor;

  vTaskDelay(10);
}

mp3_dec mp3_dec_read(uint8_t first, uint8_t second, uint8_t third, uint8_t forth) {
  mp3_dec data = {1, 2, 3, 4};

  dec_cs();

  data.first_byte = ssp1__exchange_byte_lab(first);
  data.second_byte = ssp1__exchange_byte_lab(second);
  data.third_byte = ssp1__exchange_byte_lab(third);
  data.forth_byte = ssp1__exchange_byte_lab(forth);

  dec_ds();

  return data;
}

void mp3_dec_d_write(uint8_t first, uint8_t second, uint8_t third, uint8_t forth) {
  dec_dcs();
  {
    ssp1__exchange_byte_lab(first);
    ssp1__exchange_byte_lab(second);
    ssp1__exchange_byte_lab(third);
    ssp1__exchange_byte_lab(forth);
    // ssp1__exchange_byte_lab(0);
    // ssp1__exchange_byte_lab(0);
    // ssp1__exchange_byte_lab(0);
    // ssp1__exchange_byte_lab(0);
  }
  dec_dds();
}