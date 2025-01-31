#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Queue{
    int queue[MAX_SIZE];
    int front, rear, size;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

int isFull(Queue* q) {
    return q->size == MAX_SIZE;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if(q->front==-1)q->front=0;
    q->rear = (q->rear + 1);
    q->queue[q->rear] = value;
    q->size++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value=q->queue[q->front];
    q->front++;
    q->size--;
    return value;
}

int getSize(Queue* q) {
    return q->size;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i < q->rear+1; i++) {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    int choice, value;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Get Size\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                printf("Queue size: %d\n", getSize(&q));
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
