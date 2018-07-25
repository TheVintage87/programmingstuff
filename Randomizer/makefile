.PHONY: clean

all: randomizer

clean:
	rm -f *.o
	rm -f *.a
	rm -f randomizer

randomizer: Functions.c headerFile.h main.c main.h
	gcc -Wall -c Functions.c -o Functions.o
	ar -rcs libFunc.a Functions.o
	gcc -Wall main.c -L. -l Func -o randomizer
