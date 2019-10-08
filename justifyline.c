#include <string.h>
#include "header.h"

char* justifyLine(char* line, char mode, UInt32 size) {
  UInt32 i;
  Int32 count;
  Int32 pos;
  if (mode == 'N') return line;
  while (strlen(line) < size) strcat(line," ");
  if (mode == 'L' || mode == 'C' || mode == 'F') {
    while (line[0] == ' ') {
      for (i=0; i<size-1; i++) line[i] = line[i+1];
      line[size-1] = 0;
      }
    }
  if (mode == 'R') {
    while (line[size-1] == ' ') {
      for (i=size-1; i>0; i--) line[i] = line[i-1];
      line[0] = ' ';
      }
    }
  if (mode == 'C') {
    count = 0;
    for (i=0; i<size; i++) if (line[i] != ' ') count = i;
    count = (printSize() / 2) - (count / 2);
    while (count > 0) {
      for (i=size-1; i>0; i--) line[i] = line[i-1];
      line[0] = ' ';
      --count;
      }
    }
  if (mode == 'F') {
    pos = size - 1;
    while (pos > 0 && line[pos] == ' ') pos--;
    while (pos > 0 && line[pos] != ' ') pos--;
    while (line[size-1] == ' ') {
      for (i=size-1; i>pos; i--) line[i] = line[i-1];
      while (pos > 0 && line[pos] == ' ') {
        pos--;
        if (pos == 0) pos = size-1;
        }
      while (pos > 0 && line[pos] != ' ') {
        pos--;
        if (pos == 0) {
          pos = size-1;
          while (pos > 0 && line[pos] == ' ') pos--;
          while (pos > 0 && line[pos] != ' ') pos--;
          }
        }
      }
    }
  return line;
  }
