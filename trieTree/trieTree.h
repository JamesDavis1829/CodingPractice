//
// Created by crims_000 on 2/29/2016.
//

#ifndef TRIETREE_TRIETREE_H
#define TRIETREE_TRIETREE_H

#include "dynamicArray.h"

struct treeNode{
    int value;
    char index;
    struct dArray* array;
};

struct treeNode* createHead();

struct treeNode* createNodeNoVal(char index);

struct treeNode* createNodeVal(char index, int val);

void addToTree(struct treeNode* tree,int val, char* string);

void removeFromTree(struct treeNode* tree, char* string);

void printTree(struct treeNode* tree, char *word);

void freeTree(struct treeNode* tree);

void searchTree(struct treeNode* tree, char* index);

#endif //TRIETREE_TRIETREE_H
