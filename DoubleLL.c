#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node*next;
    struct node*prev; 
};

struct node*head;

struct node*createnode()
{
    struct node*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp ->next=NULL;
    temp->prev=NULL;
    return temp;
}

void insertnode(int val)
{
    struct node*temp, *new1;
    temp=head;
    new1=createnode();
    new1->data= val;

    if(head==NULL)
    {
        head = new1;
        new1->prev = new1->next= NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = new1;
        new1->prev = temp;
        temp=new1;
    }
}

void delete(int val)
{
    struct node*temp;
    temp=head;
    pri = NULL;
    if(temp==NULL)
        {printf("LL empty");}
    else
    {
        while(temp!=NULL)
        {
            if(temp->data==val)
            {
                temp->prev = temp->next;
            }
            temp = temp->next;
            pri = temp->prev;
            pri ->next = 

        }
    }
}

void display()
{
    struct node *temp;
    temp=head;
    if(temp==NULL)
        {printf("LL empty");}
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
    }
}

void main()
{
    int c=0,val;
    
    
    
    while(c < 4){
        printf("\nEnter the choice : ");
    scanf("%d",&c);
    switch(c)
    {
        case 1: 
        {
            printf("\nEnter the val : ");
            scanf("%d",&val);
            insertnode(val);
            break;
        }

        case 2:
           { display();
           break;}
        
        case 3 : 
            exit(0);
    }
    
    }
}