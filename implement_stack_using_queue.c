#include<stdio.h>
int queue[100],front=-1,rear=-1,queue1[100],front1=-1,rear1=-1;
void enqueue1(int x)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
    }
    else
    {
        rear=rear+1;
    }
    queue[rear]=x;
}
int dequeue1()
{
    int x=front;
    front=front+1;
    return x;
}
int enqueue2(int x)
{
    if(front1==-1 && rear1==-1)
    {
        front1=rear1=0;
    }
    else
    {
        rear1=rear1+1;
    }
    queue1[rear1]=x;
}
int dequeue2()
{
    int x=front1;
    front1=front1+1;
    return x;
}
void push(int x)
{
    int a;
    for(int i=front;i<rear;i++)
    {
        a=dequeue1(x);
        enqueue2(a);
    }
    enqueue1(x);
    for(int i=front1;i<rear1;i++)
    {
        a=dequeue2(x);
        enqueue1(a);
    }
}
int pop()
{
    int x;
    x=dequeue1();
    return x;
} 
void display()
{
    int i;
    for(i=front;i<=rear;i++)
    {
        printf("%d\n",queue[i]);
    }
};
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    display();
}