wordpairs: main.o getWord.o crc64.o list.o hash.o getWord.h crc64.h all.h
	gcc -o wordpairs main.o hash.o list.o crc64.o getWord.o

main.o: main.c getWord.c crc64.c crc64.h getWord.h all.h
	gcc -c main.c getWord.c crc64.c

hash.o: hash.c all.h
	gcc -c hash.c

list.o: list.c all.h
	gcc -c list.c

getWord.o: getWord.c getWord.h
	gcc -c getWord.c

crc64.o: crc64.c crc64.h
	gcc -c crc64.c
