#include <string.h>
#include "header.h"

void init() {
  numFiles = 0;
  leftMargin = 5;
  rightMargin = 5;
  lineSize = 80;
  indent = 0;
  verbose = 0;
  paragraphStart = 2;
  cellPadding = 1;
  embedLeft = 0;
  embedRight = 0;
  embedPadding = 2;
  justify = 'N';
  paraIndent = 2;
  paraStart = 0xff;
#ifdef MINGW
  strcpy(LE,"\r\n");
#else
  strcpy(LE,"\n");
#endif
  }
