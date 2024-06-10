#include <stdio.h>
#include <stdlib.h>

int top=-1,n;
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);
int main()
{
    int ele, choice;
    printf("Enter the size of stack:");
    scanf("%d",&n);
    int stack[n];
while(2>1)
{
    printf("\n Select 1 for PUSH");
    printf("\n Select 2 for POP");
    printf("\n Select 3 for PEEK");
    printf("\n Select 4 for DISPLAY");
    printf("\n Select 5 for EXIT");
    printf("\n Enter your choice:");
    scanf("%d", &choice);
    if(choice==1)
    {
        printf("\n Enter the number to be pushed on stack: ");
        scanf("%d", &ele);
        push(stack,ele);
    }
    else if(choice==2)
    {
        ele = pop(stack);
        printf("\n The value deleted from stack is: %d", ele);
    }
    else if(choice==3)
    {
        ele = peek(stack);
        printf("\n The value at top of stack is: %d", ele);
    }
    else if(choice==4)
    {
        display(stack);
    }
    else if(choice==5)
    {
        break;
    }
    else
    {
        printf("Enter a valid choice");
    }
}
}

void push(int stack[], int ele)
{
    if(top==n-1)
    {
        printf("Stack overflow.Cannot push element");
    }
    else
    {
        top++;
        stack[top] = ele;
    }
}

int pop(int stack[])
{
    int ele;
    if(top == -1)
    {
        printf("Stack underflow.Cannot pop element");
        return -1;
    }
    else
    {
        ele = stack[top];
        top--;
        return ele;
    }
}

void display(int stack[])
{
    int i;
    if(top == -1)
        printf("\n Stack is empty.");
    else
    {
        for(i=top;i>=0;i--)
        printf("\n %d",stack[i]);
        printf("\n"); 
    }
}

int peek(int stack[])
{
    if(top == -1)
    {
        printf("\n Stack is empty.");
        return -1;
    }
    else
    {
        return (stack[top]);
    }
}
