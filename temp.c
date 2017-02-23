
#include <stdio.h>
#include <stdlib.h>



void main(){
char s[10]= "12345";
char *p = "abcdef";

*(p+1) = 'w';

printf("%c\n",*p);

}

