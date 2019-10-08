#include <string.h>
#include <stdlib.h>
#include "header.h"

char fieldMode(char* field) {
  UInt32 i;
  char   mode;
  mode = '_';
  for (i=0; i<strlen(field); i++) {
    if (field[i] == ' ') mode = mode;
    else if (mode == '_' && field[i] == '#') mode = '#';
    else if (mode == '_' && field[i] == '>') mode = '>';
    else if (mode == '_' && field[i] == '<') mode = '<';
    else if (mode == '>' && field[i] == '<') mode = '%';
    else if (mode == '#' && field[i] == '#') mode = mode;
    else if (mode == '>' && field[i] == '>') mode = mode;
    else if (mode == '<' && field[i] == '<') mode = mode;
    else if (mode == '%' && field[i] == '<') mode = mode;
    else mode = ' ';
    }
  if (mode == '_') mode = ' ';
  return mode;
  }

char* prepareField(char* field, char mode, UInt32 len) {
  Int32 len1;
  len1 = strlen(field);
  pad(field, len);
  if (mode == '>') slideRight(field, len-len1);
  if (mode == '%') {
    len1 = (len / 2) - (len1 / 2);
    if (len1 >0) slideRight(field, len1);
    }
  return field;
  }

char* processTable(char* buffer) {
  UInt32 i;
  UInt32 j;
  UInt32 k;
  UInt32 row;
  char   mode;
  char   temp[1024];
  char   fields[100][1024];
  char*  src;
  char*  dst;
  char** cells;
  UInt32 numCells;
  UInt32* columnWidths;
  UInt32  numColumns;
  char    columnModes[1024];
  UInt32 padding;
  UInt32 count;
  UInt32 column;
  UInt32 size;
  char line[1024];
  Byte done;
  Byte formatted;
  flush();
  padding = cellPadding;
  numCells = 0;
  numColumns = 0;
  cells = NULL;
  count = 0;

  /* ********************************* */
  /* ***** Process table options ***** */
  /* ********************************* */
  buffer += 3;
  while (*buffer != 0 && *buffer != ']') {
    if (*buffer >= '0' && *buffer <= '9') padding = *buffer - '0';
    buffer++;
    }

  /* ********************************** */
  /* ***** Read contents of table ***** */
  /* ********************************** */
  done = 0;
  while (!done) {
    src = readLine(line, 1024);
    if (src == NULL) fail("Unexpected end of file");
    if (strncasecmp(line,"[TE]",4) == 0) done = 0xff;
    else {
      count = 0;
      src = line;
      dst = temp;
      while (*src != 0 && *src != '|') src++;
      if (*src == 0) fail("Unexpected end of line");
      src++;
      while (*src != 0) {
        while (*src != '|' && *src != 0) *dst++ = *src++;
        if (*src == '|') {
          *dst = 0;
          trim(temp);
          count++;
          if (++numCells == 1)
            cells = (char**)malloc(sizeof(char*));
          else
            cells = (char**)realloc(cells, sizeof(char*) * numCells);
          cells[numCells-1] = (char*)malloc(strlen(temp) + 1);
          strcpy(cells[numCells-1], temp);
          dst = temp;
          src++;
          }
        else if (*src == 0) {
          if (strlen(temp) > 0) {
            if (dst > temp) *dst++ = ' ';
            src = readLine(line, 1024);
            if (src == NULL) fail("Unexpected end of file");
            }
          }
        }
      }
    if (numColumns == 0) numColumns = count;
    if (count > 0 && count != numColumns)
      fail("Column count mismatch in table");
    }

  /* ********************************************** */
  /* ***** Process cells to get column widths ***** */
  /* ********************************************** */
  columnWidths = (UInt32*)malloc(sizeof(UInt32) * numColumns);
  if (columnWidths == NULL) fail("Could not allocation memory");
  for (i=0; i<numColumns; i++) {
    columnWidths[i] = 0;
    columnModes[i] =' ';
    }
  column = 0;
  row = 0;
  formatted = 0x00;
  for (i=0; i<numCells; i++) {
    mode = fieldMode(cells[i]);
    if (mode != ' ' && row == 0) {
      columnModes[column] = mode;
      columnWidths[column] = strlen(cells[i]);
      formatted = 0xff;
      }
    else if (columnModes[column] == ' ') {
      if (strlen(cells[i]) > columnWidths[column])
        columnWidths[column] = strlen(cells[i]);
      }
    if (++column == numColumns) {
      column = 0;
      row++;
      }
    }

  /* ****************************************************** */
  /* ***** Make sure table does not exceed print size ***** */
  /* ****************************************************** */
  size = (padding * 2) * (numColumns - 1);
  for (i=0; i<numColumns; i++)
    size += columnWidths[i];
  if (size > printSize())
    columnWidths[numColumns-1] -= (size - printSize());

  /* ******************************** */
  /* ***** Now output the table ***** */
  /* ******************************** */
  column = 0;
  row = 0;
  for (i=0; i<numCells; i++) {
    strcpy(fields[column], cells[i]);
    if (++column == numColumns) {
      done = 0;
      while (!done) {
        done = 0xff;
        strcpy(line,"");
        for (j=0; j<numColumns; j++) {
          if (j != 0) {
            for (k=0; k<padding; k++)
              strcat(line," ");
            }
          splitAt(temp, fields[j], columnWidths[j]);
          if (strlen(fields[j]) > 0) done = 0;
          prepareField(temp, columnModes[j], columnWidths[j]);
          strcat(line, temp);
          if (j != numColumns-1)
            for (k=0; k<padding; k++)
              strcat(line," ");
          }
        if (row != 0 || !formatted) outputLine(line, 0x00);
        row++;
        }
      column = 0;
      }
    }

  for (i=0; i<numCells; i++) free(cells[i]);
  if (numCells > 0) free(cells);
  buffer[0] = 0;
  return buffer;
  }

