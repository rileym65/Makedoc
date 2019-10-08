#include <stdio.h>
#include "types.h"

#ifdef MAIN
#define LINK
#else
#define LINK extern
#endif

LINK char   LE[3];
LINK UInt32 cellPadding;
LINK UInt32 embedLeft;
LINK UInt32 embedPadding;
LINK UInt32 embedRight;
LINK char** files;
LINK UInt32 indent;
LINK FILE*  infile;
LINK char   justify;
LINK UInt32 leftMargin;
LINK UInt32 lineCount;
LINK UInt32 lineSize;
LINK UInt32 numFiles;
LINK FILE*  outfile;
LINK char   outputBuffer[1024];
LINK char** page;
LINK UInt32 pageCount;
LINK UInt32 pageLines;
LINK UInt32 paragraphStart;
LINK UInt32 rightMargin;
LINK Byte   verbose;
LINK Byte   paraStart;
LINK UInt32 paraIndent;

extern void   appendText(char* buffer);
extern void   cleanup();
extern void   fail(char* message);
extern void   flush();
extern void   init();
extern char*  justifyLine(char* line, char mode, UInt32 size);
extern void   outputLine(char* buffer,Byte useJustify);
extern char*  pad(char* buffer,UInt32 len);
extern UInt32 printSize();
extern char*  processCenter(char* buffer);
extern char*  processEmbedded(char* buffer);
extern char*  processEmbedEnd(char* buffer);
extern char*  processEndOfLine(char* buffer);
extern char*  processEndOfParagraph(char* buffer);
extern void   processFile(const char* filename);
extern char*  processHeader(char* buffer);
extern char*  processI(char* buffer);
extern char*  processJustify(char* buffer);
extern void   processLine(char* buffer);
extern char*  processList(char* buffer);
extern char*  processLM(char* buffer);
extern void   processOptions(int argc, char** argv);
extern char*  processRM(char* buffer);
extern char*  processSection(char* buffer);
extern char*  processSplit(char* buffer);
extern char*  processTable(char* buffer);
extern char*  processText(char* buffer);
extern char*  readLine(char* dest, UInt32 maxlen);
extern char*  rtrim(char* buffer);
extern char*  slideLeft(char* buffer,UInt32 len);
extern char*  slideRight(char* buffer,UInt32 len);
extern char*  split(char* left,char* right);
extern char*  splitAt(char* left,char* right,UInt32 size);
extern char*  trim(char* buffer);
extern char*  trimLineEndings(char* buffer);

