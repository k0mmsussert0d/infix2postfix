CC=gcc
CFLAGS=-I.

infix2postfix: infix2postfix.o stack.o
	$(CC) -o infix2postfix infix2postfix.o stack.o $(CFLAGS)

infix2postfix.o: infix2postfix.c
	$(CC) -o infix2postfix.o -c infix2postfix.c

stack.o: stack.c
	$(CC) -o stack.o -c stack.c