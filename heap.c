#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define maxsize 20
//maxheap
int size=-1;

void swap(int*x,int*y){
    int z=*y;
    *y=*x;
    *x=z;
}

int parent(int x){
    return (x-1)/2;
}

int leftchild(int x){
    return 2*x+1;
}

int rightchild(int x){
    return 2*x+2;
}

void max_heapify(int *array ,int position){
    int left=leftchild(position);
    int right=rightchild(position);
    int large=position;
    if(left <= size && array[large] < array[left]){
        large=left;
    }
    if(right <=size && array[large] < array[right]){
        large = right;
    }
    if(large!=position){
        swap(&array[large],&array[position]);
        max_heapify(array,large);
    }
}

void insert(int *array ,int data){
    if(size==-1){
        size++;
        array[size]=data;
        return;
    }else if(size == maxsize){
        printf("The heap is full");
        return;
    }else{
        size++;
        array[size]=data;
        int i=size;
        while(array[parent(i)]<array[i]){
            swap(&array[parent(i)],&array[i]);
            i=parent(i);
        }
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
        printf("no data in array\n");
        return;
    }
    swap(&array[i],&array[size]);
    size--;
    max_heapify(array,i);

}

void max_heap_sort(int *array,int *sort){
    int index=size;
    for(int i=0;i<=index;i++){
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

int get_max(int *array){
    return array[0];
}

void reverse(int *sort ,int start,int end){
    while(start<end){
        swap(&sort[start],&sort[end]);
        start++;
        end--;
    }
}

void printsort(int *sort){
    printf("sort : ");
    for(int i=0;i<size;i++){
        printf(" %d ",sort[i]);
    }
    printf("\n");
}

void make_max_heap(int *array,int n){
    for(int i=(n-1)/2;i>=0;i--){
        max_heapify(array,i);
    }
}

int main(){
    int array[maxsize];
    int sort[maxsize];
    insert(array,5);
    insert(array,8);
    insert(array,3);
    insert(array,9);
    insert(array,1);
    insert(array,10);
    insert(array,11);
    insert(array,12);
    insert(array,13);
    printarray(array);

    delete(array,13);
    printarray(array);

    printf(" max : %d\n",get_max(array));
    //final to get sorted
    max_heap_sort(array,sort);

    insert(array,1);
    insert(array,2);
    insert(array,3);
    insert(array,4);
    insert(array,5);
    insert(array,6);
    insert(array,7);
    insert(array,8);
    insert(array,9);
    insert(array,10);
    printarray(array);
    max_heap_sort(array,sort);

    printf("size : %d\n",size);

    int n=10;
    unsigned int seed =time(NULL);
    srand(seed);

    for(int i=0;i<n;i++){
        size++;
        array[i]=rand()%15;
    }
    printarray(array);
    make_max_heap(array,n);
    printarray(array);
    max_heap_sort(array,sort);
}