#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Tree{
    char* s;
    struct Tree* child;
    struct Tree* sibling;
};

typedef struct Tree tree;

void strcopy(char* from, char* to){
    while(*from!='\0'){
        *to++ = *from++;
    }
    *to = '\0';
}

int strcomp(char *p,char *s){
    while(*p++==*s++ && *p!='\0');
        return *p-*s;
}

tree* new_node(char* s){
    tree* tmp = (tree*)malloc(sizeof(tree));
    tmp->s = (char*)malloc(MAX*sizeof(char));
    strcopy(s,tmp->s);
    tmp->child = NULL;
    tmp->sibling = NULL;
    return tmp;
}

int IsEntry(tree* p){
    return p->child!=NULL;
}

tree* treefind(tree* t,char *filename){
    if(!strcomp(t->s,filename))
        return t;

    else if(t->child == NULL){
        return NULL;
    }

    else
        treefind(t->child,filename);
}

void add_dir(char *pre_menu,char *newdirname,tree* header){
    tree* tmp = treefind(header,pre_menu);
    if(tmp == NULL){
        printf("the dir is not found\n");
    }
    while(tmp->child!=NULL)
        tmp = tmp->child;
    tmp->child = new_node(newdirname);
}

void treeprint(tree* header){

}


void main(){
    tree *header = new_node("header");
    add_dir("header","home",header);
    add_dir("home","user",header);
    add_dir("home","tools",header);
    add_dir("home","media",header);
    add_dir("home","media",header);
    add_dir("tools","tmp",header);


}
