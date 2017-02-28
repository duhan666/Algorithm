
#include <stdio.h>
#include <stdlib.h>
#define stackdepth 30


int IsAlpha(char s){
    if((s>='a'&&s<='z')||(s>='A'&&s<='Z'))
        return 1;
    else
        return 0;
}

int IsNumber(char s){
    if(s>='0'&&s<='9')
        return 1;
    else
        return 0;
}

int IsOperator(char s){
    if(s=='+'||s=='*')
        return 1;
    else
        return 0;
}

struct Tree{
    char s;
    struct Tree* left;
    struct Tree* right;
};

typedef struct Tree* treep;
typedef struct Tree  Tree;

treep new_node(char s){
    treep node = (treep)malloc(sizeof(Tree));
    node->s = s;
    node->left = NULL;
    node->right = NULL;
}

treep stackp[stackdepth];
int sp = 0;

void pushs(treep node){
    if(sp<stackdepth){
        stackp[sp++]=node;
    }
    else{
        printf("the stack is full!");
    }
}

treep pops(){
    if(sp>0)
        return stackp[--sp];
    else
        printf("the stack is empty!");
}

void treeprint(treep node){
    treep tmp = node;
    if(tmp!=NULL){

        //printf("this tree node\n");
        treeprint(tmp->left);
        treeprint(tmp->right);
        printf("%c\n",tmp->s);
    }
}


void main(){
    char c;
    treep tmp;
    while((c=getchar())!='\n'){
        tmp = new_node(c);
        if(IsAlpha(c)){
            pushs(tmp);
        }
        if(IsOperator(c)){
            tmp->right = pops();
            tmp->left = pops();
            pushs(tmp);
        }
    }
    treeprint(tmp);
}




