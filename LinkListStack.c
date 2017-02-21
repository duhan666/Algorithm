// implement stack with linked list

#include <stdio.h>
#include <malloc.h>

struct mystacknode{
    int num;
    struct mystacknode* next;
};

typedef struct mystacknode node;

node* create_node(x){
    node* p = (node*)malloc(sizeof(node));
    p->next = NULL;
    p->num  = x;
    return p;
}

void print_node(node* root){
    root = root->next;
    while(root!=NULL){
        printf("%d\n",root->num);
        root = root->next;
    }
}

void push_node(node* root,int x){
    node* p = create_node(x);
    node* tmp = root->next;
    root->next = p;
    root->next->next = tmp;
}

int pop_node(node* root){
    node* tmp = root->next;
    root->next = tmp->next;
    int n = tmp->num;
    free(tmp);
    tmp = NULL;
    return n;
}



main(){
    node * root = create_node();
    push_node(root,1);
    push_node(root,2);
    push_node(root,3);
    print_node(root);
    printf("%d\n",pop_node(root));
    print_node(root);
}
