//
// Created by crims_000 on 3/3/2016.
//

#include "HashTable.h"

struct hashTable* createHash(){
    struct hashTable* table = malloc(sizeof(struct hashTable));

    int x;
    for(x = 0; x < TABLESIZE; x++){
        table->array[x].state == OPEN;
    }

    return table;
}

int hashKey(char *name, int add){
    if(name != NULL){
        return (name[0] + add);
    }else{
        return -1;
    }
}

void addToTable(struct hashTable* table, char* name){
    int key = hashKey(name,0);
    int originalKey = key;
    int times = 0;
    while(times >= 0){
        if(table->array[key].state == OPEN){
            table->array[key].state = USED;

            table->array[key].name = malloc(sizeof(char) * strlen(name));
            strcpy(table->array[key].name, name);
            printf("\n%s was added to the table",table->array[key].name);
            break;
        }
        else{
            times++;
            key = hashKey(name,times);
            if(key == originalKey){
                printf("ERROR Table is full");
                break;
            }
        }
    }
}

void searchTable(struct hashTable* table, char *name){
    int key = hashKey(name,0);
    int originalKey = key;

    int times = 0;
    while(times >= 0){
        if(table->array[key].state == OPEN){
            printf("\n%s is not in table",name);
            break;
        }else if(table->array[key].state == DELETED){
            if(strcmp(name,table->array[key].name) == 0) {
                printf("\n%s was in table", name);
                break;
            }
        }else if(table->array[key].state == USED){
            if(strcmp(table->array[key].name,name) == 0){
                printf("\n%s is in the table",name);
                break;
            }
        }
        times++;
        key = hashKey(name,times);
        if(key == originalKey){
            printf("\n%s is not in the table",name);
            break;
        }
    }
}

void removeFromTable(struct hashTable* table, char *name){
    int key = hashKey(name,0);
    int originalKey = key;

    int times = 0;
    while(times >= 0){
        if(table->array[key].state == OPEN){
            printf("\n%s is not in table",name);
            break;
        }else if(table->array[key].state == DELETED){
            if(strcmp(name,table->array[key].name) == 0) {
                printf("\n%s was in table", name);
                break;
            }
        }else if(table->array[key].state == USED){
            if(strcmp(table->array[key].name,name) == 0){
                printf("\n%s has been removed from the table",table->array[key].name);
                table->array[key].state = DELETED;
                break;
            }
        }
        times++;
        key = hashKey(name,times);
        if(key == originalKey){
            printf("\n%s is not in the table",name);
            break;
        }
    }
}

void freeTable(struct hashTable *table){
    int x;
    for(x = 0; x < TABLESIZE; x++){
        if(table->array[x].state == DELETED || table->array[x].state == USED){
            free(table->array[x].name);
        }
    }

    free(table);

    return;
}