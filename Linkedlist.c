//linkedlist


#include <stdio.h>
#include <malloc.h>


typedef struct Node{
    int num;
    struct Node* np;
} node;

typedef node* position;

node* new(){
    node* p= (node*)malloc(sizeof(node));
    p->np = NULL;
    p->num = 100;
    return p;
}

int IsEmpty(node* p){          //if the Linkedlist is empty ,return 1;
    return p->np == NULL;
}

int IsLast(position p){
    return p->np == NULL;       //if position p is the last one,return 1;
}

node* Findp(node* root,int w){
        while(root->num!=w && root->np!=NULL)
            root =  root->np;
        return root;
}

int node_lenth(node*p){
    int n = 0;
    node* tmp = p;
    while(tmp){
        n++;
        tmp = tmp->np;
    }
    return n;
}

void tail_insert(node* root,int w){
    while(root->np !=NULL)
        root = root->np;
    root->np = new();
    root->np->num = w;
    root->np->np = NULL;
}

void node_print(node* root){
    while(root->np!=NULL){
        printf("%d\n",root->num);
        root = root->np;
    }
}

void main(){
    int a[]={10,20,30,40,50,60,70,80,90};
    int N = sizeof(a);

    node* root = new();
    root->num = 123456789;

    int i;
    for(i=0;i<N;i++){
        tail_insert(root,a[i]);
    }
    node_print(root);
}
