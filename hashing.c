#include<stdio.h>

void hash(int h[], int k, int i, int n)
{
    int j;
    j = (k%n+i)%n;
    if(h[j]==-1){h[j] = k;}
    else if(h[j]!=-1)
    {hash(h,k,i+1,n);}
    else 
    {printf("Sorry :(");}
}   





void main()
{
    int n, h[100],c=1,k,j;
    printf("Enter the size of hash table : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){h[i]=-1;}
    while(c == 1)
    {
        printf("\nEnter the key : ");
        scanf("%d",&k);
        hash(h,k,0,n);
        printf("\nWant to enter key(press 1) : ");
        scanf("%d",&c);
    }
    for(int i=0;i<n;i++){printf("|%d",h[i]);}
    printf("|");
}