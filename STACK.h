
#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE][50];
    int top;
} Stack;

void initializeStack(Stack *stack);

int StackisEmpty(Stack *stack);

void push(Stack *stack,char str[]);

char* pop(Stack *stack);


