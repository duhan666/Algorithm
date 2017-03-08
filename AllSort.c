// all the Sort method


#include <stdlib.h>
#include <stdio.h>
#define alen 20

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
        a[i]=rand()/100;

    for(i=0;i<alen;i++)
        //printf("%d\n",a[i]);

    ShellSort(a,alen);

    for(i=0;i<alen;i++)
        printf("%d\n",a[i]);

}
