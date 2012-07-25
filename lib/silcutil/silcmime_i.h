/*

  silcmime_i.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2005 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef SILCMIME_I_H
#define SILCMIME_I_H

#ifndef SILCMIME_H
#error "Do not include this header directly"
#endif

/* MIME context */
struct SilcMimeStruct {
  SilcHashTable fields;
  unsigned char *data;
  SilcUInt32 data_len;
  SilcDList multiparts;
  char *boundary;
  char *multitype;
};

/* MIME assembler */
struct SilcMimeAssemblerStruct {
  SilcHashTable fragments;
};

#endif /* SILCMIME_I_H */
