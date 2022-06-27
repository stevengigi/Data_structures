#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define maxsize 20
int size=-1;

int parent(int x){
    return (x-1)/2;
}

int leftchild(int x){
    return 2*x+1;
}

int rightchild(int x){
    return 2*x+2;
}
void swap(int *x,int *y){
    int temp=*y;
    *y=*x;
    *x=temp;
}

void insert(int *array,int data){
    if(size==-1){
        size++;
        array[size]=data;
        return;
    }else if(size==maxsize){
        printf("the array is full");
        return;
    }else{
        size++;
        array[size]=data;
        int i=size;
        while(i!=0 && array[parent(i)] > array[i]){
            swap(&array[i],&array[parent(i)]);
            i=parent(i);
        }
    }
}

void min_heapify(int *array,int position){
    int left=leftchild(position);
    int right=rightchild(position);
    int min=position;
    if(left<=size && array[left]<array[min]){
        min=left;
    }
    if(right<=size && array[right]<array[min]){
        min=right;
    }
    if(min!=position){
        swap(&array[min],&array[position]);
        min_heapify(array,min);
    }

}

void delete(int *array,int data){
    int flag=0;
    int i=0;
    for(i=0;i<=size;i++){
        if(array[i]==data){
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf(" No data in array\n");
        return;
    }else{
        swap(&array[i],&array[size]);
        size--;
        min_heapify(array,i);
    }
}

void min_sort(int *array,int *sort,int length){
    printf("sort : ");
    for(int i=0;i<=length;i++){
        sort[i]=array[0];
        delete(array,array[0]);
        printf(" %d ",sort[i]);
    }
    printf("\n");
}
void printarray(int *array){
    for(int i=0;i<=size;i++){
        printf(" %d ",array[i]);
    }
    printf("\n");
}

int main(){
    int array[maxsize];
    int sort[maxsize];
    unsigned int seed=time(NULL);
    srand(seed);
    for(int i=0;i<15;i++){
        insert(array,rand()%15);
    }
    printarray(array);
    delete(array,2);
    printarray(array);
    min_sort(array,sort,size);
}