#include<stdio.h>

void main()
{
    int a[100],n,i;
    printf("Enter size : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter : ");
        scanf("%d",a[i]);
    }

    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}