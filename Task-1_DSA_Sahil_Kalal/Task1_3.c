#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if (t==NULL)
    {
        printf("stack is full");
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop()
{
    struct Node *t;
    char x=-1;
    if (top==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        t = top;
        top = t->next;
        x=t->data;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *p;
    while (top!=NULL)
    {
        printf("%d ",p->data);
        top = p->next;
    }
    printf("\n");
}

int isBalanced(char *e)
{
    int i;
    for(i=0;e[i]!='\0';i++)
    {
        if (e[i]=='(')
        {
            push(e[i]);
        }
        else if(e[i]==')')
        {
            if (top==NULL)
            {
                return 0;
            }
            pop();
        }
    }
    if (top==NULL) 
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
int main()
{
    int x;
    char *e, exp[20];
    printf("Enter brackets: ");
    scanf("%s",&exp);
    e=exp;

    x = isBalanced(e);
    printf("%d",x);
    return 0;
}