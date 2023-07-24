
#define MAX_SIZE 100

typedef struct 
{
    char data[MAX_SIZE][50];
    int front;
    int rear;
} Queue;

int QueueisFull(Queue *queue);

int QueueisEmpty(Queue *queue);

void enqueue(Queue *queue, char str[]);

char* dequeue(Queue *queue);
