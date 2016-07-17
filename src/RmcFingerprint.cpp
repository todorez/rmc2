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

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include "RmcFingerprint.h"

RmcFingerprint::RmcFingerprint(vector<BiosEntry*> *ent) {
  if(ent->size() != NUM_BIOS_ENTRIES)
    ERR("Incorrect number %[%d] of BIOS entries detected", ent->size());
  else
    setBiosEntries(ent);
}

RmcFingerprint::~RmcFingerprint() {
}


void RmcFingerprint::setFp(char* md5_digest) {
  strcpy(fp, md5_digest);
}

void RmcFingerprint::generateFp() {
  unsigned char hash_octal[MD5_DIGEST_LENGTH]; // MD5 digest in octal
  char tmp_hash[MD5_DIGEST_LENGTH * 2] = {0}; // MD5 digest in hex
  char *in_data; // data input into MD5 digest generator
  MD5_CTX ctxt;

  for (int i =0; i < entries.size(); i++) {
    /* in_data contains the input for the MD5 hash generator
     * the current MD5 hash is prepended to the next bios string
     * and used as input itself
     * current MD5 hash + " " + BIOS string */
    in_data = (char *)calloc(strlen(tmp_hash) + 1 +
      entries[i].getValue().length(), sizeof(char));

    strcpy(in_data, tmp_hash);

    if(strlen(in_data) != 0)
      strcat(in_data, " ");

    strcat(in_data, entries[i].getValue().c_str());
    /* generate MD5 digest */
    MD5_Init(&ctxt);
    MD5_Update(&ctxt, in_data, strlen(in_data));
    MD5_Final(hash_octal, &ctxt);
    /* convert the digest from octal to hex */
    for(int j = 0; j < MD5_DIGEST_LENGTH; j++)
      sprintf(&tmp_hash[j*2], "%02x", (unsigned int)hash_octal[j]);
#ifdef DBG
    DEBUG("Data[%d] : %s\n", i, in_data);
    DEBUG("Hash[%d] : %s\n", i, tmp_hash);
#endif
    free(in_data);
  }
  /* the final MD5 has is the fingerprint for these BIOS entries */
  setFp(tmp_hash);
}

string RmcFingerprint::getFingerprint() {
  return fp;
}

void RmcFingerprint::setBiosEntries(vector<BiosEntry*> *ent){
  /* set smbios strings */
  for(int i =0; i < ent->size(); i++)
    entries.push_back((*ent)[i]);

  /* sort the BIOS entries by type in ascending order*/
  sort(entries.begin(), entries.end());

  /* generate fingerprint from BIOS entries */
  generateFp();
}

vector<BiosEntry> RmcFingerprint::getBiosEntries(){
  return entries;
}
