#include<stdio.h>
#include<ctype.h>
#include<string.h>
char stack[100];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    char a;
    if(top == -1)
        return -1;
    else
    {
        a=stack[top--];
        return a;
    }
}
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char e[100],s[100],a;
    char x;
    printf("Enter the expression : ");
    scanf("%s",e);
    printf("\n");
    for(int i = 0; i<strlen(e); i++)
    {
        if(isalnum(e[i]))
        {
            strncat(s,&e[i],1);
            printf("%c ",e[i]);
        }
        else if(e[i] == '(')
            push(e[i]);
        else if(e[i] == ')')
        {
            while((x=pop())!='(')
            {
                strncat(s,&x,1);
                printf("%c ",x);
            }
        }
        else
        {
            while(priority(stack[top]) >= priority(e[i]))
            {
                a=pop();
                printf("%c ",a);
                strncat(s,&a,1);
            }
            push(e[i]);
        }
    }
    while(top != -1)
    {
        a=pop();
        printf("%c ",a);
        strncat(s,&a,1);
    }
    printf("\n");
    printf("\n");
    for(int i=strlen(s)-1;i>=0;i--)
    {
        printf("%c ",s[i]);
    }
    return 0;
}