#include <stdio.h>



//solution 1:
int Max_seq1(int a[],int N){
    int maxsum = 0;
    int sum=0;
    int i,j;
    for(i=0;i<N;i++){
        for(j=i;j<N;j++){
            sum += a[j];
            //printf("%d\t",sum);
            if(sum>maxsum)
                maxsum = sum;
        }
        sum = 0;
    }
    return maxsum;
}

int Max_seq2(int a[],int N){
    int maxsum = 0;
    int sum = 0;
    int i;

    for(i=0;i<N;i++){
        sum +=a[i];
        if(sum > maxsum)        //ingenious method
            maxsum = sum;
        else if(sum < 0)
            sum = 0;
    }
    return maxsum;
}



void main(){
    int a[]  = {-2,11,-4,13,-5,-2};
    int N =  sizeof(a)/sizeof(int);
    printf("%d\n",Max_seq2(a,N));
    printf("%d\n",Max_seq1(a,N));
}





