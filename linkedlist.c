#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(int position, int value) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    Node* newNode = createNode(value);
    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void updateAtPosition(int position, int newValue) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    temp->data = newValue;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Delete at a specific position
void deleteAtPosition(int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        deleteAtBeginning();
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x;
            scanf("%d", &x);
            insertAtEnd(x);
        } else if (op == 2) {
            int x;
            scanf("%d", &x);
            insertAtBeginning(x);
        } else if (op == 3) {
            int pos, x;
            scanf("%d %d", &pos, &x);
            insertAtPosition(pos, x);
        } else if (op == 4) {
            display();
        } else if (op == 5) {
            int pos, x;
            scanf("%d %d", &pos, &x);
            updateAtPosition(pos, x);
        } else if (op == 6) {
            deleteAtBeginning();
        } else if (op == 7) {
            deleteAtEnd();
        } else if (op == 8) {
            int pos;
            scanf("%d", &pos);
            deleteAtPosition(pos);
        } else {
            printf("Invalid operation\n");
        }
    }
    return 0;
}