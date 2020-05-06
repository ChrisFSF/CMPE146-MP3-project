#pragma once
#include <stdint.h>

void ssp1__init_lab(uint32_t max_clock_mhz);
void ssp1__init_max_clock();

uint8_t ssp1__exchange_byte_lab(uint8_t data_out);
