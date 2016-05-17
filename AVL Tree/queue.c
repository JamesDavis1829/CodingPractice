//
// Created by crims_000 on 3/13/2016.
//

#include "avlTree.h"
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct qHead* createQ() {
    struct qHead *q = malloc(sizeof(struct qHead));
    q->front = NULL;
    q->back = NULL;
    return q;
}

struct qNode* createNode(struct node* node){
    struct qNode* temp = malloc(sizeof(struct qNode));
    temp->val = node;
    temp->next = NULL;
}

void enq(struct node* node){
    
}