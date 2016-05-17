//
// Created by crims_000 on 3/3/2016.
//

#ifndef LINEARHASHEDTABLE_HASHTABLE_H
#define LINEARHASHEDTABLE_HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define TABLESIZE 103

enum states {OPEN, DELETED, USED};

struct hashNode{
    char *name;
    enum states state;
};

struct hashTable{
    struct hashNode array[TABLESIZE];
};

struct hashTable* createHash();

void addToTable(struct hashTable* table, char* name);

void searchTable(struct hashTable* table, char *name);

void removeFromTable(struct hashTable* table, char *name);

void freeTable(struct hashTable *table);

#endif //LINEARHASHEDTABLE_HASHTABLE_H
