#include <string.h>
#include "header.h"

char* processEndOfParagraph(char* buffer) {
  flush();
  outputLine("", 0x00);
  paraStart = 0xff;
  return trim(slideLeft(buffer,4));
  }
