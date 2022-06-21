#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *link;
};
struct Node *top;

void Push(int x){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    if(top==NULL){
        temp->data=x;
        temp->link=NULL;
        top=temp;
        return;
    }
    temp->data=x;
    temp->link=top;
    top=temp;
}

void Pop(){
    struct Node *temp=top;
    if(top==NULL){
        return;
    }
    top=top->link;
    free(temp);
}

void Print(){
    struct Node *temp=top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
int main(){
    top=NULL;
    Push(5);
    Push(10);
    Push(15);
    Push(20);
    Print();
    Pop();
    Print();
    // Pop();
    // Print();
}
