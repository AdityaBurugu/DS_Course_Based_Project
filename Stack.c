//
// Created by aditya on 8/11/25.
//

#include "Stack.h"

#include <stdio.h>
#include <string.h>

void initializeStack(Stack *stack) {
    stack->top = -1;
}

int StackisFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

int StackisEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack,char str[]) {
    if (StackisFull(stack)) {
        printf("Error: Stack is full, cannot push more elements.\n");
        return;
    }

    strcpy(stack->data[++stack->top], str);
}

char* pop(Stack *stack) {
    if (StackisEmpty(stack)) {
        printf("Error: Stack is empty, cannot pop an element.\n");
        return NULL;
    }
    return stack->data[stack->top--];
}
