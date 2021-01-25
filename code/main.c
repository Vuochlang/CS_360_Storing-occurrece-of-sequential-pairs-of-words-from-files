#include "all.h"

extern int hashTableSize;

int main (int argc, char ** argv) {
	int topNumber = -1; // number of words to print
    int wordPairCount = 0; // total words paired

	FILE *fp;
	char fileName[20];
	char *temp;
	char first[LIMIT], second[LIMIT], combine[LIMIT * 2];

	char sign; // minus sign in front of <count>
	bool isError = false;

	if (argc == 1) { // if user didn't given any  file to read
		printPrompt();
		return -1;
	}
	else {
		int startIndex = 1;
		if (argc > 2 && sscanf(argv[1], "%c%d", &sign, &topNumber) == 2) {
		    if (sign != '-') { // when there's no minus sign in front of the count variable as expected
		        printPrompt();
		        return -1;
		    }
		    startIndex = 2;
		}
        HashTable* hashTable = hashInit();
		for (int i = startIndex; i < argc; i++ ) {
            strcpy(fileName, argv[i]);
            if (strstr(fileName, ".txt") == NULL) // user didn't include extension
                strcat(fileName, ".txt");
			fp = fopen(fileName, "r");
		   	if (fp == NULL) {
                fprintf(stderr,"=====Error: %s is not a valid textfile\n", argv[i]);
				isError = true;
				break;
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
                    strcat(combine, " ");
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
        if (isError) { // if there is a error while reading the file, free the hashTable and leave
            hashFree(hashTable);
            return -1;
        }

        if (topNumber == -1 || topNumber == 0) // if user didn't initialize or user entered 0
            topNumber = wordPairCount;

        if (wordPairCount != 0) { // in case, if the given file is empty, skip the following steps
            ARRAY arr[wordPairCount];
            arrayConnect(hashTable, arr);
            qsort(arr, wordPairCount, sizeof(struct array), sortWords);
            printArray(arr, topNumber);
        }
        else {
            hashFree(hashTable);
            fprintf(stderr, "Warning, file is empty.\n"); // if the given file doesn't have any content
        }
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
