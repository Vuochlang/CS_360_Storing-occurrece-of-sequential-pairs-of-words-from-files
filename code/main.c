#include "all.h"

int main (int argc, char ** argv) {
	int topNumber = 0;
	FILE *fp;
//	char *temp;
	char *first;
	char *second;
	char pair[120] = "";
	char empty[] = "";

	if (argc == 1) { // if user didn't given any  file to read
		printPrompt();
		return -1;
	}
	else {
		int startIndex = 1;
		if (argc > 2 && sscanf(argv[1], "%d", &topNumber) == 1) {
			if (topNumber > 0) {
				printPrompt();
				return -1;
			}
			topNumber *= -1;
			printf("entered count = %d\n", topNumber);
			startIndex = 2;
		}
		for (int i = startIndex; i < argc; i++ ) {
			fp = fopen(argv[i], "r");
		   	if (fp == NULL) {
				printf("Error: %s is not a valid textfile\n", argv[i]);
				printPrompt();
				return -1;
			}
			printf("successfully read %s\n", argv[i]);

            HashTable *hashTable = hashInit(hashTableSize);

			first = getNextWord(fp);
			strncat(pair, first, strlen(first));
			second = getNextWord(fp);
			while (second != NULL) {
				strncat(pair, " ", 1);
				strncat(pair, second, strlen(second));
				printf("here %s\n", pair);
				printf("%s = %u\n", pair, hashIndex(pair));
				pair[0] = '\0';
				first = second;
				strncat(pair, first, strlen(first));
				second = getNextWord(fp);
			}
			puts("out");
			fclose(fp);
			hashFree(hashTable);
		}	
	}
	puts("hrer");
	return 0;	
}

void printPrompt () {
	printf("\nUsage : wordpairs <-count> fileName1 <fileName2> <fileName3> ...\n");
	printf("count : OPTIONAL - number to dislay the top number of pairs\n\n");
}
