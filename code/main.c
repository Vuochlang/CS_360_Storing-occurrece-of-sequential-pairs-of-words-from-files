#include "all.h"

extern int hashTableSize;

int main (int argc, char ** argv) {
	int topNumber = -1;
	FILE *fp;
	char *temp;
	char first[120], second[120], combine[240];
	bool isErrorOccur = false;
	int wordPairCount = 0;

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
        HashTable* hashTable = hashInit();
		for (int i = startIndex; i < argc; i++ ) {
			fp = fopen(argv[i], "r");
		   	if (fp == NULL) {
				printf("Error: %s is not a valid textfile\n", argv[i]);
				printPrompt();
				isErrorOccur = true;
				break;
			}
			printf("successfully read %s\n", argv[i]);

		   	temp = getNextWord(fp);
		   	if (temp != NULL) {
		   	    strcpy(first, temp);
		   	    free(temp);
		   	    temp = getNextWord(fp);
		   	    while (temp != NULL) {
                    strcpy(second, temp);
                    free(temp);
                    strcpy(combine, first);
                    strncat(combine, " ", 1);
                    strncat(combine, second, strlen(second));
                    if (needResizeTable(wordPairCount)) {
                        hashTable = resizeHashTable(hashTable);
                        puts("resizing...");
                    }
                    int index = (int)hashIndex(combine);
		   	        if (searchTable(hashTable[index], combine) == -1) { // new words
                        ++wordPairCount;
                        hashAdd(hashTable[index], combine);
                    }
                    strcpy(first, second);
		   	        temp = getNextWord(fp);
                }
		   	    free(temp);
		   	}
		   	fclose(fp);
		}
		printf("word count = %d\n", wordPairCount);
//		hashPrint(hashTable);
		printWords(hashTable, topNumber);
        hashFree(hashTable);
		if (isErrorOccur) {
		    return -1;
		}
	}
	return 0;	
}

void printPrompt () {
	printf("\nUsage : wordpairs <-count> fileName1 <fileName2> <fileName3> ...\n");
	printf("count : OPTIONAL - number to dislay the top number of pairs\n\n");
}
