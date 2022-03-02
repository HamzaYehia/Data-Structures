// Queue is First in First out (FIFO) Data structure

#ifndef QUEUE_H
#define  QUEUE_H


#include <stdio.h>

int queue[1024];
int first = 0, last = 0;

void enQueue(int element) {
    // checks if the Queue is full
    if (last == sizeof(queue) / 4) {
        printf("The Queue is full\n");
        return;
    }
    // enQueue an element to the end of the Queue
    queue[last] = element;
    printf("%d enqueued at index: %d\n", element, last);
    last++;
}

int deQueue() {
    // check if the Queue is empty
    if (last == first) {
        printf("The Queue is empty\n");
        return 0;
    }
    // else:
    int firsMember = queue[first];

    // move each element one step forward
    for (int i = 0; i < last - 1; i++) {
        queue[i] = queue[i + 1];
    }
    last--;

    return firsMember;
}

void emptyQueue() {
    // empty the Queue
    first = 0;
    last = 0;
}


#endif