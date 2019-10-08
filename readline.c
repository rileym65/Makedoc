#include <stdio.h>
#include "header.h"

char* readLine(char* dest, UInt32 maxlen) {
  if (fgets(dest, maxlen, infile) != NULL) {
    trim(trimLineEndings(dest));
    lineCount++;
    return dest;
    }
  return NULL;
  }
 

