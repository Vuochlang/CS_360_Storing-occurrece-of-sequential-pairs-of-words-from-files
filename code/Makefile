.SUFFIXES: .c .o
CC = gcc
EXEC = wordpairs

OBJECTS = main.o hash.o crc64.o array.o getWord.o resizeHash.o
HEADERS = getWord.h crc64.h all.h

${EXEC}: ${OBJECTS} ${HEADERS}
	${CC} -o ${EXEC} ${OBJECTS}

.c.o:
	${CC} -c $<

main.o: main.c resizeHash.c array.c getWord.c crc64.c ${HEADERS}

hash.o: hash.c all.h

getWord.o: getWord.c ${HEADERS}

crc64.o: crc64.c ${HEADERS}

resizeHash.o: resizeHash.c hash.c ${HEADERS}

array.o: array.c ${HEADERS}

-PHONY: clean
clean:
	rm -rf ${OBJECTS}
