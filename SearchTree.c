//SearchTree
#include <stdio.h>
#include <stdlib.h>

typedef struct SearchTree{
    int s;
    struct SearchTree* left;
    struct SearchTree* right;
}stree;

typedef stree* treep;

void EmptyTree(treep node){
    if(node!=NULL){
        EmptyTree(node->left);
        EmptyTree(node->right);
        free(node);
    }
}

treep insertree(int x,treep node){
    treep tmp = node;
    if(node == NULL ){
        tmp = (treep)malloc(sizeof(stree));
        tmp->left=tmp->right=NULL;
        tmp->s = x;

    }
    else if(x<tmp->s)
        tmp->left = insertree(x,tmp->left);
    else if(x>tmp->s)
        tmp->right = insertree(x,tmp->right);

    return tmp;
}

void main(){
    treep root = NULL;
    int a[] = {6,1,2,3,4,5,8};
    int N=sizeof(a)/sizeof(int);
    int i=0;
    while(i<N){
        root = insertree(a[i],root);
        i++;
    }
    printf("%d\n",root->right->s);
}
