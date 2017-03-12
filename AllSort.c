// all the Sort method


#include <stdlib.h>
#include <stdio.h>
#define alen 10

void PrecolateDown(int* a,int i,int N){
    int tmp;
    for(i;2*i+1<N;i=2*i+1){
        int child = 2*i+1;
        if(child<N-1&&a[child]<a[child+1])
            child++;
        if(a[i]<a[child])
            tmp = a[i],a[i]=a[child],a[child]=tmp;
    }
}


void InsertSort(int* a,int N){
    int i,j,temp;
    for(i=1;i<N;i++){
        temp = a[i];
        for(j=i-1;j>=0&&temp<a[j];j--){
            a[j+1] = a[j];
        }
        a[++j] = temp;
    }
}

void ShellSort(int* a,int N){
    int i,j,step,tmp;
    for(step=N/2;step>0;step/=2)
        for(i=step;i<N;i++){
            tmp = a[i];
            for(j=i;j>step;j-=step){
                if(tmp<a[j-step])
                    a[j]=a[j-step];
                else
                    break;
            }
            a[j]=tmp;
        }
}

void main(){
    int a[alen];
    int i;
    for(i=0;i<alen;i++)
        a[i]=rand()%67;

    for(i=0;i<alen;i++)
        printf("%d\n",a[i]);

    PrecolateDown(a,4,10);
    printf("\n");

    for(i=0;i<alen;i++)
        printf("%d\n",a[i]);

}
