#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert_at_head(Node** head_ref, int data) {
    Node* newnode = createNode(data);
    newnode->next = *head_ref;
    *head_ref = newnode;
}

void insertionSort(Node** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) return;

    Node* sorted = NULL;
    Node* current = *head_ref;

    while (current != NULL) {
        Node* next = current->next;
        
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        
        current = next;
    }
    *head_ref = sorted;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values for the nodes:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insert_at_head(&head, data);
    }

    printf("\nOriginal Linked List:\n");
    printList(head);

    insertionSort(&head);

    printf("\nSorted Linked List:\n");
    printList(head);

    return 0;
}

/*
Time Complexity:
Best-O(n^2)
Avg-O(n^2)
Worst-O(n^2)

space Complexity:O(1)
*/
