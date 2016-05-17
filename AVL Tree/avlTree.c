//
// Created by crims_000 on 3/12/2016.
//
#include "avlTree.h"
#include <stdio.h>
#include <stdlib.h>

struct node* createAVL(int val){
    struct node* head = malloc(sizeof(struct node));
    head->value = val;
    head->left = NULL;
    head->right = NULL;
    head->height = 1;
    return head;
}

struct node* createNode(int val) {
    return createAVL(val);
}

int max(int a, int b){
    return (a > b)? a : b;
}

int height(struct node *tree){
    if(tree == NULL)
        return 0;
    return tree->height;
}

struct node* rightRotate(struct node* y){
    struct node* x = y->left;
    struct node* T2 = x->right;

    y->left = T2;
    x->right = y;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return x;
}

struct node* leftRotate(struct node* x){
    struct node* y = x->right;
    struct node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBF(struct node* tree){
    if(tree == NULL){
        return 0;
    }
    return height(tree->left) - height(tree->right);
}

struct node* insert(struct node* node, int key){
    if(node == NULL){
        return createNode(key);
    }
    if(key < node->value) {
        node->left = insert(node->left, key);
    }else{
        node->right = insert(node->right, key);
    }

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBF(node);

    if(balance > 1 && key < node->left->value)
        return rightRotate(node);
    if(balance < -1 && key > node->right->value){
        return leftRotate(node);
    }

    if(balance > 1 && key > node->left->value){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance < -1 && key < node->right->value){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct node* minValNode(struct node* tree){
    struct node* current = tree;

    while(current->left != NULL){
        current = current->left;
    }

    return current;
}

struct node* deleteNode(struct node* root, int key){
    if( root == NULL){
        return root;
    }

    if(key < root->value){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->value){
        root->right = deleteNode(root->right, key);
    }else{
        if(root->left == NULL || root->right == NULL){
          struct node* temp = root->left ? root->left : root->right;

            if(temp == NULL){
                temp = root;
                root = NULL;
            }
            else{
                *root = *temp;
            }

            free(temp);
        }
        else{
            struct node* temp = minValNode(root->right);

            root->value = temp->value;

            root->right = deleteNode(root->right, temp->value);
        }
    }

    if(root == NULL){
        return root;
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    int bal = getBF(root);

    if(bal > 1 && getBF(root->left) >= 0){
        return rightRotate(root);
    }

    if(bal > 1 && getBF(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(bal < -1 && getBF(root->right) <= 0){
        return leftRotate(root);
    }

    if(bal < -1 && getBF(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;


}

void printTree(struct node* tree){
    if(tree != NULL){
        printTree(tree->left);
        printf("%d ",tree->value);
        printTree(tree->right);
    }
}

void preOrder(struct node* tree){
    if(tree != NULL){
        printf("%d ", tree->value);
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

int main(void){
    struct node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 175);
    root = insert(root, 234);
    root = insert(root, 20);

    int x;
    for(x = 0; x < 30; x++){
        root = insert(root, x*4);
    }

    root = deleteNode(root, 20);
    printTree(root);
}