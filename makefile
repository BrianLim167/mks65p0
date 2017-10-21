all: my_tunez.c my_tunez.h main.c
	gcc -c my_tunez.c my_tunez.h
	gcc -o tunes main.c

run: all
	./tunes
