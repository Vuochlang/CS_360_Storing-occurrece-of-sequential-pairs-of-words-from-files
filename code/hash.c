#include "all.h"

HashTable * hashInit() { // initializing the hashTable with the hashTableSize
    HashTable* hashTable = malloc(hashTableSize * (sizeof(HashTable)));
    for (int i = 0; i < hashTableSize; i++)
    {   hashTable[i] = listInit(); //initializing the sentinel node for each table
        hashTable[i] -> wordPair[DICT_MAX_WORD_LEN * 2] = "";
        hashTable[i] -> occurrence = 0;
        hashTable[i] -> next = NULL;
    }
    return (hashTable);
}

unsigned int hashIndex (char* str) {
    return crc64(str) % hashTableSize;
}

void hashFree (HashTable* hashTable) {
    for (int i = 0; i < hashTableSize; i++) { //loop to go through each hashTable
        listFree(hashTable[i]);//free the given hashTable
    }
    free(hashTable);
    printf("free all memory...\n");
}

