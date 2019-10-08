#include <string.h>
#include <stdlib.h>
#include "header.h"

void processLine(char* buffer) {
  while (buffer[0] == '[') {
    if (strncmp(buffer,"[=]",3) == 0) buffer = processEndOfParagraph(buffer);
    else if (strncasecmp(buffer,"[C]",3) == 0) buffer = processCenter(buffer);
    else if (strncasecmp(buffer,"[H2]",4) == 0) buffer = processHeader(buffer);
    else if (strncasecmp(buffer,"[H1]",4) == 0) buffer = processHeader(buffer);
    else if (strncasecmp(buffer,"[H=]",4) == 0) buffer = processHeader(buffer);
    else if (strncasecmp(buffer,"[H-]",4) == 0) buffer = processHeader(buffer);
    else if (strncasecmp(buffer,"[I",2) == 0) buffer = processI(buffer);
    else if (strncmp(buffer,"[-]",3) == 0) buffer = processEndOfLine(buffer);
    else if (strncasecmp(buffer,"[LB",3) == 0) buffer = processList(buffer);
    else if (strncasecmp(buffer,"[TB",3) == 0) buffer = processTable(buffer);
    else if (strncasecmp(buffer,"[RM",3) == 0) buffer = processRM(buffer);
    else if (strncasecmp(buffer,"[ER",3) == 0) buffer = processEmbedded(buffer);
    else if (strncasecmp(buffer,"[EL",3) == 0) buffer = processEmbedded(buffer);
    else if (strncasecmp(buffer,"[E-]",4) == 0) buffer = processEmbedEnd(buffer);
    else if (strncasecmp(buffer,"[--]",4) == 0) buffer = processSection(buffer);
    else if (strncasecmp(buffer,"[==]",4) == 0) buffer = processSection(buffer);
    else if (strncasecmp(buffer,"[*]",4) == 0) buffer = processSection(buffer);
    else if (strncasecmp(buffer,"[SP]",4) == 0) buffer = processSplit(buffer);
    else if (strncasecmp(buffer,"[JR]",4) == 0) buffer = processJustify(buffer);
    else if (strncasecmp(buffer,"[JL]",4) == 0) buffer = processJustify(buffer);
    else if (strncasecmp(buffer,"[JF]",4) == 0) buffer = processJustify(buffer);
    else if (strncasecmp(buffer,"[JC]",4) == 0) buffer = processJustify(buffer);
    else if (strncasecmp(buffer,"[JN]",4) == 0) buffer = processJustify(buffer);
    else if (strncasecmp(buffer,"[]",2) == 0) buffer = processText(buffer);
    else {
      printf("Unknown tag found: %s%s",buffer,LE);
      exit(1);
      }
    }
  if (strlen(buffer) > 0) appendText(buffer);
  }

