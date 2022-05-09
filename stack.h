// Stack is Last in First out (LIFO) Data Structure

#ifndef STACK_H
#define STACK_H



int stack[1024];
int lastMember = 0;

void push(int member) {
    // ckeck if the stack is full
    if (lastMember == sizeof(stack) / 4) {
        printf("The stack is full, nothing pushed\n");
        return;
    }
    // else: push element on top of the Stack
    stack[lastMember] = member;
    printf("%d pushed at index %d\n", member, lastMember);
    lastMember++;
}

int pop() {
    // ckeck if Stack is empty
    lastMember--;
    if (lastMember < 0) {
        printf("Stack is empty, defualt value: ");
        return 0;
    }
    // else: return element on top of the Stack and remove it
    else {
        return stack[lastMember];
    }
}

void emptyStack() {
    // empty the Stack
    lastMember = 0;
}


#endif