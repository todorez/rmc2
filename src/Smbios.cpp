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

#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "Smbios.h"
#include "Smbios32.h"

void Smbios::SetEntryPoint(uint8_t *ep) {
  memcpy(&EntryPoint, ep, sizeof(struct SMBIOSEntryPoint));
};

bool Smbios::ChecksumEntryPointStruct(const uint8_t *ep){
  struct SMBIOSEntryPoint *EntryPoint = (struct SMBIOSEntryPoint *) ep;
  unsigned char checksum = 0, len = EntryPoint->Length;

  for(int i = 0; i < len; i++)
    checksum += ep[i];

  if(!checksum)
    return true;
  else
    return false;
};

/* scan physical memory for SMBIOS Entry Point Table
 * The table should be between 0xF0000 and 0xFFFFF and must be on 16-bit
 * boundary.
 */
uint8_t* Smbios::GetSmbiosEntryPoint() {
  int fd;
  off_t offset;
  void *memmap = NULL;
  uint8_t *mem = NULL, *ep = NULL;
  bool found = false;

  if ((fd = open(MEM_DEV, O_RDONLY)) == -1) {
    ERR("Unable to open /dev/mem : %s\n", strerror(errno));
  }

  if ((mem = (uint8_t *) calloc(1, SMBIOS_TEND - SMBIOS_TBEGIN)) == NULL) {
    close(fd);
    ERR("Unable to allocate memory for SMBIOS table : %s\n", strerror(errno));
  }

  offset = SMBIOS_TBEGIN % sysconf(_SC_PAGESIZE);

  memmap = mmap(NULL, offset + SMBIOS_TEND - SMBIOS_TBEGIN, PROT_READ, MAP_SHARED, fd,
    SMBIOS_TBEGIN - offset);

  if (memmap == MAP_FAILED) {
    close(fd);
    free(mem);
    ERR("Unable to map /dev/mem to memory : %s\n", strerror(errno));
  }
  memcpy(mem, (uint8_t *)memmap + offset, SMBIOS_TEND - SMBIOS_TBEGIN);

  if (munmap(memmap, offset + SMBIOS_TEND - SMBIOS_TBEGIN) == -1) {
    close(fd);
    free(mem);
    ERR("Unable to unmap  memory : %s\n", strerror(errno));
  }

  for(int boundary = 0; boundary < SMBIOS_TEND-SMBIOS_TBEGIN; boundary += 16) {
    if(memcmp(mem + boundary, "_SM_", 4) == 0 ) {
      found = true;
      ep = mem + boundary;
      break;
    }
  }

  if(found) {
    INFO("32-bit SMBIOS entry point found\n");
    if(ChecksumEntryPointStruct(ep)) {
      SetEntryPoint(ep);
      free(mem);
      return ep;
    }
    else
      ERR("Invalid entry point structure checksum\n");
  } else
    ERR("32-bit SMBIOS entry point not found\n");

  return NULL;
};
