#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void quickSort(int *array,int begin, int end){
    if(begin < end){
        int l = begin + 1, r = end, piv = array[begin];

        while(l < r){
            if(array[l] <= piv) {
                l++;
            }
            else if(array[r] >= piv){
                r--;
            }
            else{
                swap(&array[l], &array[r]);
            }
        }
        if(array[l] < piv){
            swap(&array[l], &array[begin]);
            l--;
        }
        else {
            l--;
            swap(&array[l], &array[begin]);
        }

        quickSort(array,begin,l);
        quickSort(array,r,end);
    }

}

void printArray(int *array, int len){
    int x;
    printf("[");
    for(x = 0; x < len; x++){
        if(x != len - 1){
            printf("%d, ",array[x]);
        }
        else {
            printf("%d", array[x]);
        }
    }
    printf("]");
}

int main() {

    int array[10] = {0,6,2,7,3,9,4,1,5,8};

    quickSort(array,0, 10);

    printArray(array, 10);

    return 0;
}