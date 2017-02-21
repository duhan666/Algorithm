// Stack is implemented by Array

#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 20

struct array_stack{
    int Topofstack;
    int Capacity;
    int* a;
};

typedef struct array_stack astack;

int myabs(int a,int b){
    return a>b?(a-b):(b-a);
}

astack* create_stack(int max){
    astack* s = (astack*)malloc(sizeof(astack));
    s->Capacity = max;
    s->Topofstack = -1;
    s->a = (int*)malloc(max*sizeof(int));
    if(s->a == NULL){
        return NULL;
    }
    return s;
}

void push(int x,astack* s){
    if(s->Topofstack>=(MAXLEN-1))
        printf("the stack is full\n");
    s->a[++s->Topofstack] = x;
};

int pop(astack* s){
    if(s->Topofstack<=-1)
        printf("the stack is empty");
    return  s->a[s->Topofstack--];
}

void print_astack(astack* s){
    int i;
    for(i=0;i<MAXLEN;i++)
        printf("%d\n",s->a[i]);
}

int IsEmpty(astack* s){
    return s->Topofstack<=-1;
}


main(){
    astack* s = create_stack(MAXLEN);
    int i = 0;
    while(i<20){
        push(i,s);
        i++;
    }
    for(i=20;i>0;i--){
       printf("%d\n",pop(s));
    }
    int label = 0;
    int c;
    while((c=getchar())!='\n'){
        if(c=='[' || c=='(' || c=='{')
            push(c,s);
        else if(c==']' || c==')' || c=='}'){
            if(IsEmpty(s))
                label = 1;
            else if(abs(c - pop(s))>5)
                label = 1;
        }
    }
    if(!IsEmpty(s))
        label = 1;

    if(label == 0)
        printf("right!");
    else
        printf("error!");
}

