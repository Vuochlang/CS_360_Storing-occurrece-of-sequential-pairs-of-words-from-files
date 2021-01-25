#include "all.h"

extern int hashTableSize;

bool needResizeTable (int wordCount) {
    return ((hashTableSize * 5) < wordCount);
}

HashTable* resizeHashTable (HashTable *oldTable) {
    hashTableSize *= 3;
    HashTable* newTable = hashInit();
    HashTable current, temp;
    int index;

    for (int i = 0; i < (hashTableSize / 3); i++) {
        current = oldTable[i] -> next;
        while (current != NULL) {
            temp = current -> next;
            index = hashIndex(current -> wordPair);
            connectOldToNew(newTable[index], current);
            current = temp;
        }
        free(oldTable[i]);
    }
    free(oldTable);
    return newTable;
}

void connectOldToNew (HashTable newTable, HashTable oldTable) {
    if (newTable -> next == NULL) {
        newTable -> next = oldTable;
        oldTable -> next = NULL;
    }
    else {
        HashTable temp = newTable -> next;
        newTable -> next = oldTable;
        oldTable -> next = temp;
    }
}