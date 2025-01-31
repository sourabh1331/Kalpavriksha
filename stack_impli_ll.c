#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
    int size;
} Stack;

void initStack(Stack* s) {
    s->top = NULL;
    s->size = 0;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top; 
    s->top = newNode;
    s->size++;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    Node* temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return value;
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->top->data;
}

int getSize(Stack* s) {
    return s->size;
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = s->top;
    printf("Stack: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Stack after push operations: ");
    display(&s);
    printf("Stack size: %d\n", getSize(&s));

    printf("Popped: %d\n", pop(&s));
    printf("Stack after pop: ");
    display(&s);
    printf("Stack size: %d\n", getSize(&s));

    printf("Top element: %d\n", peek(&s));

    return 0;
}
