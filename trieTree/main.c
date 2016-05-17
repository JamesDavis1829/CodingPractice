//
// Created by crims_000 on 2/29/2016.
//
#include <stdio.h>
#include <stdlib.h>
#include "trieTree.h"

int main(int argc, char* argv[]){

    printf("Creating the tree\n");
    struct treeNode* tree = createHead();

    printf("Adding a value to the tree\n\n");
    addToTree(tree,15,"tent");
    addToTree(tree,35,"tan");
    addToTree(tree,10,"almost");
    addToTree(tree,400,"can");
    addToTree(tree,560,"back");
    addToTree(tree,11,"delta");
    addToTree(tree,43,"either");
    addToTree(tree,12321,"failure");
    printf("Printing the tree\n");
    printTree(tree, NULL);
    printf("\n");

    printf("Removing almost from the tree\n");
    removeFromTree(tree,"almost");

    printf("Removing black from the tree\n");
    removeFromTree(tree, "black");

    printf("Reprinting the tree\n\n");
    printTree(tree, NULL);

    printf("Searching the tree for tent\n");
    searchTree(tree,"tent");
    printf("Searching the tree for black\n");
    searchTree(tree, "black");

    printf("\nFreeing the tree");
    freeTree(tree);


    return 0;
}
