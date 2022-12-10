#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    int pow;
    struct node*next;
};

struct node *start, *start1, *start2;

struct node*createnode()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> next = NULL;
    return temp;
}

struct node *insert(int n, struct node* head)
{
    struct node *temp, *new1;
    int val, val2;
    head = NULL;
    temp=head;
    while(n>0)
    {
    printf("\nEnter the coeff : ");
    scanf("%d",&val);
    printf("\nEnter the power : ");
    scanf("%d",&val2);
    new1 = createnode();
    new1->data = val;
    new1->pow = val2;
    if(head == NULL)
    {

        head = new1;
        temp = new1;
        // head->next = temp;
    }
    else
    {
        temp->next = new1;
        temp=new1;
    }
    n--;
    }
    return head;
}

void add(int c,int p)
{
    struct node *sum, *temp;
    sum = createnode();
    sum->data = c;
    sum->pow = p;
    if(start2==NULL)
    {
        start2 = sum;
        temp = sum;
    }
    else
    {
        temp->next = sum;
        temp = sum;
    }
}

void display(struct node *head)
{
    struct node *temp;
    temp = head;
    
    if(temp == NULL)
        printf("\nEmpty\n");
    else
    {
        while(temp != NULL)
        {
            {printf(" (%dX^%d) ",temp->data,temp->pow);}
            temp = temp->next;
        }
    }
}


void main()
{
    int c=0,val,val2;
    struct node *t1, *t2;
    start = insert(2,start);
    start1 = insert(2,start1);
    display(start);
    printf("\n");
    display(start1);
    t1 = start;
    t2 = start1;
    while(t1 != NULL && t2 != NULL)
    {
        if(t1->pow==t2->pow)
        {
            c = (int)(t1->data)+(int)(t2->data);
            printf("\n%d",c);
            add(c,t2->pow);
            t1= t1->next;
            t2 = t2->next;
        }
        else if(t1->pow>t2->pow)
        {
            add(t1->data,t1->pow);
            t1 =t1->next;
        }
        else if(t1->pow<t2->pow)
        {
            add(t2->data,t2->pow);
            t2 =t2->next;
        }
       
    }

     while(t1!=NULL)
        {
            add(t1->data,t1->pow);
            t1 =t1->next;
        }
    while(t2!=NULL)
        {
            add(t2->data,t2->pow);
            t2 =t2->next;
        }
    printf("\n");
    display(start2);
    
}
