/*

  sha256_internal.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2005 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  information.

*/

#ifndef SHA256_INTERNAL_H
#define SHA256_INTERNAL_H

typedef struct {
    SilcUInt64 length;
    SilcUInt32 state[8];
    SilcUInt32 curlen;
    unsigned char buf[64];
} sha256_state;

int sha256_init(sha256_state * md);
int sha256_process(sha256_state * md, const unsigned char *in, 
		   unsigned long inlen);
int sha256_done(sha256_state * md, unsigned char *hash);
int sha256_compress(SilcUInt32 *state, unsigned char *buf);

#endif /* SHA256_INTERNAL_H */
