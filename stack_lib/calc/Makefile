OBJS=main.o sqstack.o
CC=gcc

mystack:$(OBJS)
	$(CC) $^ -o $@


.PHONY:clean
clean:
	rm *.o mystack -rf