#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    struct tree *left;
    int data;
    struct tree *right;
}tree;
tree* root = NULL;

tree* insert(tree* t, int val) {
    if (t == NULL) {
        tree* pt = (tree*)malloc(sizeof(tree));
        pt->data = val;
        pt->left = pt->right = NULL;
        return pt;
    }

    if (t->data > val) {
        t->left = insert(t->left, val);
    } else if (t->data < val) {
        t->right = insert(t->right, val);
    }

    return t;
}


void inorder(tree* t){
    if(t==NULL){
        return;
    }
    inorder(t->left);
    printf("%d ",t->data);
    inorder(t->right);
}

void preorder(tree* t){
    if(t==NULL){
        return;
    }
    printf("%d ",t->data);
    preorder(t->left);
    preorder(t->right);

}

void postorder(tree* t){
    if(t==NULL){
        return;
    }
    postorder(t->left);
    postorder(t->right);
    printf("%d ",t->data);

}
void main(){
    int A[] = {8,1,5,3,9,4,6,7};
    root = insert(root,A[0]);
    for(int i=1; i<8; i++){
        root = insert(root,A[i]);
    }
    printf("Inorder traversal\n");
    inorder(root);
    printf("\nPreorder traversal\n");
    preorder(root);
    printf("\nPostorder traversal\n");
    postorder(root);
}
