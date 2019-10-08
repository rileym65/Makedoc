#include <stdlib.h>
#include "header.h"

void cleanup() {
  UInt32 i;
  for (i=0; i<numFiles; i++)
    free(files[i]);
  if (numFiles > 0) free(files);
  }

