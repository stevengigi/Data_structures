#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head;

struct Node* GetNewNode(int x){
    struct Node *NewNode =(struct Node*)malloc(sizeof(struct Node));
    NewNode->data=x;
    NewNode->next=NULL;
    NewNode->prev=NULL;
    return NewNode;
}

void InsertHead(int x){
    struct Node *temp =GetNewNode(x);
    if(head==NULL){
        head=temp;
        return;
    }
    head->prev=temp;
    temp->next=head;
    head=temp;
}

void Print(){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    head=NULL;
    InsertHead(5);
    InsertHead(10);
    InsertHead(15);
    InsertHead(20);
    InsertHead(25);
    Print();
    return 0;
}