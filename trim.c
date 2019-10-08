#include <string.h>
#include "header.h"

char* trim(char* buffer) {
  UInt32 src;
  UInt32 dst;
  UInt32 len;
  dst = 0;
  src = 0;
  while (buffer[src] > 0 && buffer[src] <= 32) src++;
  while ((buffer[dst++] = buffer[src++]) != 0) ;
  len = strlen(buffer);
  while (len > 0 && buffer[len-1] > 0 && buffer[len-1] <= 32) {
    buffer[len-1] = 0;
    len--;
    }
  return buffer;
  }
