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

void sortedInsert(Node** sorted_ref, Node* new_node) {
    if (*sorted_ref == NULL || (*sorted_ref)->data >= new_node->data) {
        new_node->next = *sorted_ref;
        *sorted_ref = new_node;
    } else {
        Node* current = *sorted_ref;
        while (current->next != NULL && current->next->data < new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void insertionSort(Node** head_ref) {
    Node* sorted = NULL;
    Node* current = *head_ref;

    while (current != NULL) {
        Node* next = current->next;
        sortedInsert(&sorted, current);
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
Best-O(n)
Avg-O(n^2)
Worst-O(n^2)

space Complexity:O(1)

*/
