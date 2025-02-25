/*
 * ntdddisk.h
 *
 * Disk IOCTL interface.
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

#ifndef __NTDDDISK_H
#define __NTDDDISK_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "ntddk.h"
#include "ntddstor.h"

#define DD_DISK_DEVICE_NAME               "\\Device\\UNKNOWN"
#define DD_DISK_DEVICE_NAME_U             L"\\Device\\UNKNOWN"

#define IOCTL_DISK_BASE                   FILE_DEVICE_DISK

#define IOCTL_DISK_CHECK_VERIFY \
  CTL_CODE(IOCTL_DISK_BASE, 0x0200, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_DISK_CONTROLLER_NUMBER \
  CTL_CODE(IOCTL_DISK_BASE, 0x0011, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_DISK_CREATE_DISK \
  CTL_CODE(IOCTL_DISK_BASE, 0x0016, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_DISK_DELETE_DRIVE_LAYOUT \
  CTL_CODE(IOCTL_DISK_BASE, 0x0040, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_DISK_FIND_NEW_DEVICES \
  CTL_CODE(IOCTL_DISK_BASE, 0x0206, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_DISK_FORMAT_TRACKS \
  CTL_CODE(IOCTL_DISK_BASE, 0x0006, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_DISK_FORMAT_TRACKS_EX \
  CTL_CODE(IOCTL_DISK_BASE, 0x000b, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_DISK_GET_CACHE_INFORMATION \
  CTL_CODE(IOCTL_DISK_BASE, 0x0035, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_DISK_GET_DRIVE_GEOMETRY \
  CTL_CODE(IOCTL_DISK_BASE, 0x0000, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_DISK_GET_DRIVE_GEOMETRY_EX \
  CTL_CODE(IOCTL_DISK_BASE, 0x0028, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_DISK_GET_DRIVE_LAYOUT \
  CTL_CODE(IOCTL_DISK_BASE, 0x0003, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_DISK_GET_DRIVE_LAYOUT_EX \
  CTL_CODE(IOCTL_DISK_BASE, 0x0014, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_DISK_GET_MEDIA_TYPES \
  CTL_CODE(IOCTL_DISK_BASE, 0x0300, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_DISK_GET_LENGTH_INFO \
  CTL_CODE(IOCTL_DISK_BASE, 0x0017, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_DISK_GET_PARTITION_INFO \
  CTL_CODE(IOCTL_DISK_BASE, 0x0001, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_DISK_GET_PARTITION_INFO_EX \
  CTL_CODE(IOCTL_DISK_BASE, 0x0012, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_DISK_GROW_PARTITION \
  CTL_CODE(IOCTL_DISK_BASE, 0x0034, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_DISK_INTERNAL_CLEAR_VERIFY \
  CTL_CODE(IOCTL_DISK_BASE, 0x0101, METHOD_NEITHER, FILE_ANY_ACCESS)

#define IOCTL_DISK_INTERNAL_SET_VERIFY \
  CTL_CODE(IOCTL_DISK_BASE, 0x0100, METHOD_NEITHER, FILE_ANY_ACCESS)

#define IOCTL_DISK_IS_WRITABLE \
  CTL_CODE(IOCTL_DISK_BASE, 0x0009, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_DISK_PERFORMANCE \
  CTL_CODE(IOCTL_DISK_BASE, 0x0008, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_DISK_PERFORMANCE_OFF \
  CTL_CODE(IOCTL_DISK_BASE, 0x0018, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_DISK_REASSIGN_BLOCKS \
  CTL_CODE(IOCTL_DISK_BASE, 0x0007, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_DISK_RESERVE \
  CTL_CODE(IOCTL_DISK_BASE, 0x0204, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_DISK_SET_CACHE_INFORMATION \
  CTL_CODE(IOCTL_DISK_BASE, 0x0036, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_DISK_SET_DRIVE_LAYOUT \
  CTL_CODE(IOCTL_DISK_BASE, 0x0004, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_DISK_SET_DRIVE_LAYOUT_EX \
  CTL_CODE(IOCTL_DISK_BASE, 0x0015, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_DISK_SET_PARTITION_INFO \
  CTL_CODE(IOCTL_DISK_BASE, 0x0002, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_DISK_SET_PARTITION_INFO_EX \
  CTL_CODE(IOCTL_DISK_BASE, 0x0013, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_DISK_UPDATE_DRIVE_SIZE \
  CTL_CODE(IOCTL_DISK_BASE, 0x0032, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_DISK_VERIFY \
  CTL_CODE(IOCTL_DISK_BASE, 0x0005, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define SMART_GET_VERSION \
  CTL_CODE(IOCTL_DISK_BASE, 0x0020, METHOD_BUFFERED, FILE_READ_ACCESS)

#define SMART_RCV_DRIVE_DATA \
  CTL_CODE(IOCTL_DISK_BASE, 0x0022, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define SMART_SEND_DRIVE_COMMAND \
  CTL_CODE(IOCTL_DISK_BASE, 0x0021, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)


#define PARTITION_ENTRY_UNUSED            0x00
#define PARTITION_FAT_12                  0x01
#define PARTITION_XENIX_1                 0x02
#define PARTITION_XENIX_2                 0x03
#define PARTITION_FAT_16                  0x04
#define PARTITION_EXTENDED                0x05
#define PARTITION_HUGE                    0x06
#define PARTITION_IFS                     0x07
#define PARTITION_OS2BOOTMGR              0x0A
#define PARTITION_FAT32                   0x0B
#define PARTITION_FAT32_XINT13            0x0C
#define PARTITION_XINT13                  0x0E
#define PARTITION_XINT13_EXTENDED         0x0F
#define PARTITION_PREP                    0x41
#define PARTITION_LDM                     0x42
#define PARTITION_UNIX                    0x63
#define VALID_NTFT                        0xC0
#define PARTITION_NTFT                    0x80

#define IsFTPartition( PartitionType ) \
  (((PartitionType) & PARTITION_NTFT) && \
  IsRecognizedPartition(PartitionType))

#define IsContainerPartition(PartitionType) \
  (((PartitionType) == PARTITION_EXTENDED) || \
  ((PartitionType) == PARTITION_XINT13_EXTENDED))

#define IsRecognizedPartition(PartitionType) ( \
	(((PartitionType) & PARTITION_NTFT) && (((PartitionType) & ~0xC0) == PARTITION_FAT_12)) || \
	(((PartitionType) & PARTITION_NTFT) && (((PartitionType) & ~0xC0) == PARTITION_HUGE)) || \
	(((PartitionType) & PARTITION_NTFT) && (((PartitionType) & ~0xC0) == PARTITION_IFS)) || \
	(((PartitionType) & PARTITION_NTFT) && (((PartitionType) & ~0xC0) == PARTITION_FAT32)) || \
	(((PartitionType) & PARTITION_NTFT) && (((PartitionType) & ~0xC0) == PARTITION_FAT32_XINT13)) || \
	(((PartitionType) & PARTITION_NTFT) && (((PartitionType) & ~0xC0) == PARTITION_XINT13)) || \
	((PartitionType) == PARTITION_FAT_12) || \
	((PartitionType) == PARTITION_FAT_16) || \
	((PartitionType) == PARTITION_HUGE) || \
	((PartitionType) == PARTITION_IFS) || \
	((PartitionType) == PARTITION_FAT32) || \
	((PartitionType) == PARTITION_FAT32_XINT13) || \
	((PartitionType) == PARTITION_XINT13))

#define WMI_DISK_GEOMETRY_GUID \
  {0x25007f51, 0x57c2, 0x11d1, {0xa5, 0x28, 0x0, 0xa0, 0xc9, 0x6, 0x29, 0x10}}

typedef USHORT BAD_TRACK_NUMBER;
typedef USHORT *PBAD_TRACK_NUMBER;

typedef enum _MEDIA_TYPE {
  Unknown,
  F5_1Pt2_512,
  F3_1Pt44_512,
  F3_2Pt88_512,
  F3_20Pt8_512,
  F3_720_512,
  F5_360_512,
  F5_320_512,
  F5_320_1024,
  F5_180_512,
  F5_160_512,
  RemovableMedia,
  FixedMedia,
  F3_120M_512,
  F3_640_512,
  F5_640_512,
  F5_720_512,
  F3_1Pt2_512,
  F3_1Pt23_1024,
  F5_1Pt23_1024,
  F3_128Mb_512,
  F3_230Mb_512,
  F8_256_128
} MEDIA_TYPE, *PMEDIA_TYPE;

typedef enum _DETECTION_TYPE {
  DetectNone,
  DetectInt13,
  DetectExInt13
} DETECTION_TYPE;

typedef struct _DISK_CONTROLLER_NUMBER {
  ULONG  ControllerNumber;
  ULONG  DiskNumber;
} DISK_CONTROLLER_NUMBER, *PDISK_CONTROLLER_NUMBER;

typedef struct _DISK_INT13_INFO {
  USHORT  DriveSelect;
  ULONG  MaxCylinders;
  USHORT  SectorsPerTrack;
  USHORT  MaxHeads;
  USHORT  NumberDrives;
} DISK_INT13_INFO, *PDISK_INT13_INFO;

typedef struct _DISK_EX_INT13_INFO {
  USHORT  ExBufferSize;
  USHORT  ExFlags;
  ULONG  ExCylinders;
  ULONG  ExHeads;
  ULONG  ExSectorsPerTrack;
  ULONG64  ExSectorsPerDrive;
  USHORT  ExSectorSize;
  USHORT  ExReserved;
} DISK_EX_INT13_INFO, *PDISK_EX_INT13_INFO;

typedef struct _DISK_DETECTION_INFO {
  ULONG  SizeOfDetectInfo;
  DETECTION_TYPE  DetectionType;
  _ANONYMOUS_UNION union {
    _ANONYMOUS_STRUCT struct {
      DISK_INT13_INFO  Int13;
      DISK_EX_INT13_INFO  ExInt13;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
} DISK_DETECTION_INFO, *PDISK_DETECTION_INFO;

typedef struct _DISK_GEOMETRY {
  LARGE_INTEGER  Cylinders;
  MEDIA_TYPE  MediaType;
  ULONG  TracksPerCylinder;
  ULONG  SectorsPerTrack;
  ULONG  BytesPerSector;
} DISK_GEOMETRY, *PDISK_GEOMETRY;

typedef struct _DISK_GEOMETRY_EX {
  DISK_GEOMETRY  Geometry;
  LARGE_INTEGER  DiskSize;
  UCHAR  Data[1];
} DISK_GEOMETRY_EX, *PDISK_GEOMETRY_EX;

#define DiskGeometryGetPartition(Geometry) \
   ((PDISK_PARTITION_INFO)((Geometry) + 1))

#define DiskGeometryGetDetect(Geometry)\
 ((PDISK_DETECTION_INFO)(((PBYTE)DiskGeometryGetPartition(Geometry) + \
  DiskGeometryGetPartition(Geometry)->SizeOfPartitionInfo)))

typedef struct _PARTITION_INFORMATION {
  LARGE_INTEGER  StartingOffset;
  LARGE_INTEGER  PartitionLength;
  DWORD  HiddenSectors;
  DWORD  PartitionNumber;
  BYTE  PartitionType;
  BOOLEAN  BootIndicator;
  BOOLEAN  RecognizedPartition;
  BOOLEAN  RewritePartition;
} PARTITION_INFORMATION, *PPARTITION_INFORMATION;

typedef struct _PARTITION_INFORMATION_GPT {
  GUID  PartitionType;
  GUID  PartitionId;
  ULONG64  Attributes;
  WCHAR Name  [36];
} PARTITION_INFORMATION_GPT, *PPARTITION_INFORMATION_GPT;

typedef struct _DISK_PARTITION_INFO {
  ULONG  SizeOfPartitionInfo;
  PARTITION_STYLE  PartitionStyle;
  _ANONYMOUS_UNION union {
    struct {
      ULONG  Signature;
      ULONG  CheckSum;
    } Mbr;
    struct {
      GUID  DiskId;
    } Gpt;
  } DUMMYUNIONNAME;
} DISK_PARTITION_INFO, *PDISK_PARTITION_INFO;

typedef struct _DISK_PERFORMANCE {
  LARGE_INTEGER  BytesRead;
  LARGE_INTEGER  BytesWritten;
  LARGE_INTEGER  ReadTime;
  LARGE_INTEGER  WriteTime;
  LARGE_INTEGER  IdleTime;
  ULONG  ReadCount;
  ULONG  WriteCount;
  ULONG  QueueDepth;
  ULONG  SplitCount;
  LARGE_INTEGER  QueryTime;
  ULONG  StorageDeviceNumber;
  WCHAR  StorageManagerName[8];
} DISK_PERFORMANCE, *PDISK_PERFORMANCE;

typedef struct _PARTITION_INFORMATION_EX {
  PARTITION_STYLE  PartitionStyle;
  LARGE_INTEGER  StartingOffset;
  LARGE_INTEGER  PartitionLength;
  ULONG  PartitionNumber;
  BOOLEAN  RewritePartition;
  _ANONYMOUS_UNION union {
    PARTITION_INFORMATION_MBR  Mbr;
    PARTITION_INFORMATION_GPT  Gpt;
  } DUMMYUNIONNAME;
} PARTITION_INFORMATION_EX, *PPARTITION_INFORMATION_EX;

typedef struct _FORMAT_EX_PARAMETERS {
  MEDIA_TYPE  MediaType;
  ULONG  StartCylinderNumber;
  ULONG  EndCylinderNumber;
  ULONG  StartHeadNumber;
  ULONG  EndHeadNumber;
  USHORT  FormatGapLength;
  USHORT  SectorsPerTrack;
  USHORT  SectorNumber[1];
} FORMAT_EX_PARAMETERS, *PFORMAT_EX_PARAMETERS;

typedef struct _FORMAT_PARAMETERS {
  MEDIA_TYPE  MediaType;
  ULONG  StartCylinderNumber;
  ULONG  EndCylinderNumber;
  ULONG  StartHeadNumber;
  ULONG  EndHeadNumber;
} FORMAT_PARAMETERS, *PFORMAT_PARAMETERS;

typedef struct _GET_LENGTH_INFORMATION {
  LARGE_INTEGER  Length;
} GET_LENGTH_INFORMATION, *PGET_LENGTH_INFORMATION;

typedef struct _REASSIGN_BLOCKS {
  WORD  Reserved;
  WORD  Count;
  DWORD  BlockNumber[1];
} REASSIGN_BLOCKS, *PREASSIGN_BLOCKS;

typedef struct _SET_PARTITION_INFORMATION {
  UCHAR  PartitionType;
} SET_PARTITION_INFORMATION, *PSET_PARTITION_INFORMATION;

typedef SET_PARTITION_INFORMATION SET_PARTITION_INFORMATION_MBR;
typedef PARTITION_INFORMATION_GPT SET_PARTITION_INFORMATION_GPT;

typedef struct _SET_PARTITION_INFORMATION_EX {
  PARTITION_STYLE  PartitionStyle;
  _ANONYMOUS_UNION union {
    SET_PARTITION_INFORMATION_MBR  Mbr;
    SET_PARTITION_INFORMATION_GPT  Gpt;
  } DUMMYUNIONNAME;
} SET_PARTITION_INFORMATION_EX, *PSET_PARTITION_INFORMATION_EX;

typedef struct _VERIFY_INFORMATION {
  LARGE_INTEGER  StartingOffset;
  DWORD  Length;
} VERIFY_INFORMATION, *PVERIFY_INFORMATION;

typedef enum {
	EqualPriority,
	KeepPrefetchedData,
	KeepReadData
} DISK_CACHE_RETENTION_PRIORITY;

typedef struct _DISK_CACHE_INFORMATION {
	BOOLEAN  ParametersSavable;
	BOOLEAN  ReadCacheEnabled;
	BOOLEAN  WriteCacheEnabled;
	DISK_CACHE_RETENTION_PRIORITY  ReadRetentionPriority;
	DISK_CACHE_RETENTION_PRIORITY  WriteRetentionPriority;
	USHORT  DisablePrefetchTransferLength;
	BOOLEAN  PrefetchScalar;
	_ANONYMOUS_UNION union {
		struct {
			USHORT  Minimum;
			USHORT  Maximum;
			USHORT  MaximumBlocks;
		} ScalarPrefetch;
		struct {
			USHORT  Minimum;
			USHORT  Maximum;
		} BlockPrefetch;
	} DUMMYUNIONNAME;
} DISK_CACHE_INFORMATION, *PDISK_CACHE_INFORMATION;

typedef struct _DISK_GROW_PARTITION {
  ULONG  PartitionNumber;
  LARGE_INTEGER  BytesToGrow;
} DISK_GROW_PARTITION, *PDISK_GROW_PARTITION;

/* GETVERSIONINPARAMS.fCapabilities constants */
#define CAP_ATA_ID_CMD                    1
#define CAP_ATAPI_ID_CMD                  2
#define CAP_SMART_CMD                     4

typedef struct _GETVERSIONINPARAMS {
	UCHAR  bVersion;
	UCHAR  bRevision;
	UCHAR  bReserved;
	UCHAR  bIDEDeviceMap;
	ULONG  fCapabilities;
	ULONG  dwReserved[4];
} GETVERSIONINPARAMS, *PGETVERSIONINPARAMS, *LPGETVERSIONINPARAMS;

/* IDEREGS.bCommandReg constants */
#define ATAPI_ID_CMD                      0xA1
#define ID_CMD                            0xEC
#define SMART_CMD                         0xB0

#define SMART_CYL_LOW                     0x4F
#define SMART_CYL_HI                      0xC2

typedef struct _IDEREGS {
	UCHAR  bFeaturesReg;
	UCHAR  bSectorCountReg;
	UCHAR  bSectorNumberReg;
	UCHAR  bCylLowReg;
	UCHAR  bCylHighReg;
	UCHAR  bDriveHeadReg;
	UCHAR  bCommandReg;
	UCHAR  bReserved;
} IDEREGS, *PIDEREGS, *LPIDEREGS;

#include <pshpack1.h>
typedef struct _SENDCMDINPARAMS {
	ULONG  cBufferSize;
	IDEREGS  irDriveRegs;
	UCHAR  bDriveNumber;
	UCHAR  bReserved[3];
	ULONG  dwReserved[4];
	UCHAR  bBuffer[1];
} SENDCMDINPARAMS, *PSENDCMDINPARAMS, *LPSENDCMDINPARAMS;
#include <poppack.h>

/* DRIVERSTATUS.bDriverError constants */
#define SMART_NO_ERROR                    0
#define SMART_IDE_ERROR                   1
#define SMART_INVALID_FLAG                2
#define SMART_INVALID_COMMAND             3
#define SMART_INVALID_BUFFER              4
#define SMART_INVALID_DRIVE               5
#define SMART_INVALID_IOCTL               6
#define SMART_ERROR_NO_MEM                7
#define SMART_INVALID_REGISTER            8
#define SMART_NOT_SUPPORTED               9
#define SMART_NO_IDE_DEVICE               10

#define SMART_OFFLINE_ROUTINE_OFFLINE     0
#define SMART_SHORT_SELFTEST_OFFLINE      1
#define SMART_EXTENDED_SELFTEST_OFFLINE   2
#define SMART_ABORT_OFFLINE_SELFTEST      127
#define SMART_SHORT_SELFTEST_CAPTIVE      129
#define SMART_EXTENDED_SELFTEST_CAPTIVE   130

typedef struct _DRIVERSTATUS {
	UCHAR  bDriverError;
	UCHAR  bIDEError;
	UCHAR  bReserved[2];
	ULONG  dwReserved[2];
} DRIVERSTATUS, *PDRIVERSTATUS, *LPDRIVERSTATUS;

#define READ_ATTRIBUTE_BUFFER_SIZE        512
#define IDENTIFY_BUFFER_SIZE              512
#define READ_THRESHOLD_BUFFER_SIZE        512
#define SMART_LOG_SECTOR_SIZE             512

#include <pshpack1.h>
typedef struct _SENDCMDOUTPARAMS {
	ULONG  cBufferSize;
	DRIVERSTATUS  DriverStatus;
	UCHAR  bBuffer[1];
} SENDCMDOUTPARAMS, *PSENDCMDOUTPARAMS, *LPSENDCMDOUTPARAMS;
#include <poppack.h>

#define READ_ATTRIBUTES                   0xD0
#define READ_THRESHOLDS                   0xD1
#define ENABLE_DISABLE_AUTOSAVE           0xD2
#define SAVE_ATTRIBUTE_VALUES             0xD3
#define EXECUTE_OFFLINE_DIAGS             0xD4
#define SMART_READ_LOG                    0xD5
#define SMART_WRITE_LOG                   0xd6
#define ENABLE_SMART                      0xD8
#define DISABLE_SMART                     0xD9
#define RETURN_SMART_STATUS               0xDA
#define ENABLE_DISABLE_AUTO_OFFLINE       0xDB

#ifdef __cplusplus
}
#endif

#endif /* __NTDDDISK_H */
