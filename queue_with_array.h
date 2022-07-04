// Queue is First in First out (FIFO) Data structure

#ifndef QUEUE_WITH_ARRAY
#define QUEUE_WITH_ARRAY



int queue[1024];
int front = 0, rear = 0;
int sizeOfQueue = (sizeof(queue) / 4) + 1;


void emptyQueue() {
    front = 0;
    rear = 0;
}

bool isEmpty() {
    if (front == rear) {
        return true;
    }
    else {
        return false;
    }
}


bool isFull() {
    if (((rear + 1) % sizeOfQueue) == front) {
        return true;
    }
    else {
        return false;
    }
}


void enQueue(int element) {

    if (isEmpty()) {
        emptyQueue();
    }

    if (isFull()) {
        printf("The Queue is full!\n");
        return;
    }


    queue[rear] = element;
    rear = (rear + 1) % sizeOfQueue;
    printf("%d enqueued\n", element);
}

void deQueue() {
    if (isEmpty()) {
        emptyQueue();
        printf("The Queue is empty!\n");
        return;
    }

    printf("%d dequeued\n", queue[front]);
    front = (front + 1) % sizeOfQueue;
}


int getFront() {
    if (!isEmpty()) {
        return queue[front];
    }
    else {
        printf("No elements in the front!\n");
        return 0;
    }
}



#endif