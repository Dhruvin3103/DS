#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *createnode(int val)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = val;
    return temp;
}


struct node *createBST(struct node *root,int val)
{
    struct node *temp, *new1;
    int n;
    if(root==NULL)
    {return createnode(val);}
    else if(root->data > val)
        {printf(" left %d \n",root->data); root->left = createBST(root->left,val);}
    else
        {printf(" right %d \n", root->data); root->right = createBST(root->right,val);}
    printf("return kar rah");
    return root;
}

void inorder(struct node *root)
{
    if(root == NULL)
    {return;}
    inorder(root->left);
    printf("%d \t", root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if(root == NULL)
    {return;}
    postorder(root->left);
    postorder(root->right);
    printf("%d \t", root->data);
}

void preorder(struct node *root)
{
    if(root == NULL)
    {return;}
    printf("%d \t", root->data);
    preorder(root->left);
    preorder(root->right);
}

void insuc()
{
    
}


void main()
{
    struct node *root=NULL;
    int c =0,n;
    while(c<2)
    {printf("\nEnter choice : ");
    scanf("%d",&c);
    switch(c)
    {
        case 1 : 
        {
            
            if(root==NULL)
            {printf("Enter the root data : ");
            scanf("%d",&n);
            root = createBST(root,n);}
            else
            {printf("Enter the data : ");
            scanf("%d",&n);
            // printf("root %d \n",root->data);
                createBST(root,n);}
            
        
        break;}
    }
    }
    printf("root : %d",root->data);
    printf("\ninorder   : ");inorder(root);
    printf("\npostorder : ");postorder(root);
    printf("\npreorder  : ");preorder(root);
}