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

/*
 * Reference : SMBIOS 2.1 Specification
 * (32-bit) Entry Point structure
 */

#ifndef SMBIOS
#define SMBIOS

struct SMBIOSEntryPoint {
  char AnchorString[4];
  unsigned char Checksum;
  unsigned char Length;
  unsigned char MajorVersion;
  unsigned char MinorVersion;
  unsigned short MaxStructureSize;
  unsigned char Revision;
  char FormattedArea[5];
  char IntermediateAnchorString2[5];
  unsigned char IntermediateChecksum;
  unsigned short TableLength;
  unsigned int TableAddress;
  unsigned short NumberOfStructures;
  unsigned char BCDRevision;
};

struct SMBIOSHeader {
  unsigned char Type;
  unsigned char Length;
  unsigned short Handle;
};

#endif
