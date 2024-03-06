#include <stdio.h>
#include <string.h>
int top;
char A[100];
void push(char x){
    if(top==9){
        printf("Stack overflow!");
    }
    else{
        A[++top] = x;
    }
}
char pop(){
    int x;
    if(top==-1){
        printf("Stack underflow!");
    }
    else{
        x = A[top];
        top--;
    }
    return x;
}
int pref(char x){
    if(x=='+' || x=='-'){
        return 1;
    }
    else if(x=='*' || x=='/'){
        return 2;
    }
    else if(x=='^'){
        return 3;
    }
    else
        return 0;
}
void main(){
    char s[] = "A*B+C*D-E", postfix[100], x, y;
    int j=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/'){
            postfix[j++]=s[i];
        }
        else{
            while(top!=-1 && pref(A[top]) >= pref(s[i])){
                x = pop();
                postfix[j++] = x;
            }
            push(s[i]);

        }
    }
    while(top!=-1){
        y = pop();
        postfix[j++] = y;
    }
    postfix[j] = '\0';
    printf("%s",postfix);
}
