#include <string.h>
#include "header.h"

/* ****************************************************************** */
/* ***** This function splits a string so that the left portion ***** */
/* ***** does not exceed the current printable line width.      ***** */
/* ***** The left portion is returned and the right portion has ***** */
/* ***** the left portion removed.                              ***** */
/* ****************************************************************** */

char* splitAt(char* left,char* right,UInt32 size) {
  UInt32 i;
  UInt32 len;
  UInt32 dst;
  len = size;
  if (len >= strlen(right)) {
    strcpy(left, right);
    strcpy(right,"");
    return left;
    }
  while (len > 0 && right[len] != ' ' && right[len] != '\t') len--;
  strncpy(left,right,len);
  left[len] = 0;
  rtrim(left);
  dst = 0;
  while ((right[dst++] = right[len++]) != 0) ;
  trim(right);
  if (strlen(right) == 0) {
    strcpy(right,"");
    for (i=0; i<paragraphStart; i++) strcat(right," ");
    }
  return left;
  }

