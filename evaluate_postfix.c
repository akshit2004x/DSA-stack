#include<stdio.h>
#include<string.h>
#include<ctype.h>
int stack[20];
int top = -1;
void push(int x)
{
    stack[++top] = x;
}
int pop()
{
    return stack[top--];
}
int main()
{
    char e[20];
    int n1,n2,n3,num;
    printf("Enter the expression :: ");
    scanf("%s",&e);
    for(int i=0;e[i]!='\0';i++)
    {
        if(e[i]>='0' && e[i]<='9')
        {
            num = e[i] - 48;//typecasting integer value
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(e[i])
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
    }
    printf("\nThe result of expression %s  =  %d\n\n",e,pop());
    return 0;
}