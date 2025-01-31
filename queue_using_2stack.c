#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Stack {
    int item[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->item[++s->top] = value;
    printf("Pushed %d onto the stack\n", value);
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->item[s->top--];
}

typedef struct Queue {
    Stack s1, s2;
} Queue;

void initializeQueue(Queue *q) {
    initializeStack(&q->s1);
    initializeStack(&q->s2);
}

void enqueue(Queue *q, int value) {
    push(&q->s1, value);
}

int dequeue(Queue *q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    if (isEmpty(&q->s2)) {
        printf("Queue is empty\n");
        return -1;
    }
    return pop(&q->s2);
}

void display(Queue *q) {
    if (!isEmpty(&q->s2)) {
        printf("Queue: ");
        for (int i = q->s2.top; i >= 0; i--) {
            printf("%d ", q->s2.item[i]);
        }
    } else if (!isEmpty(&q->s1)) {
        printf("Queue: ");
        for (int i = 0; i <= q->s1.top; i++) {
            printf("%d ", q->s1.item[i]);
        }
    } else {
        printf("Queue is empty");
    }
    printf("\n");
}

int main() {
    Queue q;
    initializeQueue(&q);
    int choice, value;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                printf("Dequeued: %d\n", dequeue(&q));
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
