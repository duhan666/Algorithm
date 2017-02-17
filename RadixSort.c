
//RadixSort can be based on Array or linked list
//this program is based on Linked list
#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef struct Node{
    int num;
    struct Node* next;
}node;


node* new_node(int x){
    node* tmp = (node*)malloc(sizeof(node));
    if(tmp==NULL)
        return NULL;
    else{
        tmp->next = NULL;
        tmp->num = x;
        //printf("%d\n",tmp->num);
        return tmp;
    }
}


void add_tail_node(int x,node* root){

    while(root->next!=NULL)
        root = root->next;
    root->next = new_node(x);
    //printf("%d\n",x);
}

void add_tail_link(node* root,node* L){
    while(root->next != NULL)
        root = root->next;
    root->next = L->next;
    L->next = NULL;
}

void print_node_num(node* root){
    root = root->next;
    while(root!=NULL){
        printf("%d\n",root->num);
        root = root->next;
        //printf("too");
    }
}

int delete_first_num(node* root){
    node* tmp = root->next;
    root->next = tmp->next;
    int w = tmp->num;
    free(tmp);
    return w;
}

void init(int* a,int N,node* root){
    int i;
    for(i=0;i<N;i++){
        //printf("%d\n",a[i]);
        add_tail_node(a[i],root);
    }
}

int num_num(int *x,int N){    //caculate the max digit of the array
    int j,max=0;
    for(j=0;j<N;j++){
        int e = 0;
        int tmp = x[j];
        while(tmp!=0){
            tmp = tmp/10;
            e++;
        }
        max = max>e?max:e;
    }
    return max;
}

main(){
    int a[] = {1,2,3,4,568,6,7110,8,9};
    int N = sizeof(a)/sizeof(int);
    int D = num_num(a,N);
    //printf("the MAX Digit is %d\n",D);
    int DigBit = 10;

    node* root = new_node(1001);

    init(a,N,root);

    node* L[10];
    int i;
    for(i=0;i<10;i++)
        L[i] = new_node(0);

    for(i=0;i<D;i++){
        while(root->next != NULL){
            int First_num = delete_first_num(root);
            //printf("%d\n",First_num);
            int Digit = First_num/(int)pow(10,i)%10;
            add_tail_node(First_num,L[Digit]);
        }
        //printf("the %d sort\n",i);
        int m;
        for(m=0;m<DigBit;m++){
            add_tail_link(root,L[m]);
        }
        printf("the %d sort\n",i+1);
    }
    print_node_num(root);
}

