#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int depth = 0;


struct Tree{
    char* s;
    struct Tree* child;
    struct Tree* sibling;
};

typedef struct Tree tree;

tree* result = NULL;

void strcopy(char* from, char* to){
    while(*from!='\0'){
        *to++ = *from++;
    }
    *to = '\0';
}

int strcomp(char *p,char *s){
    while(*p!='\0' && *p==*s)
        p++,s++;
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

void treeprint(tree* t){
    int i=depth;
    if(t!=NULL){
        while(i>0){
            printf("   ");
            i--;
        }
        printf("%s\n",t->s);


        tree* tmp;
        for(tmp=t->child,depth++;tmp!=NULL;tmp = tmp->sibling){
            //printf("%s\n",tmp->s);
            treeprint(tmp);
        }
        depth--;    //suo jin xiang guan
    }
}


tree* treefind(tree* t, char *s){
    tree* tmp = t;
    if(tmp!=NULL){
        //printf("%s  %s  %d\n",tmp->s,s,strcomp(tmp->s,s));
        if(strcomp(tmp->s,s)==0){
            //printf("here!\n");
            result = tmp;
        }
        else{
            for(tmp=tmp->child;tmp!=NULL;tmp=tmp->sibling)
                treefind(tmp,s);
        }
    }
    return result;
}


void main(){
    tree *header = new_node("header");
    tree *tmp = new_node("home");
    header->child = tmp;
    tmp = new_node("tools");
    header->child->sibling = tmp;
    tmp = new_node("software");
    header->child->sibling->sibling = tmp;
    tmp = new_node("tmp");
    header->child->sibling->child = tmp;

    treeprint(header);

    tree* temp = treefind(header,"tools");

    if(temp!=NULL){
        printf("the target is %s\n",temp->s);
    }
    else
        printf("NOT FOUND");



  /*add_dir("header","home",header);
    add_dir("header","home",header);
    add_dir("home","tools",header);
    add_dir("home","media",header);
    add_dir("home","soft",header);
    add_dir("tools","tmp",header);
    add_dir("media","tmp1",header);
    treeprint(header);*/
}
