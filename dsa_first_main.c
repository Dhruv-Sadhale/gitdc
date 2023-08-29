#include<stdio.h>
#include "dsa_first.c"

int main(){
    int a=2;
int b=3;
    printf("addition of two numbers are\n");
    int sum=0;
    add(&a,&b, &sum);
    printf("%d",sum);
    return 0;
}