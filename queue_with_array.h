// Queue is First in First out (FIFO) Data structure

#ifndef QUEUE_WITH_ARRAY
#define  QUEUE_WITH_ARRAY



int queue[1024];
int front = 0, rear = 0;
int sizeOfQueue = (sizeof(queue) / 4) - 1;


void emptyQueue() {
    front = 0;
    rear = 0;
}

bool isEmpty() {
    if (front >= rear) {
        return true;
    }
    else {
        return false;
    }
}


bool isFull() {
    if (rear >= sizeOfQueue) {
        return true;
    }
    else {
        return false;
    }
}


void enQueue(int element) {

    if (isEmpty()) {
        front = 0;
        rear = 0;
    }

    if (isFull()) {
        printf("The Queue is full!\n");
        return;
    }

    queue[rear++] = element;
    printf("%d enqueued, there is/are %d members before\n", element, rear - 1);
}

int deQueue() {
    if (isEmpty()) {
        printf("The Queue is empty!\n");
        return 0;
    }

    return queue[front++];
}


int getFront() {
    return queue[front];
}



#endif