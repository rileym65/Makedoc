#include <string.h>
#include "header.h"

char* processLM(char* buffer) {
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
  if (mode == '-') leftMargin -= count;
  else if (mode == '+') leftMargin += count;
  else leftMargin = count;
  while (*buffer == ']') buffer++;
  buffer = trim(buffer);
  return buffer;
  }
