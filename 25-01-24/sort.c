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

struct node* sort(head) {
    struct node *ptr1,*ptr2;
    ptr1=head;
    int temp,count=1;
    while(ptr1->next!=NULL){
        count++;
        ptr1=ptr1->next;
    }
    ptr1=head;
    while(--count){
        ptr1=head;
        while(ptr1->next!=NULL){
            ptr2=ptr1;
            ptr1=ptr1->next;
            if(ptr1->data<ptr2->data){
                temp=ptr2->data;
                ptr2->data=ptr1->data;
                ptr1->data=temp;
            }
        }
    }
    return head;
}

void main(){
    int A[]={2,1,3,5,4,8,6,7};
    create(A,8);
    head = sort(head);
    struct node* p = head;
    while(p!=NULL){
            printf("%d",p->data);
            p = p->next;
    }
}
