#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *left;
  int value;
  struct node *right;
};

struct node *create(int item)
{   
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->value=item;
    new->left=NULL;
    new->right=NULL;
    return new;
}

struct node * insert(struct node *root, struct node *temp)
{
    if(temp->value < root->value)
    {
        if(root->left !=NULL)
           root->left=insert(root->left, temp);
        else
            root->left=temp;    
    }
    
    if(temp->value > root->value)
    {
        if(root->right !=NULL)
            root->right=insert(root->right, temp);
        else
            root->right=temp;    
    }
    return root;
}


void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d \t",root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d \t",root->value);
    }
}

void inOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        printf("%d \t",root->value);
        postOrder(root->right);
    }
}

int main()
{
    struct node *root=NULL;
    struct node *temp;
    int n,item;
    while(1)
    {   printf("\n1.Insert node into Binary Search Tree \n 2.Preorder Traversal \n 3.Postorder Traversal \n 4.Inorder Traversal \n 5.Exit \n");
        printf("Enter your choice \n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:printf("Enter the value to be inserted \n");
                   scanf("%d",&item);
                   temp=create(item);
                   if(root==NULL)
                    {
                        root=temp;
                    }
                    else
                    {
                       root=insert(root,temp);
                    }
                    break;
            case 2:printf("Preorder traversal \n");
                    preOrder(root);
                    break;
            case 3:printf("Postorder traversal \n");
                    postOrder(root);
                    break;
            case 4:printf("Inorder traversal \n");
                    inOrder(root);
                    break;
            case 5:exit(0);
                   break;
            default:printf("Enter correct choice \n");
        }
    }  
    return 0;     
}

            
