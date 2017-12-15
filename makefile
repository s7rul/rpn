#parameters

CC = gcc
CFLAGS = -pedantic -Wall -g

#compile tings

rpn: main.c math.c stack.o
	$(CC) $(CFLAGS) -o rpn main.c math.c stack.o

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) stack.o -c stack.c
