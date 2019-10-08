#include <string.h>
#include "header.h"

char* processRM(char* buffer) {
  char mode;
  UInt32 count;
  buffer += 3;
  mode = ' ';
  count = 0;
  while (*buffer != 0 && *buffer != ']') {
    if (*buffer == '-') mode = '-';
    else if (*buffer == '+') mode = '+';
    else if (*buffer >= '0' && *buffer <= '9')
      count = (count * 10) + (*buffer - '0');
    buffer++;
    }
  if (mode == '-') rightMargin -= count;
  else if (mode == '+') rightMargin += count;
  else rightMargin = count;
  while (*buffer == ']') buffer++;
  buffer = trim(buffer);
  return buffer;
  }
