#include<stdio.h>
#include<stdlib.h>

struct  Node
{
    int data;
    struct Node *next;
};

struct Node *head; //global var ,can be accessed anywhere

//Insert Node at position n
void insert(int data,int n){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    if(n==1){
        temp->next=head;
        head=temp;
        return ;
    }
    struct Node* temp2=head;

    for(int i=1;i<n-1;i++){
        temp2=temp2->next;
    }
    temp->next=temp2->next;
    temp2->next=temp;
}
//Delete node at position n
void Delete(int n){
    struct Node *temp=head;
    if(n==1){
        head=temp->next;
        free(temp);
        return;
    }
    for(int i=1;i<n-1;i++){
        temp=temp->next;
    }
    struct Node *temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);

}
//Reverse Link List
void Reverse(){
    struct Node *current=head;
    struct Node *prev=NULL;
    struct Node *next;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
//Reverse Link List with Recursive
void RecursiveReverse(struct Node *temp){
    if(temp->next==NULL){
        head=temp;
        return;
    }
    RecursiveReverse(temp->next);
    struct Node *temp2=temp->next ;
    temp2->next=temp;
    temp->next=NULL;
}

//Use recursive method
void Print(struct Node *temp){
   if(temp!=NULL){
    printf("%d ",temp->data);
   }else{
    printf("\n");
    return;
   }
   temp=temp->next;
   Print(temp);
}

void ReversePrint(struct Node *temp){
    if(temp!=NULL){
        ReversePrint(temp->next);
    }else{
        return;
    }
    printf("%d ",temp->data);
}

int main(){

    head=NULL;
    insert(5,1);
    insert(4,1);
    insert(7,2);
    insert(8,2);
    insert(9,2);
    Print(head);
    Delete(3);
    Print(head);
    Delete(1);
    Print(head);
    Reverse();
    Print(head);
    ReversePrint(head);
    printf("\n");
    RecursiveReverse(head);
    Print(head);
    insert(7,2);
    insert(8,2);
    insert(9,2);
    Print(head);
    RecursiveReverse(head);
    Print(head);
}