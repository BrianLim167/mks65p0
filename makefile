all: my_tunez.o main.o
	gcc -o tunes my_tunez.o main.o

my_tunez.o: my_tunez.c my_tunez.h
	gcc -c my_tunez.c my_tunez.h

main.o: main.c
	gcc -c main.c

run: all
	./tunes

clean:
	rm -f *.o
	rm -f *~
