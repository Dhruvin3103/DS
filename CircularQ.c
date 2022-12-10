#include<stdio.h>
#define Max 5

int a[Max];
int f=-1,r=-1;

void insert(int val)
{
    if((f==0 && r==Max-1)||f==r+1)
        printf("Overflow");
    else if(f==-1 && r==-1)
    {
        f=r=0;
        a[r]=val;
    }
    else if(r==Max-1 && f!=0)
    {
        r=0;
        a[r]=val;
    }
    else
    {
        r++;
        a[r]=val;
    }
}

void delete()
{
    if(f==-1 && r==-1)
        printf("Under flow ");
    
    printf("Deleted : %d",a[f]);
    if(f==r)
        f=r=-1;
    else if(f==Max-1)
        f=0;
    else
        f++;    
}

void display()
{
    if(f==-1 && r==-1)
        printf("Under flow ");
    else if(f<r)
    {
        for(int i=f;i<=r;i++)
            {printf("%d\t",a[i]);}
    }
    else
    {
        for(int i=f;i<Max;i++)
            {printf("%d\t",a[i]);}
        for(int i=0;i<=r;i++)
            {printf("%d\t",a[i]);}
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