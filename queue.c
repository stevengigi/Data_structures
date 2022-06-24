#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 10

int A[N];
int rear=-1;
int front=-1;

bool isfull(){
    if((rear+1)%N==front){
        return true;
    }else{
        return false;
    }
}

bool isempty(){
    if(front==rear || (rear==-1 && front==-1)){
        return true;
    }else{
        return false;
    }
}

void addq(int data){
    if(isfull()){
        printf("queue is full !! \n");
        return;
    }else if(front== -1 && rear==N-1){
        printf("queue is full !! \n");
        return;
    }else{
        rear=(rear+1)%N;
        A[rear]=data;
    }
}

void deleteq(){
    if(isempty()){
        printf("queue is empty \n");
        return;
    }
    front=(front+1)%N;
}

void print(){
    int a=front;
    while(a!=rear){
        a=(a+1)%N;
        printf("%d ",A[a]);
    }
    printf("\n");
}

int main(){
    addq(1);
    addq(2);
    addq(3);
    addq(4);
    addq(5);
    addq(6);
    addq(7);
    addq(8);
    addq(9);
    addq(10);
    print();
    addq(11);
    deleteq();
    print();
}