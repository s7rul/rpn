#parameters

CC = gcc
CFLAGS = -pedantic -Wall

#compile tings
rpn: main.c stdinput.c stack.h stack.c
	$(CC) $(CFLAGS) -o rpn main.c stdinput.c stack.h stack.c stringtoint.h stringtoint.c

debug: main.c stdinput.c stack.h stack.c
	$(CC) $(CFLAGS) -g -o rpn main.c stdinput.c stack.h stack.c stringtoint.h stringtoint.c

install: main.c stack.h stack.c
	$(CC) $(CFLAGS) -o /home/s7rul/code/bin/rpn main.c stdinput.c stack.h stack.c stringtoint.h stringtoint.c
