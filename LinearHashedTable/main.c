#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "HashTable.h"

int main() {

    struct hashTable* table = createHash();

    addToTable(table,"George");
    addToTable(table,"Henry");
    addToTable(table, "Johnny");

    searchTable(table, "Johnny");
    searchTable(table, "Geff");

    removeFromTable(table, "Johnny");
    searchTable(table,"Johnny");

    return 0;
}