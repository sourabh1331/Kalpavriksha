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

void insertNode_end(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct Node* findMiddle(struct Node* start, struct Node* end) {
    if (start == NULL) return NULL;

    struct Node* slow = start;
    struct Node* fast = start->next;

    while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

struct Node* binarySearch(struct Node* head, int value) {
    struct Node* start = head;
    struct Node* end = NULL;

    do {
        struct Node* mid = findMiddle(start, end);

        if (mid == NULL) return NULL;

        if (mid->data == value) {
            return mid;
        } else if (mid->data < value) {
            start = mid->next;
        } else {
            end = mid;
        }
    } while (end == NULL || end != start);

    return NULL;
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

    insertNode_end(&head, 10);
    insertNode_end(&head, 20);
    insertNode_end(&head, 30);
    insertNode_end(&head, 40);
    insertNode_end(&head, 50);
    insertNode_end(&head, 60);
    insertNode_end(&head, 70);

    printf("Linked List: ");
    printList(head);

    int value = 40;
    struct Node* result = binarySearch(head, value);

    if (result != NULL) {
        printf("Element %d found in the linked list.\n", value);
    } else {
        printf("Element %d not found in the linked list.\n", value);
    }

    return 0;
}

/*
Time Complexity-Finding Middle-O(n)
Binary search(overall)-O(nlog n)

Space Complexity-O(1)
*/