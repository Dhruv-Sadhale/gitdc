#include "binary_search.h"
int binary_search(int arr[],int size,int element)
{
    int mid;
    int low=0;
    int high=size-1;
    while(low<=high)
    { mid=(low+high)/2;
        if(element==arr[mid]){
            return mid;
        }
        if(element<arr[mid]){
            high=mid-1;

        }
        else{
            low=mid+1;
        }
    }

if(low>high){
    return -1;
}
}
void sort(int arr[],int size)
{
    for(int i=0;i<size;i++){
        if(arr[i+1]>arr[i])
        {
            arr
        }

    }
}

