#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node*root;
struct node*createnode(int val)
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=val;
    return temp;
}
struct node *insert(struct node*naya,int val)
{
    struct node*temp;
    if(naya==NULL)
    {
        return createnode(val);
    }
    else if(val<naya->data)
    {
        naya->left=insert(naya->left,val);
    }
    else
    {
       naya->right=insert(naya->right,val);
    }
    return naya;
}
void preorder(struct node* root)
{
    if (root != NULL) 
    {
       printf("%d \n", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node* root)
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}
void postorder(struct node* root)
{
    if (root != NULL) 
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d \n", root->data);
    }
}
struct node *inOrderSucc(struct node *temp)
{
    while(temp->left!=NULL)
    temp=temp->left;
    return temp;
}
struct node *deleteNode(struct node *temp,int val)
{
    struct node* t;
    if(val<temp->data)
    temp->left=deleteNode(temp->left,val);
    else if(val>temp->data)
    temp->right=deleteNode(temp->right,val);
    else {
        //only for nodes with 0 or 1 child
        if (temp->left == NULL) {
            t = temp->right;
            free(temp);
            return t;
        }

        else if (temp->right == NULL) {
            t = temp->left;
            free(temp);
            return t;
        }
    
        //only for nodes with 2 child
        t=inOrderSucc(temp->right);
        temp->data=t->data;
        temp->right=deleteNode(temp->right, t->data);
    }

    // return temp;
}
void main()
{
    int ch,val;
    struct node*root=NULL;
    do
    {
    printf("1)Insert\n2)PreOrder\n3)Inorder\n4)PostOrder\n5)Delete\n6)Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("Enter value ");
                scanf("%d",&val);
                if(root==NULL)
                root=insert(root,val);
                else
                insert(root,val);
                break;
        case 2:if(root==NULL)
                printf("empty\n");
                else
                preorder(root);
                break;
        case 3:if(root==NULL)
                printf("empty\n");
                else
                inorder(root);
                break;
         case 4:if(root==NULL)
                printf("empty\n");
                else
                postorder(root);
                break;   
        case 5:if(root==NULL)
                printf("empty\n");
                else
                {
            printf("Enter val to be deleted ");
            scanf("%d",&val);
            deleteNode(root,val);
                }
            break;
        case 6:printf("Thank you");
            break;
        default:printf("Invalid\n");
    }
    }while(ch!=6);
}