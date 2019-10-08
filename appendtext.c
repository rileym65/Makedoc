#include <string.h>
#include "header.h"

/* *********************************************************** */
/* ***** This function appends text to the output buffer ***** */
/* ***** If the output buffer length exceeds the line    ***** */
/* ***** length then the line is split and the leftmost  ***** */
/* ***** portion is output                               ***** */
/* *********************************************************** */

void appendText(char* buffer) {
  UInt32 i;
  UInt32 len;
  char toOutput[1024];
  if (strlen(outputBuffer) == 0 && paraStart) {
    for (i=0; i<paraIndent; i++) strcat(outputBuffer," ");
    paraStart = 0x00;
    }
  else if (strlen(outputBuffer) > 0) strcat(outputBuffer," ");
  strcat(outputBuffer, buffer);
  len = lineSize - rightMargin - leftMargin - indent - embedLeft - embedRight;
  if (strlen(outputBuffer) < len)
    return;
  outputLine(split(toOutput, outputBuffer), 0xff);
  }
