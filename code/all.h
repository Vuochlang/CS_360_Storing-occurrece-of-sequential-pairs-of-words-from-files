#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "getWord.h"
#include "crc64.h"

#define LIMIT 20 // assume 20 is the max characters in a word

struct container {
    char wordPair[LIMIT*2];
    int occurrence;
    struct container *next;
};
typedef struct container* HashTable;

typedef struct array {
    char word[LIMIT*2];
    int count;
}ARRAY;

void printPrompt ();
int sortWords (const void *, const void *);

unsigned long long hashIndex (char*);
HashTable* hashInit();
void hashFree (HashTable*);
void hashAdd (HashTable, char*);
int searchTable (HashTable, char* );
//void hashPrint (HashTable*);

HashTable* resizeHashTable(HashTable*);
bool needResizeTable (int);
void connectOldToNew (HashTable, HashTable);

void arrayConnect (HashTable*, ARRAY*);
void printArray (ARRAY*, int);