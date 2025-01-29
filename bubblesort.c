#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newnode=(Node*)malloc(sizeof(Node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void insert_at_head(Node** head_ref,int value) {
    Node* newNode = createNode(value);
    newNode->next = *head_ref;
    *head_ref = newNode;
}

void bubbleSort(Node*head){
    if(head==NULL) return;
    Node* end=NULL;
    int swapped;
    do{
        swapped=0;
        Node* current=head;
        while(current->next!=end){
            if(current->data > current->next->data){

                int temp=current->data;
                current->data=current->next->data;
                current->next->data=temp;
                swapped=1;
            }
            current=current->next;
        }
        end=current;

    }while(swapped);

}

void printList(Node* head){
    Node*temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
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

    bubbleSort(head);

    printf("\nSorted Linked List:\n");
    printList(head);

    return 0;
}