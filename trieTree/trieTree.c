#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trieTree.h"

struct treeNode* createHead(){
    struct treeNode* head = malloc(sizeof(struct treeNode));
    head->array = createArray();
    head->value = 0;
    head->index = '\0';

    return head;

}

struct treeNode* createNodeNoVal(char index){
    struct treeNode* node = malloc(sizeof(struct treeNode));
    node->array = createArray();
    node->index = index;
    node->value = 0;

    return node;
}

struct treeNode* createNodeVal(char index, int val){
    struct treeNode* node = malloc(sizeof(struct treeNode));
    node->array = createArray();
    node->index = index;
    node->value = val;

    return node;
}

void addToTree(struct treeNode* tree,int val, char* string){
    struct treeNode *current = tree, *temp;
    int x;
    for(x = 0; x < strlen(string) - 1; x++){
        temp = search(current->array, string[x]);
        if(temp != NULL){
            current = temp;
        }
        else{
            addEntry(current->array, createNodeNoVal(string[x]));
            current = search(current->array, string[x]);
        }
    }

    temp = search(current->array, string[x]);
    if(temp != NULL){
        current = temp;
        temp->value = val;
    }else{
        addEntry(current->array, createNodeVal(string[x], val));
    }

    return;
}

void removeFromTree(struct treeNode* tree, char* string){
    struct treeNode* current = tree, *temp;
    int x;
    for(x = 0; x < strlen(string) - 1; x++){
        temp = search(current->array, string[x]);
        if(temp != NULL){
            current = temp;
        }
        else{
            printf("No node to remove\n");
            return;
        }
    }

    temp = search(current->array, string[x]);
    if(temp != NULL){
        temp->value = 0;
    }
    return;

}

void printTree(struct treeNode* tree, char *word){
    if(tree->array->len < 0){
        if(tree->value != 0)
            printf("%s%c : %d\n",word,tree->index,tree->value);
        return;
    }

    char *newWord = malloc(sizeof(char)*50);
    if(word != NULL){
        sprintf(newWord,"%s%c",word,tree->index);
    }else{
        sprintf(newWord,"%c",tree->index);
    }

    int x;
    for(x = 0; x <= tree->array->len; x++){
        printTree(tree->array->array[x],newWord);
    }

    free(newWord);

}

void searchTree(struct treeNode* tree, char* index){
    struct treeNode* current = tree, *temp;
    int x;
    for(x = 0; x < strlen(index) - 1; x++){
        temp = search(current->array, index[x]);
        if(temp != NULL){
            current = temp;
        }
        else{
            printf("Node not in tree\n");
            return;
        }
    }

    temp = search(current->array, index[x]);
    if(temp != NULL){
        printf("%s : %d\n",index,temp->value);
    }else{
        printf("Node not in tree\n");
    }
    return;

}

void freeTree(struct treeNode* tree){
    if(tree->array->len >= 0){
        int x;
        for(x = 0; x <= tree->array->len; x++){
            freeTree(tree->array->array[x]);
        }
    }
    free(tree->array->array);
    free(tree->array);
    free(tree);
}
