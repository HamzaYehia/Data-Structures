// Stack is Last in First out (LIFO) Data Structure

#ifndef STACK_WITH_LINKED_LIST_H
#define STACK_WITH_LINKED_LIST_H



typedef struct member {
    int value;
    struct member* next;
}member;

member* top = NULL;

void push(int val) {
    member* pushed_member = (member*)malloc(1 * sizeof(member));

    pushed_member->value = val;
    pushed_member->next = top;

    top = pushed_member;
}

member* pop() {
    if (top == NULL) {
        printf("The stack is empty\n");
        return NULL;
    }
    member* temporary_top = top;
    top = top->next;
    free(temporary_top);

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


void empty_stack() {
    while (top != NULL) {
        member* temporary_top = top;
        top = top->next;
        free(temporary_top);
    }
}


#endif