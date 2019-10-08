#include <string.h>
#include "header.h"

char* processHeader(char* buffer) {
  UInt32 i;
  UInt32 len;
  char mode;
  char tmp[1024];
  mode = '-';
  if (buffer[2] == '2') mode = '=';
  if (buffer[2] == '1') mode = '-';
  if (buffer[2] == '=') mode = '=';
  if (buffer[2] == '-') mode = '-';
  buffer = trim(slideLeft(buffer,4));
  len = strlen(buffer);
  outputLine(buffer, 0x00);
  for (i=0; i<len; i++) tmp[i] = mode;
  tmp[len] = 0;
  outputLine(tmp, 0x00);
  buffer[0] = 0;
  return buffer;
  }
