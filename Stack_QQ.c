#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head;

struct node*createnode()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp ->next = NULL;
    return temp;
}

// void createLL(int n, struct node *head)
// {
//     struct node *temp, *new1;
//     int val;
//     temp = head;
//     while (n>0)
//     {
//         printf("\nEnter : ");
//         scanf("%d",&val);
//         new1= createnode();
//         new1->data = val;
//         if(temp == NULL)
//         {
//             head = new1;
//             temp = new1;
//         }
//         else
//         {
//             temp -> next = new1;
//             temp = new1;
//         }
//         n--;
//     }  
//     return head;
// }

void display()
{
    struct node *temp;
    temp = head;
    if(temp == NULL)
    {printf("Empty ");}
    else
    {
        while (temp !=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }  
    }
}

void insert_end(int val)
{
    struct node *temp, *new1;
    temp =head;
    new1 = createnode();
    new1->data=val;
    if(temp == NULL)
    {
        head=new1;
        temp=new1;
    }
    else
    {
    while (temp->next != NULL)
    {temp = temp->next;}
    temp->next = new1;
    temp=new1; 
    }
}

void delete_front()
{
    struct node *temp, *back;
    temp =head;
    back = NULL;
    if(head == NULL)
    {printf("\nEmpty");}
    else if (head->next==NULL)
    {
        printf("\npoped head : %d",temp->data);
        head=NULL;
        free(temp);
    }
    else
    {
        head=temp->next;
        temp->next=NULL;
        printf("\npoped : %d",temp->data);
        free(temp);
    }    
}

void delete_end()
{
    struct node *temp, *back;
    temp =head;
    back = NULL;
    if(head == NULL)
    {printf("\nEmpty");}
    else if (head->next==NULL)
    {
        printf("\npoped head : %d",temp->data);
        head=NULL;
        free(temp);
    }
    else
    {
        while(temp->next!=NULL)
        {
            back=temp;
            temp=temp->next;
        }
        back->next=NULL;
        printf("\npoped : %d",temp->data);
        free(temp);
    }
}


void main()
{
    int n=0,c;
    while(n<5){ 
         printf("\nEnter the choice : ");
    scanf("%d",&n);
    switch(n)
    {
        case 1 : 
        {
            printf("\nEnter : ");
            scanf("%d",&c);
            insert_end(c);break;}
        case 2 : delete_end();break;
        case 3 : delete_front();break;
        case 4 : display();break;
    }
    }
}