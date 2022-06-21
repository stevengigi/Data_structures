#include<Stdio.h>

#define max_size 101

int A[max_size];
int top=-1;

void Push(int x){
    if(top==max_size){
        printf("Error :stack overflow\n");
        return;
    }
    A[++top]=x;
}

void Pop(){
    if(top==-1){
        printf("No value in array\n");
        return;
    }
    A[top]=0;
    top--;
}

void Print(){
    int index=0;
    while(index <= top){
        printf("%d ",A[index]);
        index++;
    }
    printf("\n");
}

int main(){
    Push(5);
    Push(6);
    Push(7);
    Push(8);
    Push(9);
    Print();
    Pop();
    Print();
    Push(10);
    Print();
}