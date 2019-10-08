PROJECT = makedoc
INSTALLDIR = /usr/local/bin/
CC = gcc
CFLAGS =
LFLAGS =
INCDIR =
INCS =
LIBDIR = 
LIBS = 
OBJS = \
	appendtext.o \
	cleanup.o \
	fail.o \
	flush.o \
	init.o \
	justifyline.o \
	main.o \
	outputline.o \
	pad.o \
	printsize.o \
	processcenter.o \
	processembedded.o \
	processembedend.o \
	processeol.o \
	processeop.o \
	processfile.o \
	processheader.o \
	processi.o \
	processjustify.o \
	processlist.o \
	processline.o \
	processlm.o \
	processoptions.o \
	processrm.o \
	processsec.o \
	processsplit.o \
	processtable.o \
	processtext.o \
	readline.o \
	rtrim.o \
	slideleft.o \
	slideright.o \
	split.o \
	splitat.o \
	trim.o \
	trimlineendings.o

# Defs for compiling with UNIX
DEFS = -DUNIX -O3 -Wall

# Defs for compiling with MINGW for native Windows binary
#DEFS = -DUNIX -O3 -Wall -DMINGW -UWIN32 -static-libstdc++ -static-libgcc -static

$(PROJECT): $(OBJS)
	$(CC) $(LFLAGS) $(LIBDIR) $(LIBS) -o $(PROJECT) $(OBJS)

docs:   makedoc
	./makedoc -ls80 -rm5 -lm5 -tp5 -ps2 -v makedoc

.c.o:
	$(CC) $(CFLAGS) $(DEFS) $(INCDIR) $(INCS) -c $<

clean:
	-rm makedoc
	-rm *.o

install:
	cp makedoc /usr/local/bin
	chmod a+rx /usr/local/bin/makedoc

appendtext.o:      header.h appendtext.c
cleanup.o:         header.h cleanup.c
fail.o:            header.h fail.c
flush.o:           header.h flush.c
init.o:            header.h init.c
justifyline.o:     header.h justifyline.c
main.o:            header.h main.c
outputline.o:      header.h outputline.c
pad.o:             header.h pad.c
printsize.o:       header.h printsize.c
processcenter.o:   header.h processcenter.c
processembedded.o: header.h processembedded.c
processembedend.o: header.h processembedend.c
processeol.o:      header.h processeol.c
processeop.o:      header.h processeop.c
processfile.o:     header.h processfile.c
processheader.o:   header.h processheader.c
processi.o:        header.h processi.c
processjustify.o:  header.h processjustify.c
processline.o:     header.h processline.c
processlist.o:     header.h processlist.c
processlm.o:       header.h processlm.c
processoptions.o:  header.h processoptions.c
processrm.o:       header.h processrm.c
processsec.o:      header.h processsec.c
processsplit.o:    header.h processsplit.c
processtable.o:    header.h processtable.c
processtext.o:     header.h processtext.c
readline.o:        header.h readline.c
rtrim.o:           header.h rtrim.c
slideleft.o:       header.h slideleft.c
slideright.o:      header.h slideright.c
split.o:           header.h split.c
trim.o:            header.h trim.c
trimlineendings.o: header.h trimlineendings.c
