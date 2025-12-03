/* Copyright (C) 2019-2025 Free Software Foundation, Inc.

   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2.1 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#include <sysdep.h>
#include <sysdep-vdso.h>

void *
__m68k_read_tp (void)
{
  unsigned long (*vdso_get_thread_area) (void) = GLRO(dl_vdso_get_thread_area);
  if (vdso_get_thread_area != NULL)
    return (void*) INTERNAL_VSYSCALL_CALL (vdso_get_thread_area, 0);

  return (void*) INTERNAL_SYSCALL_CALL (get_thread_area);
}
