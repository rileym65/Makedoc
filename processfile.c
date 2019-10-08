#include <stdio.h>
#include <string.h>
#include "header.h"

void processFile(const char* filename) {
  char line[1024];
  char inFilename[1024];
  char outFilename[1024];
  lineCount = 0;
  if (verbose) printf("Processing %s%s",filename,LE);
  if (strcmp(filename+strlen(filename)-2,".d") == 0) {
    strncpy(line,filename,strlen(filename)-2);
    line[strlen(filename)-2] = 0;
    }
  else
    strcpy(line,filename);
  strcpy(inFilename,line);
  strcpy(outFilename,line);
  strcat(inFilename,".d");
  strcat(outFilename,".doc");
  infile = fopen(inFilename,"r");
  if (infile == NULL) {
    printf("Could not open %s. Aborting this file.%s",inFilename,LE);
    return;
    }
  outfile = fopen(outFilename,"w");
  if (outfile == NULL) {
    printf("Could not open output file %s. Aborting this file.%s",outFilename,LE);
    fclose(infile);
    return;
  }
  outputBuffer[0] = 0;
  while (fgets(line, 1024, infile) != NULL) {
    trimLineEndings(line);
    trim(line);
    processLine(line);
    }



  fclose(infile);
  fclose(outfile);
  }

