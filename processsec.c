#include <string.h>
#include "header.h"

char* processSection(char* buffer) {
  UInt32 i;
  char line[1024];
  flush();
  for (i=0; i< printSize(); i++) line[i] = buffer[1];
  line[printSize()] = 0;
  outputLine(line, 0x00);
  buffer[0] = 0;
  return buffer;
  }
