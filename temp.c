
#include <stdio.h>
#include <stdlib.h>


int strcomp(char *p,char *s){
    while((*p!='\0') && (*p++==*s++));
    printf("%c  %c\n",*p,*s);
    return *p-*s;
}

void main(){
    int c = strcomp("home","tools");
    printf("%d\n",c);
}

