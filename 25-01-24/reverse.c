
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
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

struct node* reverse(struct node* p, int len){
    p = head;
    int a[len];
    a[0] = p->data;
    for(int i=1; i<len; i++){
        p = p->next;
        a[i] = p->data;
    }
    p = head;
    for(int i = len-1; i>=0; i--){
        p->data = a[i];
        p = p->next;
    }
    return head;
}

void main(){
    int A[]={2,1,3,5,4,8,6,7};
    create(A,8);
    head = reverse(head,8);
    struct node* p = head;
    while(p!=NULL){
            printf("%d ",p->data);
            p = p->next;
    }
}
