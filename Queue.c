#include<stdio.h>
#define Max 5
int f=-1;
int r=-1;
int a[Max];

void insert(int val)
{
    if(r==Max-1)
        printf("Overflow");
    else if(f==-1 && r==-1)
    {f=r=0;}
    else
        r++;

    a[r]=val;
}

void delete()
{
    if(f==-1 && r==-1)
        printf("Under flow");
    else
    {
        printf("popped : %d",a[f]);
        f++;
        if(f>r)
        {f=r=-1;}
    }
}

void display()
{
    if(f==-1 && r==-1)
        printf("Under flow");
    else
    {
        for(int i=f;i<=r;i++)
        {
            printf("%d\t",a[i]);
        }
    }
}
void main()
{
    int c=0,val;
    while (c<4)
    {
        printf("\nEnter choice : ");
        scanf("%d",&c);
        switch (c)
        {
        case 1 : 
        {
            printf("\nEnter : ");
            scanf("%d",&val);
            insert(val);
        }
            break;
        
        case 2: delete();break;
        case 3: display();break;
        default:
            break;
        }
    }
    
}