#include<stdio.h>

void insertion(int arr[], int n)
{
int i, j, temp;
for(i=1;i<n;i++)
{
 temp = arr[i];
 j = i-1;
 while((temp < arr[j]) && (j>=0))
 {
 arr[j+1] = arr[j];
j--;
 }
 arr[j+1] = temp;
}
}

int small(int a[],int p, int n)
{
    int small = a[p],pos;
    for(int i = p+1 ;i<n;i++)
    {
        if(a[i]<small)
        {
            small=a[i];
            pos=i;
        }
    }
        return pos;
}

void select(int a[],int n)
{
    int pos,temp;
    for(int i=0;i<n;i++)
    {
        pos = small(a,i,n);
        temp = a[i];
        a[i] = a[pos];
        a[pos] = temp;
    }
}

void main()
{
    int arr[100],n,i;
    printf("Enter size : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter : ");
        scanf("%d",&arr[i]);
    }
    select(arr,n);
    // insertion(arr,n);
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
}