/*

  silcmemory.c

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 1999 - 2006 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/
/* $Id$ */

#include "silc.h"

#ifndef SILC_STACKTRACE

#define SILC_MAX_ALLOC (1024 * 1024L * 1024L)

void *silc_malloc(size_t size)
{
  void *addr;
  if (silc_unlikely(size <= 0 || size >= SILC_MAX_ALLOC)) {
    SILC_LOG_ERROR(("Invalid memory allocation"));
    return NULL;
  }
  addr = malloc(size);
  if (silc_unlikely(!addr))
    SILC_LOG_ERROR(("System out of memory"));
  return addr;
}

void *silc_calloc(size_t items, size_t size)
{
  void *addr;
  if (silc_unlikely(size * items <= 0 || size * items >= SILC_MAX_ALLOC)) {
    SILC_LOG_ERROR(("Invalid memory allocation"));
    return NULL;
  }
  addr = calloc(items, size);
  if (silc_unlikely(!addr))
    SILC_LOG_ERROR(("System out of memory"));
  return addr;
}

void *silc_realloc(void *ptr, size_t size)
{
  void *addr;
  if (silc_unlikely(size <= 0 || size >= SILC_MAX_ALLOC)) {
    SILC_LOG_ERROR(("Invalid memory allocation"));
    return NULL;
  }
  addr = realloc(ptr, size);
  if (silc_unlikely(!addr))
    SILC_LOG_ERROR(("System out of memory"));
  return addr;
}

void silc_free(void *ptr)
{
  free(ptr);
}

void *silc_memdup(const void *ptr, size_t size)
{
  unsigned char *addr;
  addr = silc_malloc(size + 1);
  if (silc_unlikely(!addr)) {
    SILC_LOG_ERROR(("System out of memory"));
    return NULL;
  }
  memcpy((void *)addr, ptr, size);
  addr[size] = '\0';
  return (void *)addr;
}

#endif /* !SILC_STACKTRACE */

/* SilcStack aware routines */

void *silc_smalloc(SilcStack stack, SilcUInt32 size)
{
  return stack ? silc_stack_malloc(stack, size, TRUE) : silc_malloc(size);
}

void *silc_smalloc_ua(SilcStack stack, SilcUInt32 size)
{
  return stack ? silc_stack_malloc(stack, size, FALSE) : silc_malloc(size);
}

void *silc_scalloc(SilcStack stack, SilcUInt32 items, SilcUInt32 size)
{
  unsigned char *addr;

  if (!stack)
    return silc_calloc(items, size);

  addr = silc_stack_malloc(stack, items * size, TRUE);
  if (silc_unlikely(!addr))
    return NULL;
  memset(addr, 0, items * size);
  return (void *)addr;
}

void *silc_srealloc(SilcStack stack, SilcUInt32 old_size,
		    void *ptr, SilcUInt32 size)
{
  return stack ? silc_stack_realloc(stack, old_size, ptr, size, TRUE) :
    silc_realloc(ptr, size);
}

void *silc_srealloc_ua(SilcStack stack, SilcUInt32 old_size,
		       void *ptr, SilcUInt32 size)
{
  return stack ? silc_stack_realloc(stack, old_size, ptr, size, FALSE) :
    silc_realloc(ptr, size);
}

void *silc_smemdup(SilcStack stack, const void *ptr, SilcUInt32 size)
{
  unsigned char *addr;

  if (!stack)
    return silc_memdup(ptr, size);

  addr = silc_stack_malloc(stack, size + 1, TRUE);
  if (silc_unlikely(!addr))
    return NULL;
  memcpy((void *)addr, ptr, size);
  addr[size] = '\0';
  return (void *)addr;
}

char *silc_sstrdup(SilcStack stack, const char *str)
{
  SilcInt32 size = strlen(str);
  char *addr;

  if (!stack)
    return silc_memdup(str, size);

  addr = silc_stack_malloc(stack, size + 1, FALSE);
  if (silc_unlikely(!addr))
    return NULL;
  memcpy((void *)addr, str, size);
  addr[size] = '\0';
  return addr;
}
