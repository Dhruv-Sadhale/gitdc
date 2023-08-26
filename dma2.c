#include<stdio.h>// you fool, this is an int array , similarly you can use char for string 
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
//here i think we shouldnt free ptr
// instead of this ptr=realloc(ptr,8);
ptr = (float *)realloc(ptr, 8 * sizeof(float));// do this instead, this is important 
if (ptr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
printf("enter values again 8: \n");
for(int i=0;i<8;i++){
   scanf("%f",&ptr[i]);
   }
for(int i=0;i<8;i++){
    printf("%f \n",ptr[i]);}

free(ptr);

    return 0;

}