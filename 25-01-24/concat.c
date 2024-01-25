
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head = NULL, *head1 = NULL;
void create()
{
    head = (struct node*)malloc(sizeof(struct node));
    head1 = (struct node*)malloc(sizeof(struct node));
   struct node *last, *last1;
   int a[] = {1,2,3,4};
   int b[] = {5,6,7,8};

   head->data = a[0];
   head->next = NULL;

   head1->data = b[0];
   head1->next = NULL;

   last = head;
   last1 = head1;

   for(int i=1;i<sizeof(a)/sizeof(a[0]);i++)
   {
       struct node *t;
       t = (struct node*)malloc(sizeof(struct node));
       t->data = a[i];
       t->next = NULL;
       last->next = t;
       last = t;
   }

   for(int i=1;i<sizeof(b)/sizeof(b[0]);i++)
   {
        struct node *t1;
        t1 = (struct node*)malloc(sizeof(struct node));
        t1->data = b[i];
        t1->next = NULL;
        last1->next = t1;
        last1 = t1;
    }

}

void display_a()
{
    struct node *n = head;

    printf("A:\n");
    while(n!=NULL)
    {
        printf("%d\n",n->data);
        n = n->next;
    }
    return;
}

void display_b()
{
    struct node *n1 = head1;

    printf("B:\n");
    while(n1!=NULL)
    {
        printf("%d\n",n1->data);
        n1 = n1->next;
    }
}

void concat()
{
    struct node *n, *n1;
    if(head == NULL || head1 == NULL)
    {
        if(head == NULL)
            display_b();
        else
            display_a();
    }
    else
    {
        n=head;
        while(n!=NULL)
        {
            n1 = n;
            n = n->next;
        }
        n1->next = head1;
        display_a();
    }

}
void main()
{
    create();
    printf("After Concatenation A and B\n");
    concat();
}
