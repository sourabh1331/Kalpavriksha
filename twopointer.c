// Finding the Starting Node of a Cycle
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head; 
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    
    return NULL;
}

struct ListNode *createNode(int val) {
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode *createLinkedListWithCycle(int pos) {
    struct ListNode *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    if (pos >= 0) {
        struct ListNode *cycleNode = head;
        for (int i = 0; i < pos; i++) {
            cycleNode = cycleNode->next;
        }
        struct ListNode *tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = cycleNode;
    }

    return head;
}

int main() {

    struct ListNode *head = createLinkedListWithCycle(2);

    struct ListNode *cycleStart = detectCycle(head);

    if (cycleStart != NULL) {
        printf("Cycle starts at node with value: %d\n", cycleStart->val);
    } else {
        printf("No cycle found.\n");
    }

    return 0;
}

/*
time complexity-O(n)
space complexity-O(1)
*/