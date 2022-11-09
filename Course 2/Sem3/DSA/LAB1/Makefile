all: obj/brtree.o obj/main.o
	gcc -Wall -o rbtree obj/brtree.o obj/main.o

obj/main.o: src/main.c
	gcc -c src/main.c
	mv main.o obj/

obj/brtree.o: src/brtree.c src/brtree.h
	gcc -c src/brtree.c
	mv brtree.o obj/
