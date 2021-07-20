OBJS=main.o list.o
CC=gcc
CFLAGS=-c -Wall -g

all:mylist
.PHONY:all clean

mylist:$(OBJS)
	$(CC) $^ -o $@

# %.o:%.c
#	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o mylist 