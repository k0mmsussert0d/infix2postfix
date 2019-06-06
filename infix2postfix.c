#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

char* infix2postfix(const char*);
int prec(char);
int isOp(char);

int main(int argc, char* argv[]) {
    printf("%s\n", infix2postfix("1234097*9862/32423^3333"));

    return 0;
}

char* infix2postfix(const char input_exp[]) {
    size_t len = strlen(input_exp);
    Stack* stack = createStack(len);
    char* res   = (char*)malloc(len + 1);
    char* infix = (char*)malloc(len + 1);

    strcpy(infix,input_exp);

    infix[len] = ')';
    push(stack, '(');

    const char* ptr = infix;
    int i = 0;

    while(*ptr != '\0') {
        if(isalnum(*ptr)) {
            res[i++] = *ptr;

        } else if(*ptr == '(') {
            push(stack, *ptr);

        } else if(*ptr == ')') {
            while(peek(stack) != '(') {
                res[i++] = pop(stack);
            }

            pop(stack);

        } else if(isOp(*ptr)) {
            while(prec(*ptr) <= prec(peek(stack))) {
                res[i++] = pop(stack);
            }

            push(stack, *ptr);

        }

        ++ptr;
    }

    res[i] = '\0';
    return res;

}

int prec(char c) {
    switch(c) {
        case '^':
        return 3;

        case '*': case '/':
        return 2;

        case '+': case '-':
        return 1;
    }

    return -1;
}

int isOp(char c) {
    return  c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^';
}