#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "getWord.h"
#include "crc64.h"

#define LIMIT 120

struct container{
    char *wordPair;
//    char *second;
    int occurrence;
    struct container *next;
};

typedef struct container* HashTable;

void printPrompt ();
void printWords (HashTable*, int);
char* combineWord(char*, char*);
bool needResizeTable (int);

unsigned long long hashIndex (char*);
HashTable* hashInit();
void hashFree (HashTable*);
void hashAdd (HashTable, char*);
void hashPrint (HashTable*);
int searchTable (HashTable, char* );

HashTable* resizeHashTable(HashTable*);
void replace(HashTable, HashTable);
void connectOldToNew (HashTable, HashTable);

