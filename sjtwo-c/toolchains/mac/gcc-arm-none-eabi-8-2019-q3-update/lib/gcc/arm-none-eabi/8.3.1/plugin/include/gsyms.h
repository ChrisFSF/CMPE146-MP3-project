/* Copyright (C) 1992-2018 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/* For cross compilation, use the portable definitions from the COFF
   documentation.  */
#ifndef GCC_GSYMS_H
#define GCC_GSYMS_H

#define __GNU_SYMS__

enum sdb_storage_class
{
  C_EFCN = -1,
  C_NULL = 0,
  C_AUTO = 1,
  C_EXT = 2,
  C_STAT = 3,
  C_REG = 4,
  C_EXTDEF = 5,
  C_LABEL = 6,
  C_ULABEL = 7,
  C_MOS = 8,
  C_ARG = 9,
  C_STRTAG = 10,
  C_MOU = 11,
  C_UNTAG = 12,
  C_TPDEF = 13,
  C_USTATIC = 14,
  C_ENTAG = 15,
  C_MOE = 16,
  C_REGPARM = 17,
  C_FIELD = 18,

  C_BLOCK = 100,
  C_FCN = 101,
  C_EOS = 102,
  C_FILE = 103,
  C_LINE = 104,
  C_ALIAS = 105,
  C_HIDDEN = 106
};

enum sdb_type
{
  T_NULL = 0,
  T_ARG = 1,
  T_VOID = 1,
  T_CHAR = 2,
  T_SHORT = 3,
  T_INT = 4,
  T_LONG = 5,
  T_FLOAT = 6,
  T_DOUBLE = 7,
  T_STRUCT = 8,
  T_UNION = 9,
  T_ENUM = 10,
  T_MOE = 11,
  T_UCHAR = 12,
  T_USHORT = 13,
  T_UINT = 14,
  T_ULONG = 15
};

enum sdb_type_class
{
  DT_NON = 0,
  DT_PTR = 1,
  DT_FCN = 2,
  DT_ARY = 3
};

enum sdb_masks
{
  N_BTMASK = 017,
  N_TMASK = 060,
  N_TMASK1 = 0300,
  N_TMASK2 = 0360,
  N_BTSHFT = 4,
  N_TSHIFT = 2
};

#endif /* GCC_GSYMS_H */
