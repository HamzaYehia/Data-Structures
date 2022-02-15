// Stack is Last in First out (LIFO) Data Structure

#ifndef STACK_H
#define STACK_H


#include <stdio.h>

int stack[1024];
int lastMember = 0;

void push(int member) {
    if (lastMember == sizeof(stack) / 4) {
        printf("The stack is full, nothing pushed\n");
        return;
    }
    stack[lastMember] = member;
    printf("%d pushed successfully at index %d\n", member, lastMember);
    lastMember++;
}

int pop() {
    lastMember--;
    if (lastMember < 0) {
        printf("Stack is empty, defualt value: ");
        return 0;
    }
    else {
        return stack[lastMember];
    }
}

void emptyStack() {
    lastMember = 0;
}


#endif