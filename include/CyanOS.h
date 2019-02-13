/*
 * CyanOS.h
 * Defines the OS macro that determines
 * this OS’s name upon building c & c++
 * code.
 */
#ifndef CYANOS_H
#define CYANOS_H
#define cyanos
#ifdef WITH_KERNEL
#include "types/kerneltypes.h"
#include "kernel/kernel.h"
#endif
#endif
