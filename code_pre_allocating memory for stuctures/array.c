#include "headers.h"

extern int hashTableSize;

/**
 * @function    arrayConnect
 * @brief       combine data that are stored in hashTable into array
 * @param       table   a pointer to the HashTable
 * @param       arr     a pointer to the Array
 */
void arrayConnect (HashTable* table, ARRAY* arr) {
    int index = 0;
    HashTable tableNode, temp;
    for (int i = 0; i < hashTableSize; i++) {
        tableNode = table[i] -> next;
        while (tableNode != NULL) {
            temp = tableNode -> next;
            strcpy(arr[index] . word, tableNode -> wordPair);
            arr[index] . count = tableNode -> occurrence;
            ++index;
            free(tableNode);
            tableNode = temp;
        }
        free(table[i]);
    }
    free(table);
}

/**
 * @function    printArray
 * @brief       print all word pairs and their occurrence counts
 * @param       arr     a pointer to the Array
 * @param       size    size of the Array
 */
void printArray(ARRAY* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%10d %s\n", arr[i] . count, arr[i] . word);
    }
}