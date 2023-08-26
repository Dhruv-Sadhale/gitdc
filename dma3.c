// this program is an example of how dma memory is passed to a function
// it is just like passing strings, arrays, or pointers for that matter , to a function
#include <stdio.h>
#include <stdlib.h>// always remeber to use this library

void modifyArray(int **arr, int size) {// very important that if you want to reaclloc in another function, you have to pass address of the pointer and then pointer to pointer in the function 
    *arr=(int*)realloc(*arr,7*sizeof(int));
    (*arr)[5]=252;
    (*arr)[6]=32;
    for (int i = 0; i < 5; i++) {
        (*arr)[i] *= 2; // Modify the values in the array
    }
}

int main() {
    int size = 5;
    int *dynamicArray;

    // Allocate memory for an array
    dynamicArray = (int *)malloc(size * sizeof(int));

    if (dynamicArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &dynamicArray[i]);
    }

    modifyArray(&dynamicArray, size); // Pass the dynamically allocated array to the function
    // & if you want to change the size of the array

    printf("Modified array:\n");
    for (int i = 0; i < 7; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    free(dynamicArray); // Free dynamically allocated memory

    return 0;
}
