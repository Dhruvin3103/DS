#include<stdio.h>

void DFS(int a[100][100] ,int v[], int s,int n)
{
    int stack[n];
    int top = -1,i;
    printf("%d\n",s);
    v[s]=1;
    //  1  1  1  0 
//      0  0  1  0 
//      1  0  0  0 
//      0  1  0  0 
    stack[++top]=s;//PUDSH
    while(top != -1)
    {
        s = stack[top--];
        printf("%d",s);
        for(i=0; i<n;i++)
        {
            if(a[s][i]==1 && v[i]==0)
            {
                stack[++top]= i;//PUSH
                v[i]=1;// VIS MEW 1
            }
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
        
        for(int j=0;j<n;j++)
        {
           printf(" %d ",a[i][j]);
        }
        printf("\n");
    }

    DFS(a,v,0,n);
    // printf("Over ");
}

//  1  1  1  0 
//  0  0  1  0 
//  1  0  0  0 
//  0  1  0  0 