// Stack is Last in First out (LIFO) Data Structure

#ifndef STACK_H
#define STACK_H



int stack[1024];
int lastMember = -1;

void push(int member) {
    // ckeck if the stack is full
    if (lastMember == (sizeof(stack) / 4) - 1) {
        printf("The stack is full, %d was not pushed\n", member);
        return;
    }

    // else: push element on top of the Stack
    stack[++lastMember] = member;
    printf("%d pushed at index %d\n", member, lastMember);
}

int pop() {
    // ckeck if Stack is empty
    if (lastMember < 0) {
        printf("Stack is empty, defualt value: ");
        return 0;
    }
    // else: return element on top of the Stack and remove it
    else {
        return stack[lastMember--];
    }
}

void emptyStack() {
    lastMember = -1;
}


bool isEmpty() {
    if (lastMember <= -1) return true;
    else {
        return false;
    }
}

#endif