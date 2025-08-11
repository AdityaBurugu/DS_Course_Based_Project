//
// Created by aditya on 8/11/25.
//

#ifndef STUDENT_DATA_MANAGEMENT_SYSTEM_STACK_H
#define STUDENT_DATA_MANAGEMENT_SYSTEM_STACK_H

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE][50];
    int top;
} Stack;

void initializeStack(Stack *stack);

int StackisFull(Stack *stack);

int StackisEmpty(Stack *stack);

void push(Stack *stack,char str[]);

char* pop(Stack *stack);

#endif //STUDENT_DATA_MANAGEMENT_SYSTEM_STACK_H