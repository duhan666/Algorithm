//linkedlist


#include <stdio.h>
#include <malloc.h>


typedef struct Node{
    int num;
    struct Node* np;
} node;

//typedef node* position;

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

/*
node* Findp(node* root,int w){
        while(root->num!=w && root->np!=NULL)
            root =  root->np;
        return root;
}*/

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

node* findp(int x,node* p){
    node* tmp = p->np;
    while( p!=NULL && p->num!=x )
        p = p->np;
    return p;
}

node* previous(int x,node* p){
    node* tmp = p->np;
    while(tmp->np!=NULL && tmp->np->num!=x){
        tmp = tmp->np;
    }
    return tmp;
}

void deletep(int x,node* p){
    node* tmp = findp(x,p);
    node* ptmp = previous(x,p);
    ptmp->np = tmp->np;
    free(tmp);
}

void addnode(int x,node* posi){
    node* tmp = new(x);
    tmp->np = posi->np;
    posi->np = tmp;
}


void main(){
    int a[]={1,2,3,4,22,3};
    int N = sizeof(a)/sizeof(int);

    node* root = new(101);

    int i;
    for(i=0;i<N;i++){
        tail_insert(root,a[i]);
    }

    node* prep = previous(3,root);
    if(prep == NULL )
        printf("the number is not found!");
    else
        printf("the previous num is %d\n",prep->num );


    node* posi = findp(4,root);
    addnode(188,posi);

    node_print(root);
}
