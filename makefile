#parameters

CC = gcc
CFLAGS = -pedantic -Wall -g

#compile tings

rpn: rpn.o stack.o
	$(CC) $(CFLAGS) -o rpn rpn.o stack.o

rpn.o: main.c math.c stack.h
	$(CC) $(CFLAGS) -c main.c math.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c
