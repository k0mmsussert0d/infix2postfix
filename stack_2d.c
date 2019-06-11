#include "stack_2d.h"
#include <stdlib.h>
#include <string.h>

#define STACK_STRING_SIZE 30

Stack2D* create2DStack(unsigned int capacity) {
    Stack2D* res = (Stack2D*)malloc(sizeof(Stack2D));
    res->capacity = capacity;
    res->top = -1;
    res->array = (char**)malloc(res->capacity * sizeof(char*));
    for(int i = 0; i < res->capacity; ++i) {
        res->array[i] = (char*)malloc(STACK_STRING_SIZE);
    }

    return res;
}

static int isFull(Stack2D* stack) {
    return stack->top == stack->capacity - 1;
}

static int isEmpty(Stack2D* stack) {
    return stack->top == -1;
}

char* push(Stack2D* stack, char* str) {
    if(isFull(stack)) {
        return NULL;
    }

    strcpy(stack->array[++stack->top], str);
    return stack->array[stack->top];    
}

char* pop(Stack2D* stack) {
    if(isEmpty(stack)) {
        return NULL;
    }

    return stack->array[stack->top--];
}

char* peek(Stack2D * stack) {
    if(isEmpty(stack)) {
        return NULL;
    }

    return stack->array[stack->top];
}