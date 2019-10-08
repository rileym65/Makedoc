#include <string.h>
#include "header.h"

/* ****************************************************************** */
/* ***** This function splits a string so that the left portion ***** */
/* ***** does not exceed the current printable line width.      ***** */
/* ***** The left portion is returned and the right portion has ***** */
/* ***** the left portion removed.                              ***** */
/* ****************************************************************** */

char* split(char* left,char* right) {
  UInt32 len;
  len = printSize();
  return splitAt(left, right, len);
  }

