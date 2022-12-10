#include<stdio.h>

int bin(int a[], int l,int r,int val)
{
    while (l<r)
    {
        int m = l+r;
        if(a[m]==val)
        {return (m);}
        else if(a[m]>val)
        {r=m-1;}
        else if(a[m]<val)
        {l=m+1;}
    }
}

void main()
{
    int n;
    int a[100];
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter : ");
        scanf("%d",&a[i]);
    }

    int m = bin(a,0,n,5);
    printf("%d",m+1);
}