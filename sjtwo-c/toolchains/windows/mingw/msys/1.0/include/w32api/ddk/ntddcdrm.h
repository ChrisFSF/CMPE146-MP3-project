/*
 * ntddcdrm.h
 *
 * CDROM IOCTL interface.
 *
 * This file is part of the w32api package.
 *
 * Contributors:
 *   Created by Casper S. Hornstrup <chorns@users.sourceforge.net>
 *
 * THIS SOFTWARE IS NOT COPYRIGHTED
 *
 * This source code is offered for use in the public domain. You may
 * use, modify or distribute it freely.
 *
 * This code is distributed in the hope that it will be useful but
 * WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 * DISCLAIMED. This includes but is not limited to warranties of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#ifndef __NTDDCDRM_H
#define __NTDDCDRM_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "ntddk.h"
#include "ntddstor.h"

#define IOCTL_CDROM_BASE                  FILE_DEVICE_CD_ROM

#define IOCTL_CDROM_CHECK_VERIFY \
  CTL_CODE(IOCTL_CDROM_BASE, 0x0200, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_CDROM_FIND_NEW_DEVICES \
  CTL_CODE(IOCTL_CDROM_BASE, 0x0206, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_CDROM_GET_CONTROL \
  CTL_CODE(IOCTL_CDROM_BASE, 0x000D, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_CDROM_GET_DRIVE_GEOMETRY \
  CTL_CODE(IOCTL_CDROM_BASE, 0x0013, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_CDROM_GET_LAST_SESSION \
  CTL_CODE(IOCTL_CDROM_BASE, 0x000E, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_CDROM_GET_VOLUME \
  CTL_CODE(IOCTL_CDROM_BASE, 0x0005, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_CDROM_PAUSE_AUDIO \
  CTL_CODE(IOCTL_CDROM_BASE, 0x0003, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_CDROM_PLAY_AUDIO_MSF \
  CTL_CODE(IOCTL_CDROM_BASE, 0x0006, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_CDROM_RAW_READ \
  CTL_CODE(IOCTL_CDROM_BASE, 0x000F, METHOD_OUT_DIRECT,  FILE_READ_ACCESS)

#define IOCTL_CDROM_READ_Q_CHANNEL \
  CTL_CODE(IOCTL_CDROM_BASE, 0x000B, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_CDROM_READ_TOC \
  CTL_CODE(IOCTL_CDROM_BASE, 0x0000, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_CDROM_READ_TOC_EX \
  CTL_CODE(IOCTL_CDROM_BASE, 0x0015, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_CDROM_RESUME_AUDIO \
  CTL_CODE(IOCTL_CDROM_BASE, 0x0004, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_CDROM_SEEK_AUDIO_MSF \
  CTL_CODE(IOCTL_CDROM_BASE, 0x0001, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_CDROM_SET_VOLUME \
  CTL_CODE(IOCTL_CDROM_BASE, 0x000A, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_CDROM_SIMBAD \
  CTL_CODE(IOCTL_CDROM_BASE, 0x1003, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_CDROM_STOP_AUDIO \
  CTL_CODE(IOCTL_CDROM_BASE, 0x0002, METHOD_BUFFERED, FILE_READ_ACCESS)


#define MAXIMUM_NUMBER_TRACKS             100
#define MAXIMUM_CDROM_SIZE                804
#define MINIMUM_CDROM_READ_TOC_EX_SIZE    2

typedef struct _TRACK_DATA {
  UCHAR  Reserved;
  UCHAR  Control : 4;
  UCHAR  Adr : 4;
  UCHAR  TrackNumber;
  UCHAR  Reserved1;
  UCHAR  Address[4];
} TRACK_DATA, *PTRACK_DATA;

/* CDROM_DISK_DATA.DiskData flags */
#define CDROM_DISK_AUDIO_TRACK            0x00000001
#define CDROM_DISK_DATA_TRACK             0x00000002

typedef struct _CDROM_DISK_DATA {
  ULONG  DiskData;
} CDROM_DISK_DATA, *PCDROM_DISK_DATA;

typedef struct _CDROM_PLAY_AUDIO_MSF {
  UCHAR  StartingM;
  UCHAR  StartingS;
  UCHAR  StartingF;
  UCHAR  EndingM;
  UCHAR  EndingS;
  UCHAR  EndingF;
} CDROM_PLAY_AUDIO_MSF, *PCDROM_PLAY_AUDIO_MSF;

/* CDROM_READ_TOC_EX.Format constants */
#define CDROM_READ_TOC_EX_FORMAT_TOC      0x00
#define CDROM_READ_TOC_EX_FORMAT_SESSION  0x01
#define CDROM_READ_TOC_EX_FORMAT_FULL_TOC 0x02
#define CDROM_READ_TOC_EX_FORMAT_PMA      0x03
#define CDROM_READ_TOC_EX_FORMAT_ATIP     0x04
#define CDROM_READ_TOC_EX_FORMAT_CDTEXT   0x05

typedef struct _CDROM_READ_TOC_EX {
  UCHAR  Format : 4;
  UCHAR  Reserved1 : 3; 
  UCHAR  Msf : 1;
  UCHAR  SessionTrack;
  UCHAR  Reserved2;
  UCHAR  Reserved3;
} CDROM_READ_TOC_EX, *PCDROM_READ_TOC_EX;

typedef struct _CDROM_SEEK_AUDIO_MSF {
  UCHAR  M;
  UCHAR  S;
  UCHAR  F;
} CDROM_SEEK_AUDIO_MSF, *PCDROM_SEEK_AUDIO_MSF;

/* CDROM_SUB_Q_DATA_FORMAT.Format constants */
#define IOCTL_CDROM_SUB_Q_CHANNEL         0x00
#define IOCTL_CDROM_CURRENT_POSITION      0x01
#define IOCTL_CDROM_MEDIA_CATALOG         0x02
#define IOCTL_CDROM_TRACK_ISRC            0x03

typedef struct _CDROM_SUB_Q_DATA_FORMAT {
  UCHAR Format;
  UCHAR Track;
} CDROM_SUB_Q_DATA_FORMAT, *PCDROM_SUB_Q_DATA_FORMAT;

typedef struct _CDROM_TOC {
  UCHAR  Length[2];
  UCHAR  FirstTrack;
  UCHAR  LastTrack;
  TRACK_DATA  TrackData[MAXIMUM_NUMBER_TRACKS];
} CDROM_TOC, *PCDROM_TOC;

#define CDROM_TOC_SIZE sizeof(CDROM_TOC)

typedef struct _CDROM_TOC_ATIP_DATA_BLOCK {
  UCHAR  CdrwReferenceSpeed : 3;
  UCHAR  Reserved3 : 1;
  UCHAR  WritePower : 3;
  UCHAR  True1 : 1;
  UCHAR  Reserved4 : 6;
  UCHAR  UnrestrictedUse : 1;
  UCHAR  Reserved5 : 1;
  UCHAR  A3Valid : 1;
  UCHAR  A2Valid : 1;
  UCHAR  A1Valid : 1;
  UCHAR  Reserved6 : 3;
  UCHAR  IsCdrw : 1;
  UCHAR  True2 : 1;
  UCHAR  Reserved7;
  UCHAR  LeadInMsf[3];
  UCHAR  Reserved8;
  UCHAR  LeadOutMsf[3];
  UCHAR  Reserved9;
  UCHAR  A1Values[3];
  UCHAR  Reserved10;
  UCHAR  A2Values[3];
  UCHAR  Reserved11;
  UCHAR  A3Values[3];
  UCHAR  Reserved12;
} CDROM_TOC_ATIP_DATA_BLOCK, *PCDROM_TOC_ATIP_DATA_BLOCK;

typedef struct _CDROM_TOC_ATIP_DATA {
  UCHAR  Length[2];
  UCHAR  Reserved1;
  UCHAR  Reserved2;
  CDROM_TOC_ATIP_DATA_BLOCK  Descriptors[0];
} CDROM_TOC_ATIP_DATA, *PCDROM_TOC_ATIP_DATA;

/* CDROM_TOC_CD_TEXT_DATA_BLOCK.PackType constants */
#define CDROM_CD_TEXT_PACK_ALBUM_NAME 0x80
#define CDROM_CD_TEXT_PACK_PERFORMER  0x81
#define CDROM_CD_TEXT_PACK_SONGWRITER 0x82
#define CDROM_CD_TEXT_PACK_COMPOSER   0x83
#define CDROM_CD_TEXT_PACK_ARRANGER   0x84
#define CDROM_CD_TEXT_PACK_MESSAGES   0x85
#define CDROM_CD_TEXT_PACK_DISC_ID    0x86
#define CDROM_CD_TEXT_PACK_GENRE      0x87
#define CDROM_CD_TEXT_PACK_TOC_INFO   0x88
#define CDROM_CD_TEXT_PACK_TOC_INFO2  0x89
#define CDROM_CD_TEXT_PACK_UPC_EAN    0x8e
#define CDROM_CD_TEXT_PACK_SIZE_INFO  0x8f

typedef struct _CDROM_TOC_CD_TEXT_DATA_BLOCK {
  UCHAR  PackType;
  UCHAR  TrackNumber : 7;
  UCHAR  ExtensionFlag : 1;
  UCHAR  SequenceNumber;
  UCHAR  CharacterPosition : 4;
  UCHAR  BlockNumber : 3;
  UCHAR  Unicode : 1;
  _ANONYMOUS_UNION union {
    UCHAR  Text[12];
    WCHAR  WText[6];
  } DUMMYUNIONNAME;
  UCHAR  CRC[2];
} CDROM_TOC_CD_TEXT_DATA_BLOCK, *PCDROM_TOC_CD_TEXT_DATA_BLOCK;

typedef struct _CDROM_TOC_CD_TEXT_DATA {
  UCHAR  Length[2];
  UCHAR  Reserved1;
  UCHAR  Reserved2;
  CDROM_TOC_CD_TEXT_DATA_BLOCK  Descriptors[0];
} CDROM_TOC_CD_TEXT_DATA, *PCDROM_TOC_CD_TEXT_DATA;

/* CDROM_TOC_FULL_TOC_DATA_BLOCK.Adr constants */
#define ADR_NO_MODE_INFORMATION           0x0
#define ADR_ENCODES_CURRENT_POSITION      0x1
#define ADR_ENCODES_MEDIA_CATALOG         0x2
#define ADR_ENCODES_ISRC                  0x3

typedef struct _CDROM_TOC_FULL_TOC_DATA_BLOCK {
  UCHAR  SessionNumber;
  UCHAR  Control : 4;
  UCHAR  Adr : 4;
  UCHAR  Reserved1;
  UCHAR  Point;
  UCHAR  MsfExtra[3];
  UCHAR  Zero;
  UCHAR  Msf[3];
} CDROM_TOC_FULL_TOC_DATA_BLOCK, *PCDROM_TOC_FULL_TOC_DATA_BLOCK;

typedef struct _CDROM_TOC_FULL_TOC_DATA {
  UCHAR  Length[2];
  UCHAR  FirstCompleteSession;
  UCHAR  LastCompleteSession;
  CDROM_TOC_FULL_TOC_DATA_BLOCK  Descriptors[0];
} CDROM_TOC_FULL_TOC_DATA, *PCDROM_TOC_FULL_TOC_DATA;

typedef struct _CDROM_TOC_PMA_DATA {
  UCHAR  Length[2];
  UCHAR  Reserved1;
  UCHAR  Reserved2;
  CDROM_TOC_FULL_TOC_DATA_BLOCK  Descriptors[0];
} CDROM_TOC_PMA_DATA, *PCDROM_TOC_PMA_DATA;

/* SUB_Q_HEADER.AudioStatus constants */
#define AUDIO_STATUS_NOT_SUPPORTED  0x00
#define AUDIO_STATUS_IN_PROGRESS    0x11
#define AUDIO_STATUS_PAUSED         0x12
#define AUDIO_STATUS_PLAY_COMPLETE  0x13
#define AUDIO_STATUS_PLAY_ERROR     0x14
#define AUDIO_STATUS_NO_STATUS      0x15

typedef struct _SUB_Q_HEADER {
  UCHAR  Reserved;
  UCHAR  AudioStatus;
  UCHAR  DataLength[2];
} SUB_Q_HEADER, *PSUB_Q_HEADER;

typedef struct _SUB_Q_MEDIA_CATALOG_NUMBER {
  SUB_Q_HEADER  Header;
  UCHAR  FormatCode;
  UCHAR  Reserved[3];
  UCHAR  Reserved1 : 7;
  UCHAR  Mcval :1;
  UCHAR  MediaCatalog[15];
} SUB_Q_MEDIA_CATALOG_NUMBER, *PSUB_Q_MEDIA_CATALOG_NUMBER;

typedef struct _SUB_Q_TRACK_ISRC {
  SUB_Q_HEADER  Header;
  UCHAR  FormatCode;
  UCHAR  Reserved0;
  UCHAR  Track;
  UCHAR  Reserved1;
  UCHAR  Reserved2 : 7;
  UCHAR  Tcval : 1;
  UCHAR  TrackIsrc[15];
} SUB_Q_TRACK_ISRC, *PSUB_Q_TRACK_ISRC;

typedef struct _SUB_Q_CURRENT_POSITION {
  SUB_Q_HEADER  Header;
  UCHAR  FormatCode;
  UCHAR  Control : 4;
  UCHAR  ADR : 4;
  UCHAR  TrackNumber;
  UCHAR  IndexNumber;
  UCHAR  AbsoluteAddress[4];
  UCHAR  TrackRelativeAddress[4];
} SUB_Q_CURRENT_POSITION, *PSUB_Q_CURRENT_POSITION;

typedef union _SUB_Q_CHANNEL_DATA {
  SUB_Q_CURRENT_POSITION  CurrentPosition;
  SUB_Q_MEDIA_CATALOG_NUMBER  MediaCatalog;
  SUB_Q_TRACK_ISRC  TrackIsrc;
} SUB_Q_CHANNEL_DATA, *PSUB_Q_CHANNEL_DATA;

/* CDROM_AUDIO_CONTROL.LbaFormat constants */
#define AUDIO_WITH_PREEMPHASIS            0x1
#define DIGITAL_COPY_PERMITTED            0x2
#define AUDIO_DATA_TRACK                  0x4
#define TWO_FOUR_CHANNEL_AUDIO            0x8

typedef struct _CDROM_AUDIO_CONTROL {
	UCHAR  LbaFormat;
	USHORT  LogicalBlocksPerSecond;
} CDROM_AUDIO_CONTROL, *PCDROM_AUDIO_CONTROL;

typedef struct _VOLUME_CONTROL {
  UCHAR  PortVolume[4];
} VOLUME_CONTROL, *PVOLUME_CONTROL;

typedef enum _TRACK_MODE_TYPE {
	YellowMode2,
	XAForm2,
	CDDA
} TRACK_MODE_TYPE, *PTRACK_MODE_TYPE;

typedef struct __RAW_READ_INFO {
	LARGE_INTEGER  DiskOffset;
	ULONG  SectorCount;
	TRACK_MODE_TYPE  TrackMode;
} RAW_READ_INFO, *PRAW_READ_INFO;

#ifdef __cplusplus
}
#endif

#endif /* __NTDDCDRM_H */
