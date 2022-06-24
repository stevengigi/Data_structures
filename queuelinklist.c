#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *rear=NULL;
struct Node *front=NULL;

void addq(int x){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    if(rear==NULL && front==NULL){
        rear=temp;
        front=temp;
        return;
    }else{
        rear->next=temp;
        rear=temp;
    }
}

void deleteq(){
    if(front==NULL){
        printf(" queue is empty\n");
        return;
    }
    struct Node *temp=front;
    front=temp->next;
    free(temp);
}
void print(){
    struct Node *temp=front;
    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    deleteq();
    addq(10);
    addq(7);
    addq(5);
    addq(3);
    deleteq();
    deleteq();
    deleteq();
    print();
    deleteq();
    deleteq();
    printf("---ending---\n");
}