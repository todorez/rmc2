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

#include "BiosEntry.h"

BiosEntry::BiosEntry(){
  type = -1;
  name = "";
  value = "";
}

BiosEntry::BiosEntry(BiosEntry *ent) {
  type = ent->type;
  name = ent->name;
  value = ent->value;
}

string BiosEntry::getValue() {
  return value;
}

bool BiosEntry::operator < (const BiosEntry& ent) const {
  return (type < ent.type);
}
