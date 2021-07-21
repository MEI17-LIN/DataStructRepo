OBJS=main.o sqstack.o
CC=gcc
CFLAGS=-c -Wall -g

mystack:$(OBJS)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@
.PHONY:clean
clean:
	rm *.o mystack -rf