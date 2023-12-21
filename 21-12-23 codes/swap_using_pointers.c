#include<stdio.h>
void swap( int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
void main(){
    int a=10,b=20;
    printf("Before swapping: %d %d\n",a,b);
    swap(&a,&b);
    printf("After swapping: %d %d",a,b);
}
