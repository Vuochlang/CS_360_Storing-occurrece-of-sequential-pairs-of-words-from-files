#include "all.h"



//void listAdd(HashTable sentinel, char* combine) {
//    HashTable newNode, current, previous;
//    current = sentinel->next;
////    temp=malloc(sizeof(struct node));//malloc spaces to store the given data
//    if (current == NULL) {
//        newNode = malloc(sizeof(struct container));
//        newNode->wordPair = malloc(sizeof(combine));
//        strcpy(newNode->wordPair, combine);
//        newNode->occurrence = 1;
//        newNode->next = NULL;
//        sentinel->next = newNode;
//        return;
//    }
//    while (current != NULL) {
//        if (strcmp(current->wordPair, combine) == 0) {
//            current->occurrence += 1;
//            return;
//        }
//        previous = current;
//        current = current->next;
//    }
//    newNode = malloc(sizeof(struct container));
//    newNode->wordPair = malloc(sizeof(combine));
//    strcpy(newNode->wordPair, combine);
//    newNode->occurrence = 1;
//    newNode->next = NULL;
//    previous->next = newNode;
//}

//    HashTable temp, previous, current;
//    previous = sentinel;
//    current = sentinel -> next;
//
//    while (current != NULL) {
//        if (strcmp(current -> wordPair, combine) == 0 ) {
//            current -> occurrence += 1;
//            return;
//        }
//        previous = current;
//        current = current -> next;
//    }
//    temp = malloc(sizeof(struct container));
//    previous -> next = temp;
//    temp -> next = NULL;
//    temp -> wordPair = malloc(sizeof(combine));
//    strcpy(temp -> wordPair, combine);
//    temp -> occurrence += 1;
//}

//void listAdd(HashTable sentinel, char* combine) {
//    HashTable temp, previous;
//    HashTable current = sentinel -> next;
//
//    if (sentinel -> next == NULL) {
//        temp = malloc(sizeof(struct container));
//        sentinel -> next = temp;
//        temp -> next = NULL;
//        temp -> wordPair = malloc(sizeof(combine));
//        strcpy(temp -> wordPair, combine);
//        temp -> occurrence += 1;
//        return;
//    }
//    else {
//        while (current != NULL) {
//            previous = current;
//            if (strcmp(current -> wordPair, combine) == 0 ) {
//                current -> occurrence += 1;
//                return;
//            }
//            current = current -> next;
//        }
//        temp = malloc(sizeof(struct container));
//        previous -> next = temp;
//        temp -> next = NULL;
//        temp -> wordPair = malloc(sizeof(combine));
//        strcpy(temp -> wordPair, combine);
//        temp -> occurrence += 1;
//    }
//}

//void listFree (struct container* sent) {
//    struct container *current;
//    struct container *new = sent -> next;
//    while (new != NULL) {
//        current = new;
//        free(current -> wordPair);
//        free(current);
//        new = new -> next;
//    }
//  //  free(new);
//    free(sent);
//}

//void listPrint (HashTable sentinel) {
//    HashTable temp;
//    temp = sentinel -> next;
//    while (temp != NULL) {
//        printf("%10d %s\n", temp -> occurrence, temp -> wordPair);
//        temp = temp -> next;
//    }
//}


