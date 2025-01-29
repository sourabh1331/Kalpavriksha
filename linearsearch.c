#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert_at_head(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int linearSearch(struct Node* head, int key) {
    struct Node* current = head;
    int position = 0;

    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, data, key;

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

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    int result = linearSearch(head, key);
    if (result != -1) {
        printf("Element %d found at position %d\n", key, result);
    } else {
        printf("Element %d not found in the list\n", key);
    }

    return 0;
}

/*
Time Complexity:
Best-O(1)
Worst-O(n)

space-O(1)
*/