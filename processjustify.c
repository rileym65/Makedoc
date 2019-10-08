#include <string.h>
#include "header.h"

char* processJustify(char* buffer) {
  buffer += 2;
  if (*buffer == 'r' || *buffer == 'R') justify = 'R';
  if (*buffer == 'l' || *buffer == 'L') justify = 'L';
  if (*buffer == 'f' || *buffer == 'F') justify = 'F';
  if (*buffer == 'c' || *buffer == 'C') justify = 'C';
  return slideLeft(buffer,4);
  }

