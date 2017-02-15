//linkedlist


#include <stdio.h>
#include <malloc.h>


typedef struct Node{
    int num;
    struct Node* np;
} node;

typedef node* position;

node* new(int w){
    node* p= (node*)malloc(sizeof(node));
    p->np = NULL;
    p->num = w;
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

int LL_lenth(node*p){
    int n = 0;
    node* tmp = p;
    while(tmp){
        n++;
        tmp = tmp->np;
    }
    return n-1;
}

void tail_insert(node* root,int w){
    while(root->np != NULL)
        root = root->np;
    root->np = new(w);
    //printf("%d\n",root->np->num);
}

void node_print(node* root){
    root = root->np;
    while(root!=NULL){
        printf("%d\n",root->num);
        root = root->np;
    }
}

void main(){
    int a[]={1,2,3,4,22,3};
    int N = sizeof(a)/sizeof(int);
    printf("%d\n",N);
    node* root = new(101);

    int i;
    for(i=0;i<N;i++){
        tail_insert(root,a[i]);
    }
    node_print(root);
    printf("%d\n",LL_lenth(root));
}
