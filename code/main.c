#include "all.h"

extern int hashTableSize;

int main (int argc, char ** argv) {
	int topNumber = -1;
	FILE *fp;
	char *temp;
	char first[LIMIT], second[LIMIT], combine[LIMIT * 2];
	int wordPairCount = 0;
	char sign;
	char minusSign = '-';
	char fileName[20];

	if (argc == 1) { // if user didn't given any  file to read
		printPrompt();
		return -1;
	}
	else {
		int startIndex = 1;
		if (argc > 2 && sscanf(argv[1], "%c%d", &sign, &topNumber) == 2) {
		    if (sign != minusSign) { // when there's no minus sign in front of the count variable as expected
		        printPrompt();
		        return -1;
		    }
		    startIndex = 2;
		}
        HashTable* hashTable = hashInit();
		for (int i = startIndex; i < argc; i++ ) {
            strcpy(fileName, argv[i]);
            if (strstr(fileName, ".txt") == NULL) // user didn't include extension
                strncat(fileName, ".txt", 4);
			fp = fopen(fileName, "r");
		   	if (fp == NULL) {
                fprintf(stderr,"=====Error: %s is not a valid textfile\n", fileName);
				printPrompt();
				return -1;
			}
//			printf("successfully read %s\n", fileName);

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
                    if (needResizeTable(wordPairCount)) { // resize the HashTable
                        hashTable = resizeHashTable(hashTable);
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
//		printf("Words counter = %d\n", wordPairCount);
//		hashPrint(hashTable);
        if (topNumber == -1 || topNumber == 0) // if user didn't initialize or user entered 0
            topNumber = wordPairCount;

        if (wordPairCount != 0) { // in case, if the given file is empty, skip the following steps
            ARRAY arr[wordPairCount];
            arrayConnect(hashTable, arr);
            qsort(arr, wordPairCount, sizeof(struct array), sortWords);
            printArray(arr, topNumber);
        }
        else
            fprintf(stderr, "Warning, file is empty.\n");
	}
	return 0;	
}

void printPrompt () {
    fprintf(stderr,"\n=====Usage : wordpairs <-count> fileName1 <fileName2> <fileName3> ...\n");
    fprintf(stderr,"=====count : the integer number of word pairs to print out\n");
    fprintf(stderr,"=====fileNameN are pathnames from which to read words\n");
    fprintf(stderr,"=====(tokens enclosed in angular brackets are optional)\n\n");
}

int sortWords (const void *ptr1, const void *ptr2) {
    const ARRAY *p1 = ptr1;
    const ARRAY *p2 = ptr2;
    return p2 -> count - p1 -> count;
}
