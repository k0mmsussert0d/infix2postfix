#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_2d.h"

char* postfix2infix(const char*);
int isOp(char);

int main(int argc, char* argv[]) {
    printf("%s\n", postfix2infix("ab*c+"));
    return 0;
}

char* postfix2infix(const char* input_exp) {
    size_t len = strlen(input_exp);
    Stack2D* stack = create2DStack(len);

    const char* ptr = input_exp;

    while(*ptr != '\0') {
        if(isalnum(*ptr)) {
            char* toPush = (char*)malloc(2); // 1 operand and null-terminator
            sprintf(toPush, "%c", *ptr);
        } else if(isOp(*ptr)) {
            char* operand1 = pop(stack);
            char* operand2 = pop(stack);

            char* toPush = (char*)malloc(6); // 2 brackets, 2 operands, operator and null-terminator
            sprintf(toPush, "(%c%c%c)", operand1[0], *ptr, operand2[0]);
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