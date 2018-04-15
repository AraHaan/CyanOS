/*
 * Cyanyde.h
 * Defines the OS macro that determines
 * this OS’s name upon building c & c++
 * code.
 */
#ifndef CYANYDE_H
#define CYANYDE_H
#define cyanyde
#ifdef WITH_KERNEL
#include "kernel/kernel.h"
#endif
#endif
