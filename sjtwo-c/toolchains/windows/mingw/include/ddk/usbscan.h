/*
 * usbscan.h
 *
 * USB scanner definitions
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

#ifndef __USBSCAN_H
#define __USBSCAN_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "ntddk.h"

#define FILE_DEVICE_USB_SCAN              0x8000
#define IOCTL_INDEX                       0x0800

#define IOCTL_CANCEL_IO \
  CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 1, METHOD_BUFFERED,FILE_ANY_ACCESS)

#define IOCTL_GET_VERSION \
  CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 0, METHOD_BUFFERED,FILE_ANY_ACCESS)

#define IOCTL_GET_CHANNEL_ALIGN_RQST \
  CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 5, METHOD_BUFFERED,FILE_ANY_ACCESS)

#define IOCTL_GET_DEVICE_DESCRIPTOR \
  CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 6, METHOD_BUFFERED,FILE_ANY_ACCESS)

#define IOCTL_GET_PIPE_CONFIGURATION \
  CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 10,METHOD_BUFFERED,FILE_ANY_ACCESS)

#define IOCTL_GET_USB_DESCRIPTOR \
  CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 8, METHOD_BUFFERED,FILE_ANY_ACCESS)

#define IOCTL_READ_REGISTERS \
  CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 3, METHOD_BUFFERED,FILE_ANY_ACCESS)

#define IOCTL_RESET_PIPE \
  CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 7, METHOD_BUFFERED,FILE_ANY_ACCESS)

#define IOCTL_SEND_USB_REQUEST \
  CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 9, METHOD_BUFFERED,FILE_ANY_ACCESS)

#define IOCTL_SET_TIMEOUT \
  CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 11,METHOD_BUFFERED,FILE_ANY_ACCESS)

#define IOCTL_WAIT_ON_DEVICE_EVENT \
  CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 2, METHOD_BUFFERED,FILE_ANY_ACCESS)

#define IOCTL_WRITE_REGISTERS \
  CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 4, METHOD_BUFFERED, FILE_ANY_ACCESS)


#define MAX_NUM_PIPES                     8

#define BULKIN_FLAG                       0x80

typedef struct _CHANNEL_INFO {
  /*OUT*/ ULONG  EventChannelSize;
  /*OUT*/ ULONG  uReadDataAlignment;
  /*OUT*/ ULONG  uWriteDataAlignment;
}CHANNEL_INFO, *PCHANNEL_INFO;

typedef struct _DEVICE_DESCRIPTOR {
  /*OUT*/ USHORT  usVendorId;
  /*OUT*/ USHORT  usProductId;
  /*OUT*/ USHORT  usBcdDevice;
  /*OUT*/ USHORT  usLanguageId;
} DEVICE_DESCRIPTOR, *PDEVICE_DESCRIPTOR;

typedef struct _DRV_VERSION {
  /*OUT*/ ULONG  major;
  /*OUT*/ ULONG  minor;
  /*OUT*/ ULONG  internal;
} DRV_VERSION, *PDRV_VERSION;

typedef struct _IO_BLOCK {
  /*IN*/ ULONG  uOffset;
  /*IN*/ ULONG  uLength;
  /*IN OUT*/ PUCHAR  pbyData;
  /*IN*/ ULONG  uIndex;
} IO_BLOCK, *PIO_BLOCK;

typedef struct _IO_BLOCK_EX {
  /*IN*/ ULONG  uOffset;
  /*IN*/ ULONG  uLength;
  /*IN OUT*/ PUCHAR  pbyData;
  /*IN*/ ULONG  uIndex;
  /*IN*/ UCHAR  bRequest;
  /*IN*/ UCHAR  bmRequestType;
  /*IN*/ UCHAR  fTransferDirectionIn;
} IO_BLOCK_EX, *PIO_BLOCK_EX;

typedef struct _USBSCAN_GET_DESCRIPTOR {
  /*IN*/ UCHAR  DescriptorType;
  /*IN*/ UCHAR  Index;
  /*IN*/ USHORT  LanguageId;
} USBSCAN_GET_DESCRIPTOR, *PUSBSCAN_GET_DESCRIPTOR;

typedef enum _RAW_PIPE_TYPE {
	USBSCAN_PIPE_CONTROL,
	USBSCAN_PIPE_ISOCHRONOUS,
	USBSCAN_PIPE_BULK,
	USBSCAN_PIPE_INTERRUPT
} RAW_PIPE_TYPE;

typedef struct _USBSCAN_PIPE_INFORMATION {
  USHORT  MaximumPacketSize;
  UCHAR  EndpointAddress;
  UCHAR  Interval;
  RAW_PIPE_TYPE  PipeType;
} USBSCAN_PIPE_INFORMATION, *PUSBSCAN_PIPE_INFORMATION;

typedef struct _USBSCAN_PIPE_CONFIGURATION {
  /*OUT*/ ULONG  NumberOfPipes;
  /*OUT*/ USBSCAN_PIPE_INFORMATION  PipeInfo[MAX_NUM_PIPES];
} USBSCAN_PIPE_CONFIGURATION, *PUSBSCAN_PIPE_CONFIGURATION;

typedef struct _USBSCAN_TIMEOUT {
  /*IN*/ ULONG  TimeoutRead;
  /*IN*/ ULONG  TimeoutWrite;
  /*IN*/ ULONG  TimeoutEvent;
} USBSCAN_TIMEOUT, *PUSBSCAN_TIMEOUT;

typedef enum _PIPE_TYPE {
	EVENT_PIPE,
	READ_DATA_PIPE,
	WRITE_DATA_PIPE,
	ALL_PIPE
} PIPE_TYPE;

#ifdef __cplusplus
}
#endif

#endif /* __USBSCAN_H */
