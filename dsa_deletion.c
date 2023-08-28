// to create an array, insert an element and print array if insrtion is successful else dont return array

// remember: In summary, arrays are passed by reference in C, but they are passed as pointers to the first element. This means changes to the elements inside the function will affect the original array.
#include<stdio.h>
void create(int arr[],int total_size,int used_size){
for (int i=0;i<used_size;i++){
    printf("enter element %d ", i);
    scanf("%d",&arr[i]);// you forgot the &

}}
int deletion(int arr[], int total_size,int used_size,int element){
    int index=-1;
   for(int i=0;i<used_size;i++){
    if (element==arr[i]){
        index=i;
        break;

    }}
    if(index==-1){
        return -1;
    }

   
    else{
        for(int i=index+1;i<used_size;i++){
            arr[i-1]=arr[i];

        }
        
    }

}

int main(){
int arr[100];
int total_size=100;
int used_size;
int element;
int insert_index;
printf("enter the number of elements used\n");
scanf("%d",&used_size);
 create( arr, total_size,used_size);
 printf("initial array is \n");
 for(int j=0;j<used_size;j++){
        printf("%d ",arr[j]);
    }
printf("enter number to be deleted\n");
scanf("%d",&element);
int x=deletion(arr, total_size,used_size,element);
if(x==-1){
    printf("unsuccessful\n");
}
else{
    used_size-=1;
    for(int j=0;j<used_size;j++){
        printf("%d ",arr[j]);
    }
}
    return 0;
}