#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*next;
}node;

typedef struct stack{
    node*top;
}stack;

void initstack(stack*s){
    s->top=NULL;
}

node*createNode(int value){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=NULL;

    return newnode;
}

void push(stack*s,int value){
    node*newnode=createNode(value);
    newnode->next=s->top;
    s->top=newnode;

}

int isempty(stack*s){
    return s->top==NULL;
}

int pop(stack*s){
    if(isempty(s))return -1;
    node*temp=s->top;
    int data=temp->data;
    s->top=s->top->next;
    return data;
}

void next_greater_elemnt(int arr[],int n,int result[]){
    stack *s = (stack *)malloc(sizeof(stack));
    initstack(s);
    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!isempty(s) && s->top->data <= arr[i % n]) {
            pop(s);
        }
        if (i < n) {
            if (isempty(s)) {
                result[i] = -1;
            } else {
                result[i] = s->top->data;
            }
        }
        push(s, arr[i % n]);
    }

}
int main() {
    int A[] = {3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9};
    int N = sizeof(A) / sizeof(A[0]);
    int result[N];
    
    next_greater_elemnt(A, N, result);
    
    for (int i = 0; i < N; i++) {
        printf("%d%s", result[i], (i == N - 1) ? "\n" : ",");
    }
    
    return 0;
}