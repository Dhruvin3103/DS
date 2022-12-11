#include<stdio.h>
int min(int x,int y)
{
    if(x<y)
        return x;
    else
        return y;
}
int fibosearch(int s,int n,int a[])
{
    int i,offset=-1,fibm1=1,fibm2=0;
    int fibm=fibm1+fibm2;
    while(fibm<n)
    {
        fibm2=fibm1;
        fibm1=fibm;
        fibm=fibm1+fibm2;
    }
    while(fibm>=1)
    {
        i=min(offset+fibm2,n-1);
        if(s>a[i])
        {
            fibm=fibm1;
            fibm1=fibm2;
            fibm2=fibm-fibm1;
            offset=i;
        }
        else if(s<a[i])
        {
            fibm=fibm2;
            fibm1=fibm1-fibm2;
            fibm2=fibm-fibm1;
        }
        else
        return i;
    }
    return -1;
}
void main()
{
    int n,a[100],i,s,flag=-1;
    printf("enter no. of elements");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter no. ");
        scanf("%d",&a[i]);
    }
    printf("enter search ");
    scanf("%d",&s);
    flag=fibosearch(s,n,a);
    if(flag==-1)
    printf("Search not found");
    else
    printf("element found at pos %d",flag+1);
}