#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

char* processEmbedded(char* buffer) {
  UInt32 i;
  UInt32 j;
  UInt32 pos;
  char line[1024];
  char** image;
  UInt32 numLines;
  UInt32 width;
  UInt32 len;
  char mode;
  Byte done;
  flush();

  /* ************************************ */
  /* ***** Process embedded options ***** */
  /* ************************************ */
  buffer += 2;
  mode = 'l';
  while (*buffer != 0 && *buffer != ']') {
    if (*buffer == 'r' || *buffer == 'R') mode = 'r';
    if (*buffer == 'l' || *buffer == 'L') mode = 'l';
    buffer++;
    }

  /* ******************************* */
  /* ***** Read embedded image ***** */
  /* ******************************* */
  numLines = 0;
  width = 0;
  image = NULL;
  done = 0;
  while (!done) {
    if (fgets(line, 1024, infile) != NULL) {
      trim(trimLineEndings(line));
      if (strncasecmp(line,"[EE]",4) == 0) {
        done = 0xff;
        }
      else {
        if (++numLines == 1) 
          image = (char**)malloc(sizeof(char*));
        else
          image = (char**)realloc(image,sizeof(char*) * numLines);
        if (image == NULL) fail("Could not allocat memory");
        image[numLines-1] = (char*)malloc(strlen(line) + 1);
        strcpy(image[numLines-1], line);
        if (strlen(line) > width) width = strlen(line);
        }
      }
    else done = 0xff;
    }

  /* ******************************* */
  /* ***** Create a blank page ***** */
  /* ******************************* */
  pageLines = 0;
  pageLines = numLines;
  len = lineSize - leftMargin - rightMargin - indent;
  page = (char**)malloc(sizeof(char*) * numLines);
  if (page == NULL) fail("Failed to allocate memory");
  for (i=0; i<numLines; i++) {
    page[i] = (char*)malloc(len + 1);
    for (j=0; j<len+rightMargin; j++)
      page[i][j] = ' ';
    page[i][len+rightMargin] = 0;
    }

  /* ****************************************** */
  /* ***** Place embedded image onto page ***** */
  /* ****************************************** */
  pos = (mode == 'l') ? 0 : len - width;
  for (i=0; i<numLines; i++)
    for (j=0; j<width; j++)
      page[i][j+pos+leftMargin] = image[i][j];

  if (mode == 'l') embedLeft = width + embedPadding;
  if (mode == 'r') embedRight = width + embedPadding;
  pageCount = 0;
  for (i=0; i<numLines; i++) free(image[i]);
  if (numLines > 0) free(image);
  buffer[0] = 0;
  return buffer;
  }

