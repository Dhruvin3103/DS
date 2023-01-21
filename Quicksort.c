#include<stdio.h>

int part(int a[],int l,int h)
{
    int p = a[h];//pivot
    int i=l;
    // printf("%d",i);
        for(int j=l;j<h;j++)
        {
            if(a[j]<=p)
            {int temp=a[i];a[i]=a[j];a[j]=temp;i++;}//swapping i and j 
        }
        int t2=a[i];a[i]=a[h];a[h]=t2; //swapping I and h
        return i;
        

}


void quicksort(int a[],int l,int h)
{
    if(l<h)
    {
        int j= part(a,l,h);
        quicksort(a,l,j-1);
        quicksort(a,j+1,h);
    }
}

void main()
{
    int n, a[100];
    printf("enter the size : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter : ");
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}