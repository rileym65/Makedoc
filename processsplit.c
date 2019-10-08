#include <string.h>
#include "header.h"

char* processSplit(char* buffer) {
  UInt32 i;
  UInt32 pos;
  UInt32 numFields;
  char line[1024];
  char field1[1024];
  char field2[1024];
  char field3[1024];
  flush();
  trim(slideLeft(buffer,4));
  numFields = 1;
  pos = 0;
  while (*buffer != 0) {
    if (*buffer == '|') {
      switch (numFields) {
        case 1:field1[pos] = 0; break;
        case 2:field2[pos] = 0; break;
        case 3:field3[pos] = 0; break;
        }
      numFields++;
      pos = 0;
      if (numFields == 4) fail("Too many fields in split");
      buffer++;
      }
    else {
      switch (numFields) {
        case 1:field1[pos++] = *buffer++; break;
        case 2:field2[pos++] = *buffer++; break;
        case 3:field3[pos++] = *buffer++; break;
        }
      }
    }
  trim(field1);
  trim(field2);
  trim(field3);
  for (i=0; i<printSize(); i++) line[i] = ' ';
  line[printSize()] = 0;
  for (i=0; i<strlen(field1); i++) line[i] = field1[i];
  if (numFields == 2) {
    pos = printSize() - strlen(field2);
    for (i=0; i<strlen(field2); i++) line[i+pos] = field2[i];
    }
  if (numFields == 3) {
    pos = (printSize() / 2) - (strlen(field2) / 2);
    for (i=0; i<strlen(field2); i++) line[i+pos] = field2[i];
    pos = printSize() - strlen(field3);
    for (i=0; i<strlen(field3); i++) line[i+pos] = field3[i];
    }
  outputLine(line, 0x00);
  buffer[0] = 0;
  return buffer;
  }

