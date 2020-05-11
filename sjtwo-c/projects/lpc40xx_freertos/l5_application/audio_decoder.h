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

typedef struct {
  uint8_t first_byte;
  uint8_t second_byte;
  uint8_t third_byte;
  uint8_t forth_byte;
} dec_spi_4bytes_t;

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

#define SCI_MODE_INIT 0x0800
#define SCI_CLOCKF_INIT 0xC000
#define SCI_VOL_INIT 0x3232
#define SCI_BASS_INIT 0x0000
#define SCI_AUDATA_INIT 0xAC45
// #define SCI_STATUS_INIT

// static const uint16_t MODE = 0x0800;
// static const uint16_t CLOCKF = 0xC000;
// static volatile uint16_t VOL = 0x3232;
// static uint16_t BASS = 0x0000;
// static uint16_t AUDATA = 0xAC45; // 0xAC45 for stereo decoding
// static uint16_t STATUS;
// extern SemaphoreHandle_t xSemaphore_mutex_spi;

void dec_cs(void);
void dec_ds(void);
void dec_dcs(void);
void dec_dds(void);

bool dec_getlevel_dreq(void);
bool decoder_needs_data(void);

void dec_write_command(uint8_t address, uint16_t data);

void dec_init(void);
void dec_init_command();
void dec_rst(void);

void dec_dreq_set_as_input(void);
void dec_stop_decoding(void);
void dec_resume_decoding(void);
// uint16_t mp3_SCI_read(uint8_t address);
dec_spi_4bytes_t dec_write_read(uint8_t first_byte, uint8_t second_byte, uint8_t third_byte, uint8_t forth_byte);


void dec_set_VOLUME(uint16_t value);
void dec_set_VOLUME_(int audio_volume);
void dec_set_VOLUME_LR(int audio_volume_left, int audio_volume_right);
void dec_set_BASS_TREBLE(int Treble_Amplitude_index, int Treble_Frequency_index, 
                         int Bass_Amplitude_index, int Bass_Frequency_index);
