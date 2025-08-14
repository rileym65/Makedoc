#include <string.h>
#include "header.h"

char* processUnformatted(char* buffer) {
  char line[1024];
  Byte done;
  flush();
  done = 0;
  while (done == 0) {
    if (fgets(line, 1024, infile) != NULL) {
      trimLineEndings(line);
      if (strncasecmp(line,"[UE]",4) == 0) done = -1;
      else {
        fprintf(outfile,"%s%s",line,LE);
        }
      }
    else done = -1;
    }
  return "";
  }

