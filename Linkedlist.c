#include <stdio.h>
#include <conio.h>
#include <malloc.h>
//LL--Linked list
struct node
{
    int data;//data in the node-->|data||add|
    struct node*next;//address of next node
};
struct node*head;
//creating node
struct node*createnode()//creating fun to form a node
{
    struct node*temp;//declaring a var. temp that will be the node
    temp=(struct node*)malloc (sizeof(struct node));//storing the data in node
    temp->next=NULL;//assigning the add.
    return temp;
};
//creating linked list
void create_LL()//function creating LL
{
    struct node *temp,*new;
    head=temp=new;
    int n=9;
    printf("To make a node enter y : ");
    scanf("%d",&n);

    while(n==9)
    {
        new=createnode();//declaring a var. that makes a node new using the fun
        printf("Enter the data : ");//enter the data here 
        scanf("%d",&new->data);
        if(head==NULL)//if head is null i.e. there is no LL(as no node present) so creating a node head and temp
        {
            head=new;//first node in LL
            temp=new;//temp node t
            head->next=temp;//assing the add of temp in head
        }
        else
        {
            temp->next=new;//assigning the add. of new in temp 
            temp=new;//making temp new so new can be use again          
        }  
        printf("To make a node enter y : ");
        scanf("%d",&n);          
    }
    getch();
}
//inserting
// void insert_head()
// {
//     struct node *temp,*new;
//     new=createnode();
//     printf("Enter data in head : ");
//     scanf("%d",&new->data);
//     temp=head;
//     if(head==NULL)
//     {
//         head=new;
//     }
//     else
//     {
//         new->next=temp;
//         head=new;  
//     }
//     getch();    
// }
//display fun for LL
void display()
{
    struct node*temp;
    {
        temp=head;
        if(temp==NULL)
        {
            printf("Linkled list not present");
        }
        else
        {
            while(head!=NULL)
            {
                printf("%d\t",temp->data);//printing the LL and stops when NULL occurs
                temp=temp->next;
            }
        }
    };
    getch();
}

void main()
{
    create_LL();
    display();
    // insert_head();
    // display();
    getch();
}