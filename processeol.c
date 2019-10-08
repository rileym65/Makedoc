#include <string.h>
#include "header.h"

char* processEndOfLine(char* buffer) {
  flush();
  return trim(slideLeft(buffer,4));
  }

