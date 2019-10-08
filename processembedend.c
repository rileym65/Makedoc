#include <stdlib.h>
#include <string.h>
#include "header.h"

char* processEmbedEnd(char* buffer) {
  flush();
  if (embedRight > 0 || embedLeft > 0) {
    while (pageCount < pageLines) outputLine("", 0x00);
    pageCount = 0;
    pageLines = 0;
    }
  embedRight = 0;
  embedLeft = 0;
  buffer[0] = 0;
  return buffer;
  }
