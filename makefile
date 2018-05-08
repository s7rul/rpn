#parameters

CC = gcc
CFLAGS = -pedantic -Wall -g

#compile tings
rpn: main.c stack.h stack.c
	$(CC) $(CFLAGS) -o rpn main.c stack.h stack.c stringtoint.h stringtoint.c

install: main.c stack.h stack.c
	$(CC) $(CFLAGS) -o /home/s7rul/code/bin/rpn main.c stack.h stack.c stringtoint.h stringtoint.c
