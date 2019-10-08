#include <string.h>
#include "header.h"

char* slideRight(char* buffer,UInt32 len) {
  Int32 dst;
  Int32 src;
  dst = strlen(buffer) - 1;
  src = dst - len;
  while (src >= 0) buffer[dst--] = buffer[src--];
  while (dst >= 0) buffer[dst--] = ' ';
  return buffer;
  }
