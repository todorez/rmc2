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

#ifndef PTR_SMART
#define PTR_SMART

#include <cstddef>

template <class Obj>
class PtrSmart{
  private:
    Obj *ptr;

  public:
    explicit PtrSmart(Obj *p = NULL);
    ~PtrSmart();
    Obj &operator *();
    Obj *operator ->();
};

#include "../PtrSmart.cpp"

#endif
