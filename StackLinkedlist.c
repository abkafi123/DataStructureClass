#include <stdio.h>
#include <stdlib.h>
struct node
{
    /* data */
    int data;
    struct node *next;
    struct node *prev;
} *first, *last;

void display(struct node *p)
{
    if (p)
    {
        printf("%d\n", p->data);
        p = p->next;
        display(p);
    }
    else
    {
        printf("Reached Last element\n");
    }
}

int count(struct node *p)
{
    if (p)
    {
        return 1 + count(p->next);
    }
    else
    {
        return 0;
    }
}

int sum(struct node *p)
{
    if (p)
    {
        return p->data + sum(p->next);
    }
    else
    {
        return 0;
    }
}

int max(struct node *p)
{
    int max = 0;
    while (p)
    {
        if (p->data > max)
        {
            max = p->data;
            p = p->next;
        }
        else
        {
            p = p->next;
        }
    }
    return max;
}

void push(int value)
{
    // it is same as insert at last
    struct node *t, *p;
    // iterate over the list

    if (first == NULL)
    {
        first = (struct node *)malloc(sizeof(struct node));
        first->prev = NULL;
        first->data = value;
        first->next = NULL;
        last = first;
    }
    else
    {
        t = (struct node *)malloc(sizeof(struct node));
        
        if(!t){
            printf("memory error; Memory Full; Can't create new node");
            return ;
        }
        t->data = value;
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

int pop()
{

    int data = -1;
    if (last == NULL)
    {
        printf("Stack Empty\n");
        return data;
    }
    else
    {
        if (last != first)
        {
            data = last->data;
            last = last->prev;
            last->next = NULL;
            return data;
        }
        else
        {
            data = first->data;
            first = NULL;
            return data;
        }
    }
}

int main()
{
    first = NULL;
    last = NULL;
    push(30);
    push(40);
    display(first);
    printf("%d\n", pop());
    printf("%d\n", pop());
}