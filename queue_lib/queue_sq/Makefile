OBJS=main.o queue.o
CC=gcc
CFLAGS=-c -Wall -g

myqueue:$(OBJS)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@


.PHONY:clean
clean:
	rm myqueue *.o -rf