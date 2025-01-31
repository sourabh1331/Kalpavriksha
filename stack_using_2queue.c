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
    if(q->front == -1) q->front = 0;
    q->rear = (q->rear + 1);
    q->queue[q->rear] = value;
    q->size++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->queue[q->front];
    q->front = (q->front + 1);
    q->size--;
    return value;
}

int getSize(Queue* q) {
    return q->size;
}

void push(Queue*q1,Queue*q2,int value){
    enqueue(q1,value);
}

int pop(Queue*q1,Queue*q2){
    if(isEmpty(q1)){
        printf("Stack is empty");
        return -1;
    }
    while(q1->front!=q1->rear){
        enqueue(q2,dequeue(q1));//Move all elements except the last
    }
    int value=dequeue(q1);

    Queue*temp=q1;
    q1=q2;
    q2=temp;

    return value;
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
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&q1,&q2,value);
                break;
            case 2:
                printf("Popped: %d\n", pop(&q1,&q2));
                break;
            case 3:
                display(&q1);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
