/*

  silcsimutil.c

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2000 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.
  
  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#include "silc.h"

#ifdef SILC_SIM			/* SIM support enabled */

static char symname[256];

/* This is used to produce the function names that are then get from
   SIM's. */

char *silc_sim_symname(char *symbol, char *function)
{
  int len1, len2, len3;

  len1 = strlen(symbol);
  len2 = strlen(function);
  len3 = strlen(SILC_SIM_SYMBOL_PREFIX);
  memset(symname, 0, sizeof(symname));
  silc_strncat(symname, sizeof(symname), SILC_SIM_SYMBOL_PREFIX, len3);
  silc_strncat(symname, sizeof(symname), "_", 1);
  silc_strncat(symname, sizeof(symname), symbol, len1);
  silc_strncat(symname, sizeof(symname), "_", 1);
  silc_strncat(symname, sizeof(symname), function, len2);

  return symname;
}

#endif /* SILC_SIM */
