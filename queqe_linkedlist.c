#include <stdio.h>
#include <stdlib.h>
#define max 2

int counter = 0;
struct node
{
    /* data */
    int data;
    struct node *next;
} *first, *last;

int isEmpty()
{
    if (!first)
    {
        counter = 0 ;
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull()
{
    if (counter == max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int enqueue(int x)
{
    if (!isFull())
    {
        struct node *t;
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = NULL;
        if (counter == 0)
        {
            first = t;
            last = t;
            counter++;
        }
        else
        {
            last->next = t;
            last = t;
            counter++;
        }
    }else{
        printf("Queue is Full\n");
    }
}
int deque()
{
    if(!isEmpty()){
        struct node *p=first;
        int data = first->data;
        first = first->next;
        counter--;
        free(p);
        return data;
    }else{
        printf("Queue is empty\n");
    }
}
void printqueue()
{
    struct node *p;
    p = first;
    while (p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    printqueue();
    enqueue(30);
    deque();
    deque();
    printqueue();
    deque();
}