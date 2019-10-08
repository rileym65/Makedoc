#include <string.h>
#include "header.h"

char* slideLeft(char* buffer,UInt32 len) {
  UInt32 dst;
  dst = 0;
  while ((buffer[dst++] = buffer[len++]) != 0) ;
  return buffer;
  }
