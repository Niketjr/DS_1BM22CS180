#include <stdio.h>
#include <string.h>
int top = -1;
char A[10];
void push(char a){
    if(top==9){
        printf("Stack overflow!");
    }
    else{
        top++;
        A[top]=a;
    }
}

char pop(){
    char x;
    if(top==-1){
        printf("Stack undeflow!");
    }
    else{
        x = A[top];
        top--;
    }
    return x;
}



int pref(char x){
    if(x=='+'||x=='-'){
        return 1;
    }
    else if(x=='*'||x=='/'){
        return 2;
    }
    else if(x=='^'){
        return 3;
    }
    else{
        return 0;
    }
}
int compute(char exp, int o1, int o2){
    if(exp=='+'){
        return o1 + o2;
    }
    else if(exp=='-'){
        return o1 - o2;
    }
    else if(exp=='*'){
        return o1 * o2;
    }
    else if(exp=='/'){
        return o1 / o2;
    }
    else{
        return 0;
    }
    
    
}
int main()
{
    char exp[100],postfix[100];
    int j;
    scanf("%s",exp);
    for(int i  = 0;i<strlen(exp);i++){
        if(exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/'){
            push(exp[i]-'0');
        }
        else{
            int o2 = pop();
            int o1 = pop();
            int r = compute(exp[i],o1,o2);
            push(r);
        }
    }
    printf("%d",A[top]);
    return 0;
}
