#include <stdio.h>
#include <stdlib.h>
struct node
{
    /* data */
    int data;
    struct node *next;
} *first;

void create(int arr[], int n)
{

    int i;
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

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
        printf("Reached Last element");
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

int main()
{

    int a[] = {1, 2, 3, 5};
    int n = 4;
    create(a, n);
    display(first);
    printf("\n%d\n", count(first));
    printf("\n%d\n", sum(first));
    printf("\n%d\n", max(first));
}