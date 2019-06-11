CC=gcc
CFLAGS=-I.

all: infix2postfix postfix2infix

infix2postfix: infix2postfix.o stack.o
	$(CC) -o infix2postfix infix2postfix.o stack.o $(CFLAGS)

infix2postfix.o: infix2postfix.c
	$(CC) -o infix2postfix.o -c infix2postfix.c

postfix2infix: postfix2infix.o stack_2d.o
	$(CC) -o postfix2infix postfix2infix.o stack_2d.o $(CFLAGS)

postfix2infix.o: postfix2infix.c
	$(CC) -o postfix2infix.o -c postfix2infix.c

stack.o: stack.c
	$(CC) -o stack.o -c stack.c

stack_2d.o: stack_2d.c
	$(CC) -o stack_2d.o -c stack_2d.c