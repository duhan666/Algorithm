// all the Sort method


#include <stdlib.h>
#include <stdio.h>
#define alen 10

void Merge(int*a,int Na,int*b,int Nb){
    int ia,ib,it;
    ia=ib=it=0;
    int tmp[Na+Nb];
    while(it<Na+Nb){
        if(ia<Na&&ib<Nb){
            if(a[ia]<b[ib])
                tmp[it]=a[ia],ia++;
            else
                tmp[it]=b[ib],ib++;
            it++;
        }
        else if(ia>=Na)
            while(ib<Nb)
                tmp[it++] = b[ib++];
        else
            while(ia<Na)
                tmp[it++] = a[ia++];
    }
    for(it=0;it<Na+Nb;it++)
        printf("%d\n",tmp[it]);

}

void main(){
    int a[5]={1,3,4,7,8};
    int b[5]={2,4,6,9,10};
    Merge(a,5,b,5);
}









