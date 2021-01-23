#include "all.h"

extern int hashTableSize;

int searchTable (HashTable start, char* combine) {
    HashTable current = start;
    HashTable new = start -> next;

    while (new != NULL) {
        current = new;
        if (strcmp(current -> wordPair, combine) == 0) {
            current -> occurrence += 1;
            return 0;
        }
        new = new -> next;
    }
    return -1;
}

bool needResizeTable (int wordCount) {
    return ((hashTableSize * 5) < wordCount);
}

HashTable* resizeHashTable (HashTable *oldTable) {
    hashTableSize *= 3;
    HashTable* newTable = hashInit();
    HashTable current, temp;
    int index;
    char words[240];
    int count;

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

void printWords(HashTable* hashTable, int top) {
//    int limit = 0;
//    if (top != -1)  limit = top;
//    HashTable temp;
//    char word[240];
//    for (int i = 0; i < hashTableSize; i++) {
//        temp = hashTable[i] -> next;
//        while (temp != NULL) {
//
//            strcpy(word, temp -> wordPair);
//            printf("(%d) \t%10d %s\n", i, temp -> occurrence, word);
//            temp = temp -> next;
//        }
//    }
}