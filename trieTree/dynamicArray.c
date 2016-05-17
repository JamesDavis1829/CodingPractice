//
// Created by crims_000 on 2/29/2016.
//

#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"


void merge(struct treeNode** arr1, int len1, struct treeNode** arr2, int len2, struct treeNode** arrFin){
    int i = 0,j = 0,k = 0;
    while(i < len1 && j < len2)
    {
        if(arr1[i]->index < arr2[j]->index){
            arrFin[k++] = arr1[i++];
        }
        else{
            arrFin[k++] = arr2[j++];
        }
    }

    while(i < len1){
        arrFin[k++] = arr1[i++];
    }

    while(j < len2){
        arrFin[k++] = arr2[j++];
    }

    return;
}

void sort(struct treeNode** arr, int len){
    int x;

    if(len <= 1){
        return;
    }
    int len1 = len/2;
    int len2 = len - len1;

    struct treeNode** array1 = malloc(sizeof(struct treeNode*) * len1);
    for(x = 0; x < len1; x++){
        array1[x] = malloc(sizeof(struct treeNode));
        array1[x] = arr[x];
    }

    struct treeNode** array2 =malloc(sizeof(struct treeNode*) * len2);
    for(x = 0; x < len2; x++){
        array2[x] = malloc(sizeof(struct treeNode));
        array2[x] = arr[x+len1];
    }

   sort(array1,len1);
   sort(array2, len2);

    merge(array1, len1, array2, len2, arr);

    for(x = 0; x < len1; x++){
        free(array1[x]);
    }
    free(array1);

    for(x = 0; x < len2; x++){
        free(array2[x]);
    }
    free(array2);

}

struct dArray* createArray(){
    struct dArray* arr = malloc(sizeof(struct dArray));

    arr->size = 2;
    arr->len = -1;
    arr->array = malloc(sizeof(struct treeNode*)*arr->size);

    return arr;
}

void addEntry(struct dArray* arr,struct treeNode* data)
{
    arr->len++;
    if(arr->len < arr->size){
        arr->array[arr->len] = data;
    }
    else{
	arr->size = arr->size*2;
	arr->array = realloc(arr->array,sizeof(struct treeNode*) * arr->size);
	arr->array[arr->len] = data;
    }
    //sort(arr->array, arr->len);
}

void removeEntry(struct dArray* arr, int n){
    if(n < arr->len){
        arr->array[n]->value =0;
    }
    return;
}

struct treeNode* search(struct dArray* arr, char index){
    if(arr->len < 0){
        return NULL;
    }

    int x;
    for(x = 0; x <= arr->len; x++){
        if(arr->array[x]->index == index){
            return arr->array[x];
        }
    }

    return NULL;

}

void freeArray(struct dArray* arr){
    int x;
    for(x = 0; x <= arr->len; x++){
        freeTree(arr->array[x]);
    }
    free(arr);
    return;
}

