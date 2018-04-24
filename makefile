#parameters

CC = gcc
CFLAGS = -pedantic -Wall -g

#compile tings
rpn: main.c math.c stack.h stack.c
	$(CC) $(CFLAGS) -o rpn main.c math.c stack.h stack.c

#install:
