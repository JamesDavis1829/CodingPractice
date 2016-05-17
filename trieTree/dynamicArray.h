//
// Created by crims_000 on 2/29/2016.
//

#ifndef TRIETREE_DYNAMICARRAY_H
#define TRIETREE_DYNAMICARRAY_H
#include "trieTree.h"

struct dArray{
    int size;
    int len;
    struct treeNode** array;
};

struct dArray* createArray();

void addEntry(struct dArray* arr,struct treeNode* data);

void removeEntry(struct dArray* arr, int n);

void freeArray(struct dArray* arr);

struct treeNode* search(struct dArray* arr, char index);

#endif //TRIETREE_DYNAMICARRAY_H
