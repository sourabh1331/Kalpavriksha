#include <stdio.h>
#include <stdlib.h>

#define Max_size 100

typedef struct Stack {
    int items[Max_size];
    int top;
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == Max_size - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
    } else {
        s->top++;
        s->items[s->top] = value;
        printf("Pushed %d onto the stack\n", value);
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int value = s->items[s->top];
        s->top--;
        printf("Popped %d from the stack\n", value);
        return value;
    }
}

void enqueue(Stack *s,int value){
    push(s,value);
}

void dequeue(Stack *s){
    if(isEmpty(s)){
        printf("Queue is empty");
        return -1;
    }
    int item=dequeue(s);
    push(s,x);
    return item;
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&s, value);
                break;
            case 2:
                printf("Dequeued: %d\n", dequeue(&s));
                break;
            case 3:
                display(&s);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
