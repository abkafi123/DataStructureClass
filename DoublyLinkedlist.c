#include <stdio.h>
#include <stdlib.h>
struct node
{
    /* data */
    struct node *prev;
    int data;
    struct node *next;

} *first;

void create(int a[],int n){

    int i;
    struct node *t,*last;
    first = (struct node *)malloc(sizeof(struct node));
    first->prev = NULL;
    first->next = NULL;
    first->data = a[0];
    last = first;
    for(i = 0;i<n;i++){
        t = (struct node *)malloc(sizeof(struct node));
        t->prev = last;
        t->data = a[i];
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
    printf("\n%d\n", sum(first));
    printf("\n%d\n", max(first));
}