#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

void processOptions(int argc, char** argv) {
  UInt32 i;
  i = 1;
  while (i < argc) {
    if (strncmp(argv[i],"-ls",3) == 0) lineSize = atoi(argv[i]+3);
    if (strncmp(argv[i],"-rm",3) == 0) rightMargin = atoi(argv[i]+3);
    if (strncmp(argv[i],"-lm",3) == 0) leftMargin = atoi(argv[i]+3);
    if (strncmp(argv[i],"-cp",3) == 0) cellPadding = atoi(argv[i]+3);
    if (strcmp(argv[i],"-v") == 0) verbose = 0xff;
    if (strcmp(argv[i],"-u") == 0) strcpy(LE,"\n");
    if (strcmp(argv[i],"-w") == 0) strcpy(LE,"\r\n");
    if (argv[i][0] != '-') {
      if (++numFiles == 1)
        files = (char**)malloc(sizeof(char*));
      else 
        files = (char**)malloc(sizeof(char*) * numFiles);
      if (files == NULL) {
        printf("Failed to allocate memory for filenames, aborting%s",LE);
        exit(1);
        }
      files[numFiles-1] = (char*)malloc(strlen(argv[i]) + 1);
      if (files[numFiles-1] == NULL) {
        printf("Failed to allocate memory for filename, aborting%s",LE);
        exit(1);
        }
      strcpy(files[numFiles-1],argv[i]);
      }
    i++;
    }
  }

