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

#ifndef RMC_FP
#define RMC_FP
#include <vector>
#include <openssl/md5.h>
#include "BiosEntry.h"

class RmcFingerprint {
  private:
    vector<BiosEntry> entries; /* vector SMBIOS data entries*/
    char fp[MD5_DIGEST_LENGTH * 2]; /* MD5 fingerprint */
    void generateFp(); /* generates fingeprint from data in entries vector*/
    void setFp(char* md5_digest); /* generates fingeprint from data in entries array*/

  public:
    RmcFingerprint(vector<BiosEntry*> *ent) ;
    ~RmcFingerprint();
    string getFingerprint();
    void setBiosEntries(vector<BiosEntry*> *ent);
    vector<BiosEntry> getBiosEntries();

};
#endif
