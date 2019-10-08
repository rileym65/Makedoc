#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void outputLine(char* buffer,Byte useJustify) {
  UInt32 i;
  if (embedRight > 0 || embedLeft > 0) {
    if (useJustify) justifyLine(buffer,justify,printSize());
    for (i=0; i<strlen(buffer); i++)
      page[pageCount][leftMargin+indent+embedLeft+i] = buffer[i];
    fprintf(outfile,"%s%s",page[pageCount],LE);
    if (++pageCount >= pageLines) {
      embedRight = 0;
      embedLeft = 0;
      for (i=0; i<pageLines; i++) free(page[i]);
      if (pageLines > 0) free(page);
      }
    }
  else {
    if (useJustify) justifyLine(buffer,justify,printSize());
    for (i=0; i<leftMargin+indent; i++)
      fprintf(outfile," ");
    fprintf(outfile,"%s%s",buffer,LE);
    }
  }

