#include<stdio.h>
int a[10],top=-1;
void main(){
    int c,n,p;
    printf("Choose:\n 1 to push \n 2 to pop \n 3 to display\n");
    scanf("%d",&c);
    if(c==1){
        printf("Enter an element: ");
        scanf("%d",&n);
        push();
    }
    else if(c==2){
        pop();
    }
    else if(c==3){
        display();
    }
    else{
        printf("Enter the proper input");

    }
}
void push(){
    int x;
    if(top==9){
        printf("Oveflow!");
    }
    else{
        printf("Enter elements:");
        scanf("%d",&x);
        top+=1;
        a[top]=x;
    }

}
void pop(){
    if(top==-1){
        printf("Underflow!");
    }
    else{
        printf("popped element:%d",a[top]);
        top-=1;
    }
}
void display(){
    if(top==-1){
        printf("Underflow!");
    }
    else{
        printf("The elements are:");
        for(int j=top;j>0;j--){
            printf("%d ",a[j]);
        }
    }
}
