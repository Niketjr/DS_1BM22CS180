#include <stdio.h>
#define size 10

int H[size];

void insert(int val){
    int i = 0;
    int hkey = (val + i) % size;
    while (H[hkey] != -1) {
        i++;
        hkey = (val + i) % size;
    }
    H[hkey] = val;
}
void search(int v){
    for(int i=0; i<size; i++){
        if(H[i]==v){
            printf("Employee %d is found at position %d\n\n", v,i);
        }
    }
}
int main(){
    int val[size] = {1345, 2347, 4642, 9871, 9855, 2638, 9853, 2986, 9874, 5530};
    for (int j = 0; j < size; j++) {
        H[j] = -1;
    }
    for (int i = 0; i < size; i++) {
        insert(val[i]);
    }
    int x;
    printf("Enter employee you want to find:");
    scanf("%d",&x);
    search(x);
    for (int i = 0; i < size; i++) {
        printf("%d %d \n",i, H[i]);
    }
    return 0;
}
