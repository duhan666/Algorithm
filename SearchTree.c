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


