#pragma once
#include <stdint.h>

void ssp0__init_lab(uint32_t max_clock_mhz);

uint8_t ssp0__exchange_byte_lab(uint8_t data_out);
