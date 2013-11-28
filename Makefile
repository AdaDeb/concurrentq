BIN=	tester

SRCS=	concurrent_queue.c tester.c concurrent_queue_2locks.c
OBJS=	concurrent_queue.o tester.o concurrent_queue_2locks.o

CC=	gcc
CFLAGS= -g 
## Turn on this for more warnings:
#CFLAGS= -g -Wall -pedantic
LIBS= -pthread

.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

all:	$(BIN)

tester:	$(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS) $(LIBS)

clean:
	-rm -f $(OBJS) concurrent_queue tester concurrent_queue_2locks
