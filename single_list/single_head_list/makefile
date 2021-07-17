OBJS=main.o list.o
CC=gcc
CFLAGS=-c -Wall -g


mylist:$(OBJS)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@


clean:
	$(RM) rm *.o -r

