.SUFFIXES: .c .o
CC = gcc
EXEC = wordpairs
OBJECTS = main.o hash.o crc64.o getWord.o resizeHash.o
HEADERS = getWord.h crc64.h all.h


${EXEC}: ${OBJECTS} ${HEADERS}
	${CC} -o ${EXEC} ${OBJECTS}

.c.o:
	${CC} -c $<

main.o: main.c resizeHash.c getWord.c crc64.c crc64.h getWord.h all.h

hash.o: hash.c all.h

getWord.o: getWord.c getWord.h

crc64.o: crc64.c crc64.h

resizeHash.o: resizeHash.c hash.c all.h

clean:
	rm -rf ${OBJECTS}
