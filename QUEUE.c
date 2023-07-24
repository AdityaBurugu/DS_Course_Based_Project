#include "QUEUE.h"

void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int QueueisFull(Queue *queue) 
{
    return ((queue->rear + 1) % MAX_SIZE) == queue->front;
}

int QueueisEmpty(Queue *queue) 
{
    return queue->front == -1 && queue->rear == -1;
}

void enqueue(Queue *queue, char str[]) 
{
    if (QueueisFull(queue)) {
        printf("Error: Queue is full, cannot enqueue more elements.\n");
        return;
    }

    if (QueueisEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    strcpy(queue->data[queue->rear], str);
}

char* dequeue(Queue *queue) 
{
    if (QueueisEmpty(queue)) {
        printf("Error: Queue is empty, cannot dequeue an element.\n");
        return NULL;
    }

    char* dequeuedItem = queue->data[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return dequeuedItem;
}
/*
int main() {
    Queue queue;
    initialize(&queue);

    enqueue(&queue, "First");
    enqueue(&queue, "Second");
    enqueue(&queue, "Third");

    printf("Dequeued: %s\n", dequeue(&queue));
    printf("Dequeued: %s\n", dequeue(&queue));
    printf("Dequeued: %s\n", dequeue(&queue));
    printf("Dequeued: %s\n", dequeue(&queue)); // This will show an error because the queue is empty.

    return 0;
}
*/

