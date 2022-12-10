#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int top = -1; 
int size = 5;
int a[100];

void push(int val)
{
    if(top == size-1)
    {printf("Overflow");
    }
    else
    {
        top++;
        a[top] = val;
    }
}

void pop()
{
    if(top == -1)
    {printf("Underflow");}
    else
    {
        printf("\n\t%d\n",a[top]);
        top--;
    }
}

void display()
{
    if(top == -1){printf("underflow");}
    else{
    for(int i =0; i<=top;i++)
    {
        printf("\t%d\n",a[i]);
    }}
}

void main()
{
    int val, c=0;
    while(c < 4){
        printf("Enter a choice \n1]push\n2]pop\n3]display\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1 : 
        printf("\nEnter what to push : ");
        scanf("%d",&val);
        push(val);
        break;
        
        case 2 :
        pop();
        break;

        case 3 :
        display();
        break;

        case 4 :
        exit(0);
        
    }}
}