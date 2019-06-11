#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_2d.h"

// TODO: handle input size dynamically
#define BUFFER_SIZE 100

char* postfix2infix(const char*);
int isOp(char);

int main(int argc, char* argv[]) {
    if(argc > 0) {
        for(int i = 1; i < argc; ++i) {
            printf("%s\n", postfix2infix(argv[i]));
        }
    } else {
        char buffer[BUFFER_SIZE];
        int c, i = 0;
        while((c = getchar()) != EOF) {
            if(c == '\n') {
                buffer[i] = '\0';
                printf("%s\n", postfix2infix(buffer));
                i = 0;
            } else {
                buffer[i++] = c;
            }
        }
    }
    return 0;
}

char* postfix2infix(const char* input_exp) {
    Stack2D* stack = create2DStack(strlen(input_exp));

    const char* ptr = input_exp;

    while(*ptr != '\0') {
        if(isalnum(*ptr)) {
            char* toPush = (char*)malloc(2); // 1 operand and null-terminator
            sprintf(toPush, "%c", *ptr);
            push(stack, toPush);
        } else if(isOp(*ptr)) {
            char* operand2 = pop(stack);
            char* operand1 = pop(stack);

            char* toPush = (char*)malloc(strlen(operand1) + strlen(operand2) + 4); // 2 expressions, 2 brackets, operator and null-terminator
            sprintf(toPush, "(%s%c%s)", operand1, *ptr, operand2);
            push(stack, toPush);
        }

        ++ptr;
    }

    return pop(stack);
}

int isOp(char c) {
    return  c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^';
}