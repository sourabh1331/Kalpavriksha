#include <stdio.h>
#include <stdlib.h>
#define Max_size 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct queue {
    struct Node* front;
    struct Node* rear;
    int size;
} queue;

void initqueue(queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int isEmpty(queue* q) {
    return q->size == 0;
}

Node* createNode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void enqueue(queue* q, int data) {
    Node* newnode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
    q->size++;
}

int dequeue(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return data;
}

int getsize(queue* q) {
    return q->size;
}

void display(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue q;
    initqueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Queue after enqueuing 10, 20, 30: ");
    display(&q);
    printf("Queue size: %d\n", getsize(&q));

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Queue after dequeue: ");
    display(&q);
    printf("Queue size: %d\n", getsize(&q));

    return 0;
}
