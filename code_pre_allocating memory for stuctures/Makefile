.SUFFIXES: .c .o
CC = gcc
EXEC = wordpairs

OBJECTS = main.o hash.o crc64.o array.o getWord.o resizeHash.o
HEADERS = getWord.h crc64.h headers.h

${EXEC}: ${OBJECTS} ${HEADERS}
	${CC} -o ${EXEC} ${OBJECTS}

.c.o:
	${CC} -c $<

main.o: main.c resizeHash.c array.c getWord.c ${HEADERS}

hash.o: hash.c crc64.c ${HEADERS}

getWord.o: getWord.c getWord.h

crc64.o: crc64.c crc64.h

resizeHash.o: resizeHash.c hash.c ${HEADERS}

array.o: array.c ${HEADERS}

-PHONY: clean
clean:
	rm -rf ${OBJECTS}
