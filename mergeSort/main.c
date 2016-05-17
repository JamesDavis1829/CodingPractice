#include <stdlib.h>
#include <stdio.h>

void merge(int* a, int alen, int *b, int blen, int *c){
    int i = 0,j = 0,k = 0;

    while(i < alen && j < blen){
        if(a[i] <= b[j]){
            c[k++] = a[i++];
        }
        else{
            c[k++] = b[j++];
        }
    }

    while(i < alen){
        c[k++] = a[i++];
    }

    while(j < blen){
        c[k++] = b[j++];
    }

    return;
}

void mergeSort(int *array, int arrayLen){

    if(arrayLen <= 1)
        return;

    int len1 = arrayLen/2;
    int len2 = arrayLen - len1;

    int* array1 = malloc(sizeof(int) * len1);
    int* array2 = malloc(sizeof(int) * (len2));

    int x;
    for(x = 0; x < len1; x++){
        array1[x] = array[x];
    }

    for(x = 0; x < len2; x++){
        array2[x] = array[x + len1];
    }

    mergeSort(array1, len1);
    mergeSort(array2, len2);
    merge(array1,len1,array2,len2,array);
    free(array1);
    free(array2);
}

void printArray(int *arr, int len)
{
    int x;
    printf("[");
    for(x = 0; x < len; x++){
        if(x != len-1){
            printf("%d, ",arr[x]);
        }
        else{
            printf("%d",arr[x]);
        }
    }
    printf("]");

    return;
}

int main() {

    int arr[10] = {0,8,9,4,3,7,1,5,6,2};

    mergeSort(arr,10);

    printArray(arr, 10);

    return 0;
}