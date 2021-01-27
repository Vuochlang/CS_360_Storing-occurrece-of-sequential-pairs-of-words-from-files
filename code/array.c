#include "all.h"

extern int hashTableSize;

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

void printArray(ARRAY* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%10d %s\n", arr[i] . count, arr[i] . word);
    }
}