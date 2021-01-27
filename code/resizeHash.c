#include "all.h"

extern int hashTableSize;

/**
 * @function    needResizeTable
 * @param       wordCount   a total word count that has been stored in the hashTable
 * @return      True-resize the table, otherwise return False
 */
bool needResizeTable (int wordCount) {
    return ((hashTableSize * 5) < wordCount);
}

/**
 * @function    resizeHashTable
 * @brief       initialize a new hashTable by factor the hash table size by 3
 *              loop through the old hashTable,
 *              get each wordPair and hash it to get a new index,
 *              connect that specific old hashTable entry to the new hashTable with the new index entry
 * @param       oldTable    a pointer to an old hashTable
 * @return      a pointer to the new hashTable
 */
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

/**
 * @function    connectOldToNew
 * @brief       connect the oldTable to the next pointer of the newTable
 * @param       newTable    a pointer to a specific entry of the new hashTable
 * @param       oldTable    a pointer to a specific list of a specific entry of the old hashTable
 */
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