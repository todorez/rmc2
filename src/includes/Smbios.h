/*
 * Copyright (c) 2016 - 2017 Intel Corporation.
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

#include "Smbios32.h"
#include "Globals.h"

class Smbios {
  private:
    struct SMBIOSEntryPoint EntryPoint;
    bool ChecksumEntryPointStruct(const uint8_t *ep);
  public:
    uint8_t *GetSmbiosEntryPoint();
    void SetEntryPoint(uint8_t *ep);
};
