/*
 * Copyright (C) 2017 Intel Corporation
 *
 * Author: Todor Minchev <todor.minchev@linux.intel.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, or (at your option) any later version, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 */

#include <stdarg.h>
#include <stdint.h>

#ifndef GLOBALS_H
#define GLOBALS_H

#define MEM_DEV "/dev/mem"
#define SMBIOS_TBEGIN 0xF0000 /* starting address for SMBIOS entry point scan */
#define SMBIOS_TEND 0xFFFFF   /* ending address for SMBIOS entry point scan */


#define NUM_BIOS_ENTRIES 3

void info(const char* fmt, ...);
void debug(const char* fmt, ...);
void error(const char *file, int line, const char *func, const char* fmt, ...);

#define INFO(...)  info(__VA_ARGS__)
#define ERR(...) error(__FILE__, __LINE__, __func__, __VA_ARGS__)
#define DEBUG(...) debug(__VA_ARGS__)

#endif
