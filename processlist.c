#include <string.h>
#include "header.h"

UInt32 listStartIndent;
Byte listStartLine;
Byte listDoubleSpace;

void listAppendText(char* buffer) {
  UInt32 len;
  char toOutput[1024];
  if (strlen(outputBuffer) > 0) strcat(outputBuffer," ");
  strcat(outputBuffer, buffer);
  len = lineSize - rightMargin - leftMargin - indent - embedLeft - embedRight;
  if (strlen(outputBuffer) < len)
    return;
  outputLine(split(toOutput, outputBuffer), 0x00);
  if (listStartLine) {
    listStartLine = 0x00;
    indent += 2;
    }
  }

void listFlush(Byte reset) {
  char toOutput[1024];
  while (strlen(outputBuffer) > 0) {
    outputLine(split(toOutput, outputBuffer), 0x00);
    if (listStartLine) {
      if (reset) {
        listStartLine = 0x00;
        indent += 2;
        }
      }
    }
  }

char* processList(char* buffer) {
  UInt32 i;
  char line[1024];
  char tmp[10];
  char listChar;
  Byte done;
  UInt32 count;
  UInt32 space;
  flush();
  listChar = '-';
  buffer += 3;
  count = 1;
  listDoubleSpace = 0x00;
  while (*buffer != 0 && *buffer != ']') {
    if (*buffer == '*') listChar = '*';
    if (*buffer == '1') listChar = '1';
    if (*buffer == '2') listDoubleSpace = 0xff;
    buffer++;
    }
  listStartIndent = indent;
  listStartLine = 0xff;
  done = 0;
  while (!done) {
    if (fgets(line, 1024, infile) != NULL) {
      trim(trimLineEndings(line));
      if (strncasecmp(line,"[LI",3) == 0) {
        if (line[3] != ']') {
          listChar = line[3];
          trim(slideLeft(line,5));
          }
        else {
          trim(slideLeft(line,4));
          }
        if (strlen(outputBuffer) > 0) {
          listFlush(0xff);
          if (listDoubleSpace) outputLine("", 0x00);
          }
        indent = listStartIndent;
        listStartLine = 0xff;
        strcpy(outputBuffer,"  ");
        if (listChar == '1') {
          sprintf(tmp,"%d",count++);
          for (i=0; i<strlen(tmp); i++)
            outputBuffer[i] = tmp[i];
          }
        else
          outputBuffer[0] = listChar;
        strcat(outputBuffer,line);
        }
      else if (strncmp(line,"[-]",3) == 0) {
        listFlush(0x00);
//        listStartLine = 0x00;
        trim(slideLeft(line,3));
        strcpy(outputBuffer," ");
        listAppendText(line);
        }
      else if (strncmp(line,"[=]",3) == 0) {
        listFlush(0x00);
//        listStartLine = 0x00;
        outputLine("",0x00);
        trim(slideLeft(line,3));
        strcpy(outputBuffer," ");
        listAppendText(line);
        }
      else if (strncasecmp(line,"[LE]",4) == 0) done = 0xff;
      else listAppendText(line);
      }
    else done = 0xff;
    }
  listFlush(0xff);
  indent = listStartIndent;
  buffer[0] = 0;
  return buffer;
  }

