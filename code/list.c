#include "all.h"

HashTable listInit () {
	HashTable sentinel = malloc(sizeof(struct container));
	return (sentinel);
}

void listFree(HashTable sentinel) { //go through the list of the given sentinel to free everything
    HashTable current;
    HashTable new = sentinel->next;
    while (new != NULL) {
        current = new;
        free(current -> wordPair);
        free(current -> occurrence);
        free(current);
        new = new -> next;
    }
    free(new);
    free(sentinel);
}

