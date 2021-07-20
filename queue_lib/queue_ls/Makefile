OBJS=main.o list.o queue.o
CC=gcc
CFLAGS=-c -Wall -g

all:myqueue

myqueue:$(OBJS)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) $^ -o $@   

.PHONY:clean

clean:
	rm -rf *.o myqueue
