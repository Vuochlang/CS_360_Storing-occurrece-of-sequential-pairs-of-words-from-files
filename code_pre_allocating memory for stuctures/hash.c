#include "headers.h"

int hashTableSize = 10; // a global variable

/**
 * @function    hashInit
 * @brief       initializing the hashTable according to the global-hashTableSize
 * @return      a pointer to the initialized hashtable
 */
HashTable* hashInit() {
    HashTable* hashTable = malloc(hashTableSize * (sizeof(HashTable)));
    for (int i = 0; i < hashTableSize; i++)
    {   hashTable[i] = malloc(sizeof(struct container)); //initializing the sentinel node for each table
        hashTable[i] -> occurrence = 0;
        hashTable[i] -> next = NULL;
    }
    return (hashTable);
}

/**
 * @function    hashIndex
 * @param       str     a pointer to the word_pair
 * @return      index to the corresponding hashTable entry
 */
unsigned long long hashIndex (char* str) {
    return crc64(str) % hashTableSize;
}

/**
 * @function    hashAdd
 * @brief       create a new hashTable to store combine
 *              and connect that new hashTable to be the first next node after the sentinel
 * @param       sentinel    a pointer to the specific hashTable
 * @param       combine     a pointer to the word_pair that read from the file
 */
void hashAdd(HashTable sentinel, char* combine) {
    HashTable temp, current;
    temp = malloc(sizeof(struct container));
    if (sentinel -> next != NULL) {
        temp -> next = sentinel -> next;
        sentinel -> next = temp;
    }
    else {
        temp->next=NULL;
        sentinel->next=temp;
    }
    strcpy(temp -> wordPair, combine);
    temp -> occurrence = 1;
}

/**
 * @function    searchTable
 * @brief       loop through the hashTable start and compare if the given combine already exist
 * @param       start   a pointer to a specific hashTable entry
 * @param       combine a pointer to the word_pair that read from the file
 * @return      0 when the word_pair already exist, otherwise return the depth of the given hashTable
 */
int searchTable (HashTable start, char* combine) {
    HashTable current = start;
    HashTable new = start -> next;
    int depth = 0;

    while (new != NULL) {
        depth += 1;
        current = new;
        if (strcmp(current -> wordPair, combine) == 0) { // when the word_pair already exist, just increment the count
            current -> occurrence += 1;
            return -1;
        }
        new = new -> next;
    }
    return depth; // count is the depth of the hashTable
}

/**
 * @function    hashFree
 * @brief       free each hashTable entry and the hashTable itself
 * @param       hashTable   a pointer to the hashTable
 */
void hashFree (HashTable* hashTable) {
    HashTable current, new;
    for (int i = 0; i < hashTableSize; i++) { //loop to go through each hashTable
        new = hashTable[i] -> next;
        while (new != NULL) {
            current = new;
            new = new -> next;
            free(current);
        }
        free(hashTable[i]);
    }
    free(hashTable);
}

/**
 * @function    hashPrint
 * @brief       loop through each entry of the hashTable and print its content
 * @param       hashTable   a pointer to the hashTable
 */
void hashPrint (HashTable* hashTable) {
    HashTable temp;
    for (int i = 0; i < hashTableSize; i++) {
        temp = hashTable[i] -> next;
        while (temp != NULL) {
            printf("(%d) \t%10d %s\n", i, temp -> occurrence, temp -> wordPair);
            temp = temp -> next;
        }
        printf("------------------------------------\n");
    }
}