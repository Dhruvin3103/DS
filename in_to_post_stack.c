#include<stdio.h>
#include<ctype.h>

char s[100];
int top =-1;

void push(char c)
{
    s[++top]=c;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return s[top--];
}

int prio(char c)
{
    if(c == '(')
        return 0;
    if(c == '+' || c == '-')
        return 1;
    if(c == '*' || c == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char x;
    printf("Enter the exp : ");
    gets(exp);
    // printf("%c",exp[2]);
    int i=0;
    while(exp[i]!='\0')
    {
        
        if(isalnum(exp[i]))
            printf("%c",exp[i]);
        else if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i]==')')
        {
            while((x = pop())!= '(')
            {printf("%c",x);}
        }
        else 
        {
            while(prio(exp[i])<= prio(s[top]))
                printf("%c",pop());
            push(exp[i]);
        }
        i++;

    }
    
    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
    
}