#include <string.h>
#include "header.h"

char* processCenter(char* buffer) {
  UInt32 i;
  UInt32 len1;
  UInt32 len2;
  char   tmp[1024];
  buffer = trim(slideLeft(buffer,3));
  len1 = (lineSize - rightMargin - leftMargin - indent) / 2;
  len2 = strlen(buffer) / 2;
  strcpy(tmp,"");
  for (i=0; i<len1-len2; i++) strcat(tmp," ");
  strcat(tmp,buffer);
  outputLine(tmp, 0x00);
  buffer[0] = 0;
  return buffer;
  }
