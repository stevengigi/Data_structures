#include<stdio.h>
#include<stdlib.h>
#define hash_size 10 // 0~9
//可以想像是一個二維陣列 for headtable
// 0: 10 50 60 70
// 1: 51 21 31
struct node{
    int value;
    struct node *next;
};
struct node **getheadtable(){
    struct node  **headtable=(struct node**)calloc(hash_size,sizeof(struct node*));
    return headtable;
}
int hashfun(int value){
    if(value<0){
        value =value * -1;
    }
    return value % hash_size;
}
void insert_node(struct node **head,int value){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->value=value;
    temp->next=NULL;
    if(*head==NULL){
        *head=temp;
        printf("test!!\n");
    }else{
        struct node *current=*head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=temp;
    }

}
void insert_table(struct node **head,int value){
    int index=hashfun(value);
    if(head[index]==NULL){
        head[index]=(struct node*)malloc(sizeof(struct node));
        struct node *temp=NULL;
        insert_node(&temp,value);
        head[index]=temp;
    }else{
        struct node *temp=head[index];
        insert_node(&temp,value);
    }
}
void displaytable(struct node **head){
    for(int i=0;i<hash_size;i++){
        printf(" %d : ",i);
        if(head[i]==NULL){
            printf("\n");
            continue;
        }else{
            struct node *temp=head[i];
            while(temp!=NULL){
                printf(" (%d) ",temp->value);
                temp=temp->next;
            }
            printf("\n");
        }
    }
}
void delete(struct node **head,int value){
    int index=hashfun(value);
    struct node *temp=head[index];
    struct node *temp2;
    while(temp->value!=value){
        temp2=temp;
        if(temp->next==NULL){
            printf("Didnt find data\n");
            return;
        }
        temp=temp->next;
    }
    temp2->next=temp->next;
    free(temp);
}
void findvalue(struct node **head,int value){
    int index=hashfun(value);
    struct node *temp=head[index];
    while(temp!=NULL){
        if(temp->value==value){
            printf("I find it !!\n");
            return;
        }else{
            temp=temp->next;
        }
    }
}

int main(){
    struct node **head=getheadtable();
    insert_table(head,10);
    insert_table(head,5);
    insert_table(head,3);
    insert_table(head,1);
    insert_table(head,15);
    insert_table(head,11);
    insert_table(head,12);
    insert_table(head,13);
    insert_table(head,14);
    insert_table(head,16);
    displaytable(head);
    findvalue(head,15);
    delete(head,15);
    displaytable(head);
    insert_table(head,15);
    insert_table(head,11);
    insert_table(head,12);
    insert_table(head,13);
    insert_table(head,14);
    insert_table(head,16);
    displaytable(head);

}