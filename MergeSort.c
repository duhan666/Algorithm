// all the Sort method


#include <stdlib.h>
#include <stdio.h>
#define alen 10



void Merge(int a[],int tmp[],int Lp,int Rp,int End){
    int ptmp = Lp;
    int bg = Lp;
    int mid = Rp;
    while(ptmp<End+1){
        if(Lp<mid&&Rp<End+1){
            if(a[Lp]<a[Rp])
                tmp[ptmp++] = a[Lp++];
            else
                tmp[ptmp++] = a[Rp++];
        }
        else if(Lp<mid)
            tmp[ptmp++] = a[Lp++];
        else
            tmp[ptmp++] = a[Rp++];
    }
    int i;
    for(i=bg;i<End+1;i++)
        a[i]=tmp[i];


}

void Msort(int a[],int tmp[],int begin,int end){
    int center;
    if(begin<end){
        center = (begin+end)/2;
        Msort(a,tmp,begin,center);
        Msort(a,tmp,center+1,end);
        Merge(a,tmp,begin,center+1,end);
        //printf("Msort\n");
    }
}

void MergeSort(int a[],int N){
    int *tmp = malloc(N*sizeof(int));
    if(tmp!=NULL)
        Msort(a,tmp,0,N-1);
    else
        printf("Not Enough Room For MergeSort!\n");
}

void main(){
    int a[] = {4,3,2,6,1,5,8,6,6,7,9};
    int N = sizeof(a)/sizeof(int);
    //int *tmp=malloc(N*sizeof(int));
    //Merge(a,tmp,2,3,3);
    MergeSort(a,N);
    int i;
    for(i=0;i<N;i++)
        printf("%d\n",a[i]);
}











