/*
 * winioctl.h
 *
 * Windows IOCTL subsystem declarations and definitions; includes some
 * elements in common with the Windows Device Driver Kit.
 *
 * $Id: winioctl.h,v ed94503bab84 2016/05/04 19:34:24 keithmarshall $
 *
 * Written by Anders Norlander  <anorland@hem2.passagen.se>
 * Copyright (C) 1999-2005, 2009-2011, 2015, MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _WINIOCTL_H
#define _WINIOCTL_H
#pragma GCC system_header

#define __WINIOCTL_H_SOURCED__

#ifndef _WINDOWS_H
/* FIXME: MSDN says that including <windows.h> should suffice to expose
 * the content of this header, but this implementation does not satisfy
 * that requirement.  Furthermore, this implementation cannot itself be
 * included, unless <windows.h>, (or at least the content from those of
 * its subsidiary headers which define Microsoft's peculiar, obfuscated
 * data types), has been included first; enforce this requirement.
 */
#include <windows.h>
#endif

/* This file is required to provide a number of definitions which are
 * duplicated in the Windows DDK headers; retrieve these definitions by
 * selective inclusion from the appropriate DDK header files...
 */
#include <ddk/winddk.h>
#include <ddk/ntdddisk.h>

_BEGIN_C_DECLS

#define HIST_NO_OF_BUCKETS		24
#define HISTOGRAM_BUCKET_SIZE		sizeof(HISTOGRAM_BUCKET)
#define DISK_HISTOGRAM_SIZE		sizeof(DISK_HISTOGRAM)

#define IOCTL_DISK_LOGGING		CTL_CODE(IOCTL_DISK_BASE,10,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_DISK_HISTOGRAM_STRUCTURE	CTL_CODE(IOCTL_DISK_BASE,12,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_DISK_HISTOGRAM_DATA	CTL_CODE(IOCTL_DISK_BASE,13,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_DISK_HISTOGRAM_RESET	CTL_CODE(IOCTL_DISK_BASE,14,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_DISK_REQUEST_STRUCTURE	CTL_CODE(IOCTL_DISK_BASE,15,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_DISK_REQUEST_DATA		CTL_CODE(IOCTL_DISK_BASE,16,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_DISK_UPDATE_PROPERTIES	CTL_CODE(IOCTL_DISK_BASE,0x50,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_DISK_MEDIA_REMOVAL	CTL_CODE(IOCTL_DISK_BASE,0x201,METHOD_BUFFERED,FILE_READ_ACCESS)
#define IOCTL_DISK_EJECT_MEDIA		CTL_CODE(IOCTL_DISK_BASE,0x202,METHOD_BUFFERED,FILE_READ_ACCESS)
#define IOCTL_DISK_LOAD_MEDIA		CTL_CODE(IOCTL_DISK_BASE,0x203,METHOD_BUFFERED,FILE_READ_ACCESS)
#define IOCTL_DISK_RELEASE		CTL_CODE(IOCTL_DISK_BASE,0x205,METHOD_BUFFERED,FILE_READ_ACCESS)
#define IOCTL_DISK_REMOVE_DEVICE	CTL_CODE(IOCTL_DISK_BASE,0x207,METHOD_BUFFERED,FILE_READ_ACCESS)
#define IOCTL_SERIAL_LSRMST_INSERT	CTL_CODE(FILE_DEVICE_SERIAL_PORT,31,METHOD_BUFFERED,FILE_ANY_ACCESS)

/* FIXME: also in ddk/ntddvol.h; should be factored out.
 */
#define IOCTL_VOLUME_BASE   ((ULONG)('V'))
#define IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS CTL_CODE(IOCTL_VOLUME_BASE, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_VOLUME_IS_CLUSTERED	CTL_CODE(IOCTL_VOLUME_BASE, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define FSCTL_LOCK_VOLUME		CTL_CODE(FILE_DEVICE_FILE_SYSTEM,6,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define FSCTL_UNLOCK_VOLUME		CTL_CODE(FILE_DEVICE_FILE_SYSTEM,7,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define FSCTL_DISMOUNT_VOLUME		CTL_CODE(FILE_DEVICE_FILE_SYSTEM,8,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define FSCTL_MOUNT_DBLS_VOLUME		CTL_CODE(FILE_DEVICE_FILE_SYSTEM,13,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define FSCTL_GET_COMPRESSION		CTL_CODE(FILE_DEVICE_FILE_SYSTEM,15,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define FSCTL_SET_COMPRESSION		CTL_CODE(FILE_DEVICE_FILE_SYSTEM,16,METHOD_BUFFERED,FILE_READ_DATA|FILE_WRITE_DATA)
#define FSCTL_READ_COMPRESSION		CTL_CODE(FILE_DEVICE_FILE_SYSTEM,17,METHOD_NEITHER,FILE_READ_DATA)
#define FSCTL_WRITE_COMPRESSION		CTL_CODE(FILE_DEVICE_FILE_SYSTEM,18,METHOD_NEITHER,FILE_WRITE_DATA)
#define FSCTL_GET_NTFS_VOLUME_DATA 	CTL_CODE(FILE_DEVICE_FILE_SYSTEM,25,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define FSCTL_GET_VOLUME_BITMAP 	CTL_CODE(FILE_DEVICE_FILE_SYSTEM,27,METHOD_NEITHER,FILE_ANY_ACCESS)
#define FSCTL_GET_RETRIEVAL_POINTERS 	CTL_CODE(FILE_DEVICE_FILE_SYSTEM,28,METHOD_NEITHER,FILE_ANY_ACCESS)
#define FSCTL_MOVE_FILE 		CTL_CODE(FILE_DEVICE_FILE_SYSTEM,29,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define FSCTL_GET_REPARSE_POINT 	CTL_CODE(FILE_DEVICE_FILE_SYSTEM,42,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define FSCTL_SET_REPARSE_POINT 	CTL_CODE(FILE_DEVICE_FILE_SYSTEM,41,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define FSCTL_DELETE_REPARSE_POINT 	CTL_CODE(FILE_DEVICE_FILE_SYSTEM,43,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define FSCTL_SET_SPARSE		CTL_CODE(FILE_DEVICE_FILE_SYSTEM,49,METHOD_BUFFERED,FILE_SPECIAL_ACCESS)
#define FSCTL_ALLOW_EXTENDED_DASD_IO 	CTL_CODE(FILE_DEVICE_FILE_SYSTEM,32,METHOD_NEITHER,FILE_ANY_ACCESS)

typedef DWORD DEVICE_TYPE;

enum
{ SERIAL_LSRMST_ESCAPE		= 0,
  SERIAL_LSRMST_LSR_DATA	= 1,
  SERIAL_LSRMST_LSR_NODATA	= 2,
  SERIAL_LSRMST_MST		= 3
};

enum
{ DISK_LOGGING_START		= 0,
  DISK_LOGGING_STOP		= 1,
  DISK_LOGGING_DUMP		= 2,
  DISK_BINNING			= 3
};

typedef WORD BAD_TRACK_NUMBER, *PBAD_TRACK_NUMBER;
typedef enum _BIN_TYPES {RequestSize, RequestLocation} BIN_TYPES;

typedef
struct _BIN_RANGE
{ LARGE_INTEGER 		StartValue;
  LARGE_INTEGER 		Length;
} BIN_RANGE, *PBIN_RANGE;

typedef
struct _BIN_COUNT
{ BIN_RANGE			BinRange;
  DWORD 			BinCount;
} BIN_COUNT, *PBIN_COUNT;

typedef
struct _BIN_RESULTS
{ DWORD 			NumberOfBins;
  BIN_COUNT			BinCounts[1];
} BIN_RESULTS, *PBIN_RESULTS;

typedef
struct _DISK_RECORD
{ LARGE_INTEGER 		ByteOffset;
  LARGE_INTEGER 		StartTime;
  LARGE_INTEGER 		EndTime;
  PVOID 			VirtualAddress;
  DWORD 			NumberOfBytes;
  BYTE				DeviceNumber;
  BOOLEAN			ReadRequest;
} DISK_RECORD, *PDISK_RECORD;

typedef
struct _DISK_LOGGING
{ BYTE				Function;
  PVOID 			BufferAddress;
  DWORD 			BufferSize;
} DISK_LOGGING, *PDISK_LOGGING;

typedef
struct DiskQuotaUserInformation
{ LONGLONG			QuotaUsed;
  LONGLONG			QuotaThreshold;
  LONGLONG			QuotaLimit;
} DISKQUOTA_USER_INFORMATION, *PDISKQUOTA_USER_INFORMATION;

typedef
struct _HISTOGRAM_BUCKET
{ DWORD 			Reads;
  DWORD 			Writes;
} HISTOGRAM_BUCKET, *PHISTOGRAM_BUCKET;

typedef
struct _DISK_HISTOGRAM
{ LARGE_INTEGER 		DiskSize;
  LARGE_INTEGER 		Start;
  LARGE_INTEGER 		End;
  LARGE_INTEGER 		Average;
  LARGE_INTEGER 		AverageRead;
  LARGE_INTEGER 		AverageWrite;
  DWORD 			Granularity;
  DWORD 			Size;
  DWORD 			ReadCount;
  DWORD 			WriteCount;
  PHISTOGRAM_BUCKET		Histogram;
} DISK_HISTOGRAM, *PDISK_HISTOGRAM;

typedef
struct _DISK_EXTENT
{ DWORD 			DiskNumber;
  LARGE_INTEGER 		StartingOffset;
  LARGE_INTEGER 		ExtentLength;
} DISK_EXTENT, *PDISK_EXTENT;

typedef
struct _VOLUME_DISK_EXTENTS
{ DWORD 			NumberOfDiskExtents;
  DISK_EXTENT			Extents[1];
} VOLUME_DISK_EXTENTS, *PVOLUME_DISK_EXTENTS;

typedef
struct _DRIVE_LAYOUT_INFORMATION
{ DWORD 			PartitionCount;
  DWORD 			Signature;
  PARTITION_INFORMATION 	PartitionEntry[1];
} DRIVE_LAYOUT_INFORMATION, *PDRIVE_LAYOUT_INFORMATION;

typedef
struct _DRIVE_LAYOUT_INFORMATION_EX
{ DWORD 				PartitionStyle;
  DWORD 				PartitionCount;
  _ANONYMOUS_UNION union
  { DRIVE_LAYOUT_INFORMATION_MBR	  Mbr;
    DRIVE_LAYOUT_INFORMATION_GPT	  Gpt;
  };
  PARTITION_INFORMATION_EX		PartitionEntry[1];
} DRIVE_LAYOUT_INFORMATION_EX, *PDRIVE_LAYOUT_INFORMATION_EX;

typedef struct
{ HANDLE FileHandle;
  LARGE_INTEGER 		StartingVcn;
  LARGE_INTEGER 		StartingLcn;
  DWORD 			ClusterCount;
} MOVE_FILE_DATA, *PMOVE_FILE_DATA;

typedef
struct _PERF_BIN
{ DWORD 			NumberOfBins;
  DWORD 			TypeOfBin;
  BIN_RANGE			BinsRanges[1];
} PERF_BIN, *PPERF_BIN;

typedef
struct _PREVENT_MEDIA_REMOVAL
{ BOOLEAN			PreventMediaRemoval;
} PREVENT_MEDIA_REMOVAL, *PPREVENT_MEDIA_REMOVAL;

typedef
struct RETRIEVAL_POINTERS_BUFFER
{ DWORD 			ExtentCount;
  LARGE_INTEGER 		StartingVcn;
  struct
  { LARGE_INTEGER		  NextVcn;
    LARGE_INTEGER		  Lcn;
  }				Extents[1];
} RETRIEVAL_POINTERS_BUFFER, *PRETRIEVAL_POINTERS_BUFFER;

typedef struct
{ LARGE_INTEGER 		StartingLcn;
} STARTING_LCN_INPUT_BUFFER, *PSTARTING_LCN_INPUT_BUFFER;

typedef struct
{ LARGE_INTEGER 		StartingVcn;
} STARTING_VCN_INPUT_BUFFER, *PSTARTING_VCN_INPUT_BUFFER;

typedef struct
{ LARGE_INTEGER 		StartingLcn;
  LARGE_INTEGER 		BitmapSize;
  BYTE				Buffer[1];
} VOLUME_BITMAP_BUFFER, *PVOLUME_BITMAP_BUFFER;

typedef struct
{ LARGE_INTEGER 		VolumeSerialNumber;
  LARGE_INTEGER 		NumberSectors;
  LARGE_INTEGER 		TotalClusters;
  LARGE_INTEGER 		FreeClusters;
  LARGE_INTEGER 		TotalReserved;
  DWORD 			BytesPerSector;
  DWORD 			BytesPerCluster;
  DWORD 			BytesPerFileRecordSegment;
  DWORD 			ClustersPerFileRecordSegment;
  LARGE_INTEGER 		MftValidDataLength;
  LARGE_INTEGER 		MftStartLcn;
  LARGE_INTEGER 		Mft2StartLcn;
  LARGE_INTEGER 		MftZoneStart;
  LARGE_INTEGER 		MftZoneEnd;
} NTFS_VOLUME_DATA_BUFFER, *PNTFS_VOLUME_DATA_BUFFER;

_END_C_DECLS

#undef __WINIOCTL_H_SOURCED__
#endif  /* _WINIOCTL_H: $RCSfile: winioctl.h,v $: end of file */
