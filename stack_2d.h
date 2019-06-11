#ifndef STACK_2D_H
#define STACK_2D_H

typedef struct {
    char top;
    char** array;
    unsigned int capacity;
} Stack2D;

Stack2D* create2DStack(unsigned int);
char* push(Stack2D*, char*);
char* pop(Stack2D*);
char* peek(Stack2D*);

#endif