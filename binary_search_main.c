#include<stdio.h>
#include<stdlib.h>
#include "binary_search.c"
int main(){
    int size;
    int* ptr;
    int element;
    printf("enter size of array:\n");
    scanf("%d",&size);
    ptr=(int*)calloc(size,sizeof(int));
    for(int i=0;i<size;i++){
        printf("enter element %d \n",(i+1));
        scanf("%d",&ptr[i]);
    }
    if(ptr==NULL){
        printf("unsuccessful entry");
    }
    else{
        printf("enter element to be searched\n");
        scanf("%d",&element);
        int x=binary_search(ptr,size,element);
        if(x!=-1){
            printf("search successful, element found at %d",x);
        }
    }
    free(ptr);
    return 0;
}