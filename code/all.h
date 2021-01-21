#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "getWord.h"
#include "crc64.h"

#define hashTableSize 100

struct container{
    char *wordPair[DICT_MAX_WORD_LEN * 2];
    unsigned int *occurrence;
    struct container *next;
};

typedef struct container* HashTable;

void printPrompt();

unsigned int hashIndex (char*);
HashTable* hashInit();
void hashFree (HashTable*);

HashTable listInit();
void listFree(HashTable);
