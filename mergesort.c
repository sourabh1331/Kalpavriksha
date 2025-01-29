#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* getMiddle(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node* slow = head;
    struct Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

void insert_at_head(struct Node** head_ref, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head_ref;
    *head_ref = newNode;
}

struct Node* merge(struct Node* left, struct Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    if (left->data <= right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

struct Node* mergeSort(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* mid = getMiddle(head);
    struct Node* left = head;
    struct Node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
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

    head = mergeSort(head);

    printf("\nSorted Linked List:\n");
    printList(head);

    return 0;
}

/*
Time Complexity:
Best-O(nlogn)
Avg-O(nlogn)
Worst-O(nlogn)

space Complexity:O(1)
*/