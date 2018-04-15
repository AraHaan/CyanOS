/*
 * Cyanyde OS main kernel include file.
 */
#ifndef KERNEL_KERNEL_H
#ifdef __cplusplus
#define KEXTERN extern "C"
#else
#define KEXTERN extern
#endif
/* version 0.1.0. */
#define KERNEL_VERSION 0x001000

#include "kernel/pages.h"
#include "kernel/thread.h"
#endif
