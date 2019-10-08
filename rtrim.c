#include <string.h>
#include "header.h"

char* rtrim(char* buffer) {
  UInt32 len;
  len = strlen(buffer);
  while (len > 0 && buffer[len-1] > 0 && buffer[len-1] <= 32) {
    buffer[len-1] = 0;
    len--;
    }
  return buffer;
  }
