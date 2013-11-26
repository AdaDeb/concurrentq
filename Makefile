BIN=	concurrent_queue

SRCS=	concurrent_queue.c
OBJS=	concurrent_queue.o

CC=	gcc
CFLAGS= -g 
## Turn on this for more warnings:
#CFLAGS= -g -Wall -pedantic
LIBS= -pthread

.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

all:	$(BIN)

lsh:	$(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS) $(LIBS)

clean:
	-rm -f $(OBJS) concurrent_queue
