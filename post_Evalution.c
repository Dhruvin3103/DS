#include<stdio.h>

char stack[100];
int top =-1;

void push(int val)
{stack[++top]=val;}

int pop()
{return stack[top--];}

int isnum(char c)
{
    if(c>='0' && c<='9'){ return 1;}
    else{return 0;}
}

int evalute(char c[])
{
    int i=0;
    while(c[i]!='\0')
    {
        if(isnum(c[i]) == 1)
        {
            push((int)(c[i]-'0'));}
        else
        {
            int val;
            int op1 = pop();
            int op2 = pop();
            switch(c[i])
            {
                case '+' : 
                    {val=op1+op2;break;}
                case '-' : 
                    {val=op1-op2;break;}
                case '*' : 
                    {val=op1*op2;break;}
                case '/' : 
                    {val=op1/op2;break;}
                default: break;
            }
            push(val);
        }
        i++;
    }
    return stack[top];
}

void main()
{
    char exp[100];
    printf("Enter the exp : ");
    gets(exp);
    // printf(" %c hi ",exp[2]);
    int ans = evalute(exp);
    printf("\n%d",ans);

}