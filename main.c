#include <stdio.h>
#include <string.h>
#define MAIN

#include "header.h"

int main(int argc, char** argv) {
  UInt32 i;
  if (argc < 2) {
    printf("Usage: makedoc filename%s",LE);
    return 1;
    }
  init();
  processOptions(argc, argv);
  for (i=0; i<numFiles; i++) {
    processFile(files[i]);
    }




  cleanup();
  return 0;
  }

