#parameters

CC = gcc
CFLAGS = -pedantic -Wall -g

#compile tings
rpn: main.c math.c stack.h stack.c
	$(CC) $(CFLAGS) -o rpn main.c math.c stack.h stack.c

install: main.c math.c stack.h stack.c
	$(CC) $(CFLAGS) -o /home/s7rul/code/bin/rpn main.c math.c stack.h stack.c
