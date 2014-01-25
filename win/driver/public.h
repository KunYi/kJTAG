/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

Module Name:

    BulkUsr.h

Abstract:

Environment:

    User & Kernel mode

--*/

#ifndef _USER_H
#define _USER_H

#include <initguid.h>

// {9FAECCF4-2752-4bb0-8E76-61ED781BB2E5}
DEFINE_GUID(GUID_CLASS_MYUSBBULK_USB, 
0x9faeccf4, 0x2752, 0x4bb0, 0x8e, 0x76, 0x61, 0xed, 0x78, 0x1b, 0xb2, 0xe5);


#define IOCTL_INDEX             0x0000


#define IOCTL_KJTAG_GET_CONFIG_DESCRIPTOR CTL_CODE(FILE_DEVICE_UNKNOWN,     \
                                                     IOCTL_INDEX,     \
                                                     METHOD_BUFFERED,         \
                                                     FILE_ANY_ACCESS)
                                                   
#define IOCTL_KJTAG_RESET_DEVICE          CTL_CODE(FILE_DEVICE_UNKNOWN,     \
                                                     IOCTL_INDEX + 1, \
                                                     METHOD_BUFFERED,         \
                                                     FILE_ANY_ACCESS)

#define IOCTL_KJTAG_RESET_PIPE            CTL_CODE(FILE_DEVICE_UNKNOWN,     \
                                                     IOCTL_INDEX + 2, \
                                                     METHOD_BUFFERED,         \
                                                     FILE_ANY_ACCESS)

#endif

