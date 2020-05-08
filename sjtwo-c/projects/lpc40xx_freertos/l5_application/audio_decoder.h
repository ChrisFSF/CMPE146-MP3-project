#pragma once
#include "queue.h"
#include "semphr.h"
#include <stdbool.h>
#include <stdint.h>
// decoder dreg = P1.4
// decoder rst  = P1.14
// decoder xcs  = P4.28
// decoder xdcs = P4.29
QueueHandle_t queue_song_name;
SemaphoreHandle_t xSemaphore_mutex_spi;
QueueHandle_t queue_song_data_block;

typedef char song_name_t[32];
typedef uint8_t song_data_block_t[512];

static const uint16_t MODE = 0x4810;   // 4800
static const uint16_t CLOCKF = 0xE000; // was 9800, EBE8, B3E8, BBE8
static volatile uint16_t VOL = 0x2222; // full vol
// static uint16_t BASS = 0x0076;         // was 00F6
static uint16_t AUDATA = 0xAC45; // for stereo decoding, AC45,AC80, BB80-check
// static uint16_t STATUS;
// extern SemaphoreHandle_t xSemaphore_mutex_spi;
// VS10xx SCI Registers
#define SCI_MODE 0x00
#define SCI_STATUS 0x01
#define SCI_BASS 0x02
#define SCI_CLOCKF 0x03
#define SCI_DECODE_TIME 0x04
#define SCI_AUDATA 0x05
#define SCI_WRAM 0x06
#define SCI_WRAMADDR 0x07
#define SCI_HDAT0 0x08
#define SCI_HDAT1 0x09
#define SCI_AIADDR 0x0A
#define SCI_VOL 0x0B
#define SCI_AICTRL0 0x0C
#define SCI_AICTRL1 0x0D
#define SCI_AICTRL2 0x0E
#define SCI_AICTRL3 0x0F
#define playSpeed 0x1E04

// commands
#define READ 0x03
#define WRITE 0x02

// static uint8_t SEND_NUM_BYTES = 32;
// static uint16_t READ_BYTES_FROM_FILE = 4096;
// static uint16_t TRANSMIT_BYTES_TO_DECODER = 32;

typedef struct {
  uint8_t first_byte;
  uint8_t second_byte;
  uint8_t third_byte;
  uint8_t forth_byte;
} mp3_dec;

bool mp3_dreq_getLevel(void);
bool decoder_needs_data();
void mp3_writeRequest(uint8_t address, uint16_t data);
void mp3_initDecoder();
void dec_cs(void);
void dec_ds(void);
void dec_dcs(void);
void dec_dds(void);
void dec_rst(void);
void dec_dreq_set_as_input(void);
// void spi_ds_1_10(void);
void dec_init();
mp3_dec mp3_dec_read(uint8_t first, uint8_t second, uint8_t third, uint8_t forth);
void mp3_dec_d_write(uint8_t first, uint8_t second, uint8_t third, uint8_t forth);
void mp3_pause();
void mp3_resume();
uint16_t mp3_SCI_read(uint8_t address);

void dec_set_VOLUME(uint16_t value);
void dec_set_VOLUME_(int audio_volume);
void dec_set_VOLUME_LR(int audio_volume_left, int audio_volume_right);
void dec_set_BASS_TREBLE(int Treble_Amplitude_index, int Treble_Frequency_index, int Bass_Amplitude_index,
                         int Bass_Frequency_index);
