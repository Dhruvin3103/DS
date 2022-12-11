#include<stdio.h>
#define Max 10
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

int delete()
{
    if(f==-1 && r==-1)
       return -10;
    else
    {
        int t = a[f];
        f++;
        if(f>r)
        {f=r=-1;}
        return t;
    }
}

int isempty()
{
    if(f==-1 && r==-1)
       return -10;
    else
    {
        return a[f];
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
    int n=5,v[100];
    int i=0;
    int a[100][100];
    printf("Enter the size of matrix : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the %d row : ",i+1);
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=0;i<n;i++)
    {v[i]=0;}
// v[i] = 0,0,0,0,0,0...
    for(int i=0;i<n;i++)
    {
        printf("\n");
        for(int j=0;j<n;j++)
        {
           printf(" %d ",a[i][j]);
        }
    }

    printf("\nvertex : ");
    scanf("%d",&i);
    printf("%d ",i);//soucrre
    v[i] = 1;
    insert(i);//inserting in queue
    while(isempty() != -10)
    {
        int node = delete();
        // printf("%d",isempty());
        // printf("\n%d\n",node);
        for(int j =0 ;j<n;j++)
        {
            if(a[node][j] == 1 && v[j] == 0)
            {
                printf("%d ", j);//remaing  bfs
                v[j] = 1;
                insert(j);
            }
        }
    }}