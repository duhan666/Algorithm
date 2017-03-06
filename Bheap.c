// binary  heap

#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define MinData -1

struct bHeap;
typedef struct bHeap heap;
typedef heap* heapp;

struct bHeap{
    int hsize;
    int hcapacity;
    int* hp;
};

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

heapp initilize(){
    heapp p = malloc(sizeof(heap));
    if(p == NULL){
        printf("Out of Space!");
        return NULL;
    }
    p->hcapacity = MAX;
    p->hsize = 0;
    p->hp = malloc((MAX+1)*sizeof(int));
    if(p->hp == NULL){
        printf("Out of Space!");
        return NULL;
    }
    p->hp[0] = 0;
    return p;
}

void hinsert(int x,heapp H){
    int i;

    if(H->hsize>=H->hcapacity){
        printf("the Binary Heap is Full!");
        return;
    }

    i = ++H->hsize;
    H->hp[i] = x;
    while(H->hp[i]<H->hp[i/2]){
        swap(&H->hp[i],&H->hp[i/2]);
        i=i/2;
    }
}

int hdelmin(heapp H){
    int i = 1;
    int min = H->hp[1];
    int last = H->hp[H->hsize];
    printf("the last one is %d\n",last);
    while(2*i+1<H->hsize){
        if(H->hp[2*i]<H->hp[2*i+1]){
            H->hp[i] = H->hp[2*i];
            i = 2*i;
        }
        else{
            H->hp[i] = H->hp[2*i+1];
            i = 2*i+1;

        //printf("%d\n",i);
        }
    }
    //printf("the last i is %d\n",i);
    //printf("the last itoho is %d\n",H->hp[13]);
    H->hp[i] = last;
    H->hsize--;
    return min;
}

void printheep(heapp H){
    int i;
    for(i=1;i<=H->hsize;i++)
        printf("%d\n",H->hp[i]);
}

void main(){
    heapp root;
    root = initilize();
    int a[]={24,31,19,13,21,16,68,65,26,32};
    int N = sizeof(a)/sizeof(int);
    int i;
    for(i=0;i<10;i++)
        hinsert(a[i],root);

    printheep(root);

    int c;
    c = hdelmin(root);
    printf("the deleted one is %d\n",c);
    c = hdelmin(root);
    printf("the deleted one is %d\n",c);

    printheep(root);
}

