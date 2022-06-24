#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root=NULL;

struct Node *getnewnode(int data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct Node *insert(struct Node *root,int data){
    if(root==NULL){
        root=getnewnode(data);
    }else if(data <= root->data){
        root->left=insert(root->left,data);
    }else{
        root->right=insert(root->right,data);
    }
    return root;
}

bool search(struct Node *root,int data){
    if(root==NULL){
        return false;
    }else if(data == root->data){
        return true;
    }else if(data < root->data){
        return search(root->left,data);
    }else{
        return search(root->right,data);
    }
}

int main(){
    root=insert(root,15);
    root=insert(root,10);
    root=insert(root,25);
    root=insert(root,5);
    root=insert(root,7);
    int number;
    printf("Enter the number which you want to find:");
    scanf("%d",&number);
    if(search(root,number)){
        printf("\nfind it !!\n");
    }else{
        printf("\nNot find !!\n");
    }
}