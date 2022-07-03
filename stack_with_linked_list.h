// Stack is Last in First out (LIFO) Data Structure

#ifndef STACK_WITH_LINKED_LIST_H
#define STACK_WITH_LINKED_LIST_H



typedef struct member {
    int value;
    struct member* next;
}member;

member* top = NULL;

void push(int val) {
    member* pushedMember = (member*)malloc(1 * sizeof(member));

    pushedMember->value = val;
    pushedMember->next = top;

    top = pushedMember;
}

member* pop() {
    if (top == NULL) {
        printf("The stack is empty\n");
        return NULL;
    }
    member* temporaryTop = top;
    top = top->next;
    free(temporaryTop);

    return top;
}


bool isEmpty() {
    if (top == NULL) {
        return true;
    }
    else {
        return false;
    }
}


void emptyStack() {
    while (top != NULL) {
        member* temporaryTop = top;
        top = top->next;
        free(temporaryTop);
    }
}


#endif