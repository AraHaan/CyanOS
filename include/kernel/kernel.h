/*
 * CyanOS main kernel include file.
 */
#ifndef KERNEL_KERNEL_H
#ifdef __cplusplus
#define KEXTERN extern "C"
#ifdef KERNEL_BUILD
#include "gdt.h"
#include "hardwarecommunication/port.h"
#include "hardwarecommunication/interupts.h"
#include "drivers/driver.h"
#include "drivers/keyboard.h"
#include "drivers/mouse.h"
#include "hardwarecommunication/pci.h"
#endif
#else
#define KEXTERN extern
#endif
/* version 0.1.0. */
#define KERNEL_VERSION 0x001000

#endif
