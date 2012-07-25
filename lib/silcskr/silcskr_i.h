/*

  silcskr_i.h

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

#ifndef SILCSKR_I_H
#define SILCSKR_I_H

#ifndef SILCSKR_H
#error "Do not include this header directly"
#endif

/* Internal representation of SilcSKRKey context. */
typedef struct {
  struct SilcSKRKeyStruct key;	           /* Key data */
  SilcInt32 refcnt;			   /* Reference counter */
} *SilcSKRKeyInternal;

/* Key Repository context */
struct SilcSKRObject {
  SilcSchedule scheduler;
  SilcMutex lock;		          /* Repository lock */
  SilcHashTable keys;			  /* All keys in repository */
};

/* Find context */
struct SilcSKRFindStruct {
  SilcHashTable constr;			   /* Search constraints */
};

#endif /* SILCSKR_I_H */
