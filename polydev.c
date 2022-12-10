#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff,power;
    struct node *next;
};
struct node *start1,*start2,*start3;
struct node *createnode()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    return temp;
}
struct node* createlist(int num,struct node* head)
{
    struct node *temp,*n;
    head=NULL;
    temp=NULL;
    while(num>0)
    {
        n=createnode();
        printf("Enter coeff and power ");
        scanf("%d %d",&n->coeff,&n->power);
        if(head==NULL)
        {
            head=n;
            temp=n;
        }
        else
        {
            temp->next=n;
            temp=n;
        }
        num--;
    }
    return head;
}
void display(struct node*head)
{
    struct node *temp;
    temp=head;
    if(temp==NULL)
    printf("LL not present");
    else
    {
        while(temp!=NULL)
        {
            printf("%dx^%d ",temp->coeff,temp->power);
            temp=temp->next;
        }
    }
}
void addnode(int c,int p)
{
    struct node *sum,*temp;
    sum=createnode();
    sum->coeff=c;
    sum->power=p;
    if(start3==NULL)
    {
        start3=sum;
        temp=sum;
    }
    else
    {
        temp->next=sum;
        temp=sum;
    }
}
void main()
{
    int n1,n2,c;
    struct node *t1,*t2;
    printf("enter no. of elements in l1 ");
    scanf("%d",&n1);
    start1=createlist(n1,start1);
    printf("enter no. of elements in l2 ");
    scanf("%d",&n2);
    start2=createlist(n2,start2);
    t1=start1;
    t2=start2;
    while(t1!=NULL && t2!=NULL)
    {
        if(t1->power==t2->power)
        {
            c=t1->coeff+t2->coeff;
            addnode(c,t1->power);
            t1=t1->next;
            t2=t2->next;
        }
        else if(t1->power>t2->power)
        {
            addnode(t1->coeff,t1->power);
            t1=t1->next;
        }
        else
        {
            addnode(t2->coeff,t2->power);
            t2=t2->next;
        }
    }

    while(t1!=NULL)
    {
        addnode(t1->coeff,t1->power);
        t1=t1->next;
    }
    while(t2!=NULL)
    {
        addnode(t2->coeff,t2->power);
        t2=t2->next;
    }
    
    display(start1);
    printf("\n");
    display(start2);
    printf("\n");
    display(start3);
}