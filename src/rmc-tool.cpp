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

#include <iostream>
#include "BiosEntry.h"
#include "RmcFingerprint.h"

int main() {
  vector<BiosEntry*> smbios_data;
  /* A few dummy BIOS strings for testing.
   * The corresponding fingerpring for these is :
   * a2881be4463728581e6b9ad909fcd9ae*/
  smbios_data.push_back(new BiosEntry(1, "product_name", "Super Server"));
  smbios_data.push_back(new BiosEntry(4, "product_name", "Intel(R) Xeon(R) CPU E5-2699 v4 @ 2.20GHz"));
  smbios_data.push_back(new BiosEntry(2, "product_name", "X10DAL-i"));

  RmcFingerprint *fp = new RmcFingerprint(&smbios_data);
  vector<BiosEntry> be = fp->getBiosEntries();

  /* free the BIOS entries */
  for (int i =0;i < smbios_data.size(); i++)
    delete(smbios_data[i]);

  INFO("Fingerprint : %s \n", fp->getFingerprint().c_str());
}
