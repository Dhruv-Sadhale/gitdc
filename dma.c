#include<stdio.h>
#include<stdlib.h>
int main(){
float *ptr;
ptr=(float*)calloc(5,sizeof(float));
printf("enter 5 float values\n");
for(int i=0;i<5;i++){
    scanf("%f",&ptr[i]);// remember, here there shouldn't be any space character after format specifier, else there is some error in code
}

 if (ptr == NULL) {// this is important, you hadnt written this before
        printf("Memory allocation failed\n");
        return 1;
    }
for(int i=0;i<5;i++){
    printf("%f \n",ptr[i]);
}


    return 0;

}