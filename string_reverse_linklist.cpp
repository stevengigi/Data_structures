#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

struct Node{
    char c;
    struct Node *next;
};
struct Node *head;

void reverse(char *c,int length){
    stack<char> s;
    for(int i=0;i<length;i++){
        s.push(c[i]);
    }
    for(int i=0;i<length;i++){
        c[i]=s.top();
        s.pop();
    }
}

void reverse1(){
    stack<struct Node*> s;
    struct Node *temp=head;
    while(temp!=NULL){
        s.push(temp);
        temp=temp->next;
    }
    struct Node *temp=s.top();
    head=temp;
    s.pop();
    while(!s.empty()){
        temp->next=s.top();
        s.pop();
        temp=temp->next;
    }
    temp->next=NULL;
}

void push(char c){
    struct Node *temp=head;
    temp->c=c;
    if(head==NULL){
        temp->next=NULL;
        head=temp;
        return;
    }
    temp->next=head;
    head=temp;
}

void Print(){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%c ",temp->c);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    char c[51];
    char c1[51];
    printf("enter a string:");
    gets(c);
    reverse(c,strlen(c));
    printf("\n%s",c);

    head=NULL;
    push('h');
    push('e');
    push('l');
    push('l');
    push('o');
    push(' ');
    push('w');
    push('o');
    push('r');
    push('l');
    push('d');
    reverse1();
    Print();
    return 0;
}