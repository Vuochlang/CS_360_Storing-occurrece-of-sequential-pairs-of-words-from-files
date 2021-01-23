#include "all.h"

int hashTableSize = 10;

HashTable* hashInit() { // initializing the hashTable with the hashTableSize
    HashTable* hashTable = malloc(hashTableSize * (sizeof(HashTable)));
    for (int i = 0; i < hashTableSize; i++)
    {   hashTable[i] = malloc(sizeof(struct container)); //initializing the sentinel node for each table
        hashTable[i] -> occurrence = 0;
        hashTable[i] -> next = NULL;
    }
    return (hashTable);
}

unsigned long long hashIndex (char* str) {
    return crc64(str) % hashTableSize;
}

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
    temp -> wordPair = malloc(120 * sizeof(char));
    strcpy(temp -> wordPair, combine);
    temp -> occurrence = 1;
}

void hashFree (HashTable* hashTable) {
    HashTable current, new;
    for (int i = 0; i < hashTableSize; i++) { //loop to go through each hashTable
        new = hashTable[i] -> next;
        while (new != NULL) {
            current = new;
            new = new -> next;
            free(current -> wordPair);
            free(current);
        }
        free(hashTable[i]);
    }
    free(hashTable);
}

void hashPrint (HashTable* hashTable) {
    HashTable temp;
    char word[240];
    for (int i = 0; i < hashTableSize; i++) {
        temp = hashTable[i] -> next;
        while (temp != NULL) {
            strcpy(word, temp -> wordPair);
            printf("(%d) \t%10d %s\n", i, temp -> occurrence, word);
            temp = temp -> next;
        }
    }
}

//int searchTable (HashTable start, char* combine) {
//    HashTable current = start;
//    HashTable new = start -> next;
//
//    while (new != NULL) {
//        current = new;
//        if (strcmp(current -> wordPair, combine) == 0) {
//            current -> occurrence += 1;
//            return 0;
//        }
//        new = new -> next;
//    }
//    return -1;
//}
//
//bool needResizeTable (int wordCount) {
//    return ((hashTableSize * 5) < wordCount);
//}
//
//HashTable* resizeHashTable (HashTable *oldTable) {
//    hashTableSize *= 3;
//    HashTable* newTable = hashInit();
//    HashTable current, temp;
//    int index;
//    char words[240];
//    int count;
//
//    for (int i = 0; i < (hashTableSize / 3); i++) {
//        current = oldTable[i] -> next;
//        while (current != NULL) {
//            temp = current -> next;
//            index = hashIndex(current -> wordPair);
//            connectOldToNew(newTable[index], current);
//            current = temp;
//        }
//        free(oldTable[i]);
//    }
//    free(oldTable);
//    return newTable;
//}
//
//void connectOldToNew (HashTable newTable, HashTable oldTable) {
//    if (newTable -> next == NULL) {
//        newTable -> next = oldTable;
//        oldTable -> next = NULL;
//    }
//    else {
//        HashTable temp = newTable -> next;
//        newTable -> next = oldTable;
//        oldTable -> next = temp;
//    }
//}
//
//void printWords(HashTable* hashTable, int top) {
////    int limit = 0;
////    if (top != -1)  limit = top;
////    HashTable temp;
////    char word[240];
////    for (int i = 0; i < hashTableSize; i++) {
////        temp = hashTable[i] -> next;
////        while (temp != NULL) {
////
////            strcpy(word, temp -> wordPair);
////            printf("(%d) \t%10d %s\n", i, temp -> occurrence, word);
////            temp = temp -> next;
////        }
////    }
//}

