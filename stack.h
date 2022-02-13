#ifndef STACK_H
#define STACK_H


#include <stdio.h>

int stack[256]; // Last in First out (LIFO)
int count = 0;


void push(int x) {
    if (count == sizeof(stack) / 4) {
        printf("The stack is full, nothing pushed\n");
        return;
    }
    stack[count] = x;
    printf("%d pushed successfully at index %d\n", x, count);
    count++;
}

int pop() {
    count--;
    if (count < 0) {
        printf("Stack is empty, defualt value: ");
        return 0;
    }
    else {
        return stack[count];
    }
}


#endif