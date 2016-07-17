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

#ifndef BIOS_ENTRY
#define BIOS_ENTRY

#include <string>
#include "globals.h"
using namespace std;

class BiosEntry {
  private:
    int type;
    string name;
    string value;

  public:
    BiosEntry ();
    BiosEntry (BiosEntry *ent);
    BiosEntry (const int t, const string n, const string v)
      : type( t ), name( n ), value( v ){};
    string getValue();
    bool operator < (const BiosEntry& ent) const;
};
#endif
