// all the Sort method


#include <stdlib.h>
#include <stdio.h>
#define alen 10





void HeapSortPrecolate(int* a,int i,int N){
    int child,temp = a[i];

    for(i;i*2+1<N;i=child){
        child = 2*i+1;

        if(child!=N-1&&a[child]<a[child+1])
            child++;

        if(temp<a[child])
            a[i] = a[child];
        else
            break;

    }

    a[i] = temp;

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

void HeapSort(int* a,int N){
    int i,temp;
    for(i=N/2;i>=0;i--){
        HeapSortPrecolate(a,i,alen);
    }

    for(i=alen-1;i>=0;i--){
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        HeapSortPrecolate(a,0,i);
    }
}


void main(){
    int a[alen];
    int i,temp;
    for(i=0;i<alen;i++)
        a[i]=rand()%67;

    for(i=0;i<alen;i++)
        printf("%d\n",a[i]);

    printf("\n");

    HeapSort(a,alen);
    for(i=0;i<alen;i++)
        printf("%d\n",a[i]);
}









