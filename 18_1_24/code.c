#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}node;
struct node* head = NULL;

void create(int A[], int n){
    struct node *t, *last;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = A[0];
    head->next = NULL;
    last = head;
    for(int i=1; i<n; i++){
        t = (struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void fdelete(){
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    p = head;
    head = head->next;
    free(p);
}

void ldelete(){
    struct node*p, *p1;
    p = (struct node*)malloc(sizeof(struct node));
    p = head;
    while(p->next!=NULL){
        p1 = p;
        p = p->next;
    }
    p1->next = NULL;
    free(p);
}

void delete(int pos){
    struct node *p, *p1;
    p = (struct node*)malloc(sizeof(struct node));
    p = head;
    for(int i=0;i<pos-1;i++){
        p = p->next;
    }
    p1 = p;
    p = p->next;
    p1->next = p->next;
    free(p);

}

void display(struct node*p){
    struct node *t = p;
    while(t!=NULL){
        printf("%d ",t->data);
        t = t->next;
    }
}

int main()
{
    int A[] = {2,4,6,5,1,8};
    create(A,6);
    fdelete();
    ldelete();
    delete(2);
    display(head);
    return 0;
}
