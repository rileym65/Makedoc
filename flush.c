#include <string.h>
#include "header.h"

void flush() {
  char toOutput[1024];
  while (strlen(outputBuffer) > 0) {
    split(toOutput, outputBuffer);
    outputLine(toOutput, (strlen(outputBuffer) > 0) ? 0xff : 0x00);
    }
  }

