//
// Created by crims_000 on 3/13/2016.
//

#ifndef AVL_TREE_QUEUE_H
#define AVL_TREE_QUEUE_H

#include "avlTree.h"

struct qNode{
    struct node* val;
    struct node* next;
};

struct qHead{
    struct node* front,* back;
};


#endif //AVL_TREE_QUEUE_H
