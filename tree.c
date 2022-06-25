#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};


struct Node *front=NULL;
struct Node *rear=NULL;

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

int findmin(struct Node *root){
    if(root==NULL){
        return -1;
    }else if(root->left==NULL){
        return root->data;
    }else{
        return findmin(root->left);
    }
}

int findmax(struct Node *root){
    if(root==NULL){
        return -1;
    }else if(root->right==NULL){
        return root->data;
    }else{
        return findmin(root->right);
    }
}

int findheight(struct Node *root){
    if(root==NULL){
        return -1;
    }else{
        int leftheight=findheight(root->left);
        int rightheight=findheight(root->right);
        if(leftheight>rightheight){
            return leftheight+1;
        }else{
            return rightheight+1;
        }
    }
}

void addq(struct Node *root){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp=root;
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
        return;
    }
    struct Node *temp=front;
    front=temp->next;
    //free(temp);
}

void levelorder(){
    if(root==NULL){
        return;
    }

    addq(root);
    printf("LevelOrder : ");
    while(front!=NULL)
    {
        struct Node *temp=front;
        printf(" %d ",temp->data);
        if(temp->left!=NULL) addq(temp->left);
        if(temp->right!=NULL) addq(temp->right);
        deleteq();
    }
    printf("\n");
}
//(DLR)
void preorder(struct Node* root){
    if(root == NULL){
        return;
    }
    printf(" %d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
//(LDR)
void inorder(struct Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf(" %d ",root->data);
    inorder(root->right);
}
//(LRD)
void postorder(struct Node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf(" %d ",root->data);
}

int main(){
    root=insert(root,15);
    root=insert(root,10);
    root=insert(root,25);
    root=insert(root,5);
    root=insert(root,7);
    root=insert(root,3);
    root=insert(root,8);
    int number;
    printf("Enter the number which you want to find:");
    scanf("%d",&number);
    if(search(root,number)){
        printf("\nfind it !!\n");
    }else{
        printf("\nNot find !!\n");
    }
    printf("the max value in tree : %d\n",findmax(root));
    printf("the min value in tree : %d\n",findmin(root));
    printf("the tree of height : %d\n",findheight(root)+1);
    levelorder();
    printf("Preorder : ");
    preorder(root);
    printf("\n");
    printf("Inorder : ");
    inorder(root);
    printf("\n");
    printf("Postorder : ");
    postorder(root);
    printf("\n");

}