#include <string.h>
#include "header.h"

char* pad(char* buffer,UInt32 len) {
  while (strlen(buffer) < len) strcat(buffer," ");
  return buffer;
  }
