//
// Created by aditya on 8/11/25.
//

#ifndef STUDENT_DATA_MANAGEMENT_SYSTEM_QUEUE_H
#define STUDENT_DATA_MANAGEMENT_SYSTEM_QUEUE_H

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE][50];
    int front;
    int rear;
} Queue;


void initializeQueue(Queue *queue);

int QueueisFull(Queue *queue);

int QueueisEmpty(Queue *queue);

void enqueue(Queue *queue, char str[]);

char* dequeue(Queue *queue);

#endif //STUDENT_DATA_MANAGEMENT_SYSTEM_QUEUE_H