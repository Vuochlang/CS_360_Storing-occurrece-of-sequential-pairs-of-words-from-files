/**
 * @header  headers.h
 * @brief   a collection that contains all declaration for functions, struct(s) and include all headers that will
 *          be used in all .c files
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "getWord.h"
#include "crc64.h"

#define LIMIT 20 // assume 20 is the max characters in a word

/**
 * @struct  container
 * @field   wordPair    to store the each word_pair
 * @field   occurrence  to keep track of how many time that word_pair have been read from the file
 * @field   next        a pointer to the next struct container
 * @brief   will be using this struct to create hashTable and linkedlist
 */
struct container {
    char wordPair[LIMIT*2];
    int occurrence;
    struct container *next;
};
typedef struct container* HashTable;

/**
 * @struct  array
 * @field   word    to store the word_pair
 * @field   count   store the occurrence of the word
 * @discussion  use this struct to combine and store all information from the hashTable
 */
typedef struct array {
    char word[LIMIT*2];
    int count;
}ARRAY;

// in main.c
void printPrompt ();
int sortWords (const void *, const void *);

// in hash.c
unsigned long long hashIndex (char*);
HashTable* hashInit();
void hashFree (HashTable*);
void hashAdd (HashTable, char*);
int searchTable (HashTable, char* );
void hashPrint (HashTable*);

// in resizeHash.c
HashTable* resizeHashTable(HashTable*);
void connectOldToNew (HashTable, HashTable);

// in array.c
void arrayConnect (HashTable*, ARRAY*);
void printArray (ARRAY*, int);