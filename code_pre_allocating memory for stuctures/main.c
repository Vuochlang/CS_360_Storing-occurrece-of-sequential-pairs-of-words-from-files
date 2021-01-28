// Vuochlang Chang
// 01/27/2021

#include "headers.h"

extern int hashTableSize;

/**
 * @mainpage
 * @param       argc
 * @param       argv
 * @brief       read from arguments and check each arguments,
 *              if text file name is given, check if it's a valid text file otherwise return -1
 *              if <-count> is given, check if it's a valid number otherwise return -1
 * @return      -1 when specified error occur, otherwise return 0
 */
int main (int argc, char ** argv) {
	int topNumber = -1; // number of words to print
    int wordPairCount = 0; // total words paired

	FILE *fp;
	char fileName[100];
	char *temp;
	char first[LIMIT], second[LIMIT], combine[LIMIT * 2];

	bool isError = false;

    HashTable* hashTable;
    ARRAY* arr;

	if (argc == 1) { // if user didn't given any  file to read
		printPrompt();
		return -1;
	}
	else {
		int startIndex = 1;
		if (argc > 2 && sscanf(argv[1], "%d", &topNumber) == 1) {
		    if (topNumber == 0) {
                fprintf(stderr, "--------> Error: entered %d as count, program won't print anything\n", topNumber);
		        printPrompt();
		        return -1;
		    }
		    else if (topNumber > 0) {
                fprintf(stderr, "--------> Error: entered <%d> instead of <-%d>\n", topNumber, topNumber);
		        printPrompt();
		        return -1;
		    }
		    else
		        topNumber *= -1;
		    startIndex = 2;
		}

        hashTable = hashInit();
		for (int i = startIndex; i < argc; i++ ) {
            strcpy(fileName, argv[i]);
            if (strstr(fileName, ".txt") == NULL) // when user didn't include the file extension
                strcat(fileName, ".txt");
			fp = fopen(fileName, "r");
		   	if (fp == NULL) {
                fprintf(stderr, "--------> Error: %s is not a valid textfile\n", argv[i]);
				isError = true;
				break;
			}
//			printf("successfully read %s\n", fileName);

		   	temp = getNextWord(fp);
		   	if (temp != NULL) { // if the file is not empty
		   	    strcpy(first, temp);
		   	    free(temp);
		   	    temp = getNextWord(fp);
		   	    while (temp != NULL) { // keep reading from the file until reach the end of the file
                    strcpy(second, temp);
                    free(temp);
                    strncpy(combine, first, LIMIT);
                    strcat(combine, " ");
                    strncat(combine, second, LIMIT); // concatenate the first and second word

                    int index = (int)hashIndex(combine); // hashing the word_pair to get the index

                    int searchResult = searchTable(hashTable[index], combine);
		   	        if (searchResult > -1) { // when the word_pair is a new word
		   	            if (searchResult == 5) { // meet the max collision then resize hash table
                            hashTableSize *= 5;
                            hashTable = resizeHashTable(hashTable);
                            index = (int)hashIndex(combine); // get new index in new table
                        }
		   	            ++wordPairCount;
                        hashAdd(hashTable[index], combine);
                    }
                    strncpy(first, second, LIMIT); // second word becomes the first word for the next word_pair
		   	        temp = getNextWord(fp);
                }
		   	    free(temp);
		   	}
		   	fclose(fp);
		}
//		printf("Word counter = %d\n", wordPairCount);
//		hashPrint(hashTable);

        if (isError) { // if there is a error while reading the file, free the hashTable and leave
            hashFree(hashTable);
            return -1;
        }

        if (topNumber == -1) // if user didn't initialize a <-count> in the argument
            topNumber = wordPairCount;

        if (wordPairCount != 0) { // in case, if the given file is empty, skip the following steps
            arr = malloc(wordPairCount * sizeof(struct array));
            arrayConnect(hashTable, arr);
            qsort(arr, wordPairCount, sizeof(struct array), sortWords);
            printArray(arr, topNumber);
            free(arr);
        }
        else {
            hashFree(hashTable);
            fprintf(stderr, "Warning, file is empty.\n"); // if the given file doesn't have any content, output a warning
        }
	}
	return 0;	
}

/**
 * @function    printPrompt
 * @brief       print the Usage of the code
 */
void printPrompt () {
    fprintf(stderr, "\n--------> Usage : wordpairs <-count> fileName1 <fileName2> <fileName3> ...\n");
    fprintf(stderr, "--------> count : the integer number of word pairs to print out\n");
    fprintf(stderr, "--------> fileNameN are pathnames from which to read words\n");
    fprintf(stderr, "--------> (tokens enclosed in angular brackets are optional)\n\n");
}

/**
 * @function    sortWords
 * @param       ptr1
 * @param       ptr2
 * @return      0, 1,
 */
int sortWords (const void *ptr1, const void *ptr2) {
    const ARRAY *p1 = ptr1;
    const ARRAY *p2 = ptr2;
    return p2 -> count - p1 -> count;
}
