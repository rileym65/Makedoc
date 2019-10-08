#include <string.h>
#include "header.h"

char* processI(char* buffer) {
  char mode;
  UInt32 count;
  buffer += 2;
  mode = ' ';
  count = 0;
  while (*buffer != 0 && *buffer != ']') {
    if (*buffer == '-') mode = '-';
    else if (*buffer == '+') mode = '+';
    else if (*buffer >= '0' && *buffer <= '9')
      count = (count * 10) + (*buffer - '0');
    buffer++;
    }
  if (mode == '-') indent -= count;
  else if (mode == '+') indent += count;
  else indent = count;
  while (*buffer == ']') buffer++;
  buffer = trim(buffer);
  return buffer;
  }
