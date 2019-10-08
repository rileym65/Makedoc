#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void fail(char* message) {
  printf("Error: %s at line: %d%s",message, lineCount, LE);
  exit(1);
  }
