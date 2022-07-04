// Queue is First in First out (FIFO) Data structure

#ifndef QUEUE_WITH_LINKED_LIST
#define QUEUE_WITH_LINKED_LIST



typedef struct member {
    int val;
    struct member* next;
}member;


member* front = NULL;
member* rear = NULL;


void emptyQueue() {
    member* temporaryMember = NULL;
    while (front != NULL) {
        temporaryMember = front;
        front = front->next;
        free(temporaryMember);
    }
    front = NULL;
    rear = NULL;
    printf("Done\n");
}

bool isEmpty() {
    if (front == NULL && rear == NULL) {
        return true;
    }
    else {
        return false;
    }
}


void enQueue(int val) {
    member* newMember = (member*)malloc(1 * sizeof(member));

    newMember->val = val;
    newMember->next = NULL;

    if (front == NULL && rear == NULL) {
        front = newMember;
        rear = newMember;
        return;
    }

    rear->next = newMember;
    rear = newMember;
}

void deQueue() {
    if (front == NULL && rear == NULL) {
        printf("The queue is empty!\n");
        return;
    }

    member* temporaryMember = front;

    if (front == rear) {
        front = NULL;
        rear = NULL;
        free(temporaryMember);
        return;
    }

    front = front->next;
    free(temporaryMember);
}


member* getFront() {
    return front;
}



#endif