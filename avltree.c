//avltree
#include <stdio.h>
#include <stdlib.h>

struct avltree;
typedef struct avltree tree;
typedef struct avltree* treep;

struct avltree{
    int num;
    treep left;
    treep right;
    int height;
};

int max(int a,int b){
    return a>b?a:b;
}

treep rotate_left_tobe_father(treep k2){
    treep k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(k2->left->height,k2->right->height)+1;
    k1->height = max(k1->left->height,k2->height);
    return k1;
}

treep rotate_right_tobe_father(treep k1){
    treep k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(k1->left->height,k1->right->height)+1;
    k2->height = max(k1->height,k2->right->height)+1;
    return k2;
}

treep double_rotate_left(treep k3){
    k3->left = rotate_right_tobe_father(k3->left);
    return rotate_left_tobe_father(k3);
}

treep double_rotate_right(treep k3){
    k3->right = rotate_left_tobe_father(k3->left);
    return rotate_right_tobe_father(k3);
}

int treeheight(treep node){
    if(node == NULL){
        return -1;
    }
    else
        return node->height;
}

treep insert(int num,treep root){
    if(root == NULL){
        root = (treep)malloc(sizeof(tree));
        root->height = 0;
        root->left = root->right = NULL;
    }
    else{
        if(num<root->num){
            root->left = insert(num,root->left);
            if(root->left->height-root->right->height == 2)
                if(num<root->left->num)
                    root = rotate_left_tobe_father(root);
                else
                    root = double_rotate_left(root);
        }
        else if(num>root->num){
            root->right = insert(num,root->right);
            if(root->right->height-root->left->height == 2)
                if(num>root->right->num)
                    root = rotate_right_tobe_father(root);
                else
                    root = double_rotate_right(root);
        }

    }
    root->height = max(root->left->height,root->right->height)+1;
    return root;
}

main(){}

//to be continue
