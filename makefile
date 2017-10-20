all: my_tunez.o
	gcc my_tunez.o -o my_tunez

my_tunez.o: my_tunez.c my_tunez.h
	gcc -c my_tunez.c my_tunez.h

run: all
	./my_tunez

clean:
	rm -f *.o
	rm -f *~
