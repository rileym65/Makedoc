#include <string.h>
#include "header.h"

char* processText(char* buffer) {
  buffer = trim(slideLeft(buffer,2));
  appendText(buffer);
  buffer[0] = 0;
  return buffer;
  }
