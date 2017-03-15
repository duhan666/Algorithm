//QuickSort

#include <stdio.h>
#include <stdlib.h>


int getpivot(int*a,int left,int right){
    if(right-left<2){
        printf("this array is only include 2 elements!");
        return -1;
    }
    int mid = (left+right)/2;
    if(a[left]>a[right])
        if(a[left]>a[mid])
            if(a[right]>a[mid])
                return right;
            else
                return mid;
        else
            return left;
    else if(a[left]>a[mid])
        return left;
    else if(a[mid]>a[right])
        return right;
    else
        return mid;
}

void swap(int *a,int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}


void InsertSort(int*a,int left,int right){     //InsertSort is better than QuickSort when the number of elements is less than 20
    int i,j,temp;
    for(i=left+1;i<=right;i++){
        temp = a[i];
        for(j=i;(j>left)&&temp<a[j-1];j--)
            a[j]=a[j-1];
        a[j] = temp;
    }
}

void QuickSort(int*a,int left,int right){
    //printf("remark\n");
    //getchar();
    if(right-left>3){

        int i = left,j = right; //pointer of left and right

        int c = getpivot(a,left,right);

        int pivot = a[c];
        //printf("%d\n",a[c]);

        swap(&a[c],&a[right]);
        j = right - 1;

        while(1){
            while(a[i]<pivot)i++;
            while(a[j]>pivot)j--;
            if(i<j){
                swap(&a[i],&a[j]);
                //printf("%d\t%d\n",a[i],a[j]);
            }
            else
                break;
        }
        swap(&a[i],&a[right]);
        QuickSort(a,left,i-1);
        QuickSort(a,i+1,right);
    }
    else{
        InsertSort(a,left,right);
    }
    int t;
    /*for(t=left;t<=right;t++)
        printf("%d  ",a[t]);
    printf("\n");*/
}

void main(){
    int a[]={9,3,2,1,7,8,6,5,4};
    int N = sizeof(a)/sizeof(int);
    QuickSort(a,0,N-1);
    int i;
    for(i=0;i<N;i++)
        printf("%d\n",a[i]);
}
