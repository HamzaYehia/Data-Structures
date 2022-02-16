// Queue is First in First out (FIFO) Data structure

#ifndef QUEUE_H
#define  QUEUE_H


#include <stdio.h>

int queue[1024];
int first = 0, last = 0;

void enQueue(int member) {
    if (last == sizeof(queue) / 4) {
        printf("The Queue is full\n");
        return;
    }

    queue[last] = member;
    printf("%d enqueued at index: %d\n", member, last);
    last++;
}

int deQueue() {

    if (last == first) {
        printf("The Queue is empty\n");
        return 0;
    }

    int firsMember = queue[first];

    for (int i = 0; i < last - 1; i++) {
        queue[i] = queue[i + 1];
    }
    last--;

    return firsMember;
}

void emptyQueue() {
    first = 0;
    last = 0;
}


#endif