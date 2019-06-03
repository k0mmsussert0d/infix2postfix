#ifndef STACK_H
#define STACK_H

typedef struct {
    char top;
    char* array;
    unsigned int capacity;
} Stack;

Stack* createStack(unsigned int);
char push(Stack*, char);
char pop(Stack*);

#endif