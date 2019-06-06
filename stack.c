#include <stdlib.h>
#include "stack.h"

Stack* createStack(unsigned int capacity) {
    Stack* res = (Stack*)malloc(sizeof(Stack));
    res->capacity = capacity;
    res->top = -1;
    res->array = (char*)malloc(res->capacity * sizeof(int));

    return res;
}

static int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

static int isEmpty(Stack* stack) {
    return stack->top == -1;
}

char push(Stack* stack, char item) {
    if(isFull(stack)) {
        return -1;
    }

    stack->array[++stack->top] = item;
    return stack->array[stack->top];
}

char pop(Stack* stack) {
    if(isEmpty(stack)) {
        return -1;
    }

    return stack->array[stack->top--];
}

char peek(Stack* stack) {
    if(isEmpty(stack)) {
        return -1;
    }

    return stack->array[stack->top];
}