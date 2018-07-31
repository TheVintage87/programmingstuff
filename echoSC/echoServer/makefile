.PHONY: clean

all: echoServer

clean:
	rm -f *.o
	rm -f *.a
	rm -f echoServer

echoServer: main.c main.h
	gcc -Wall -c main.c -o main.o
	ar -rcs libmain.a main.o
	gcc -Wall main.c -L. -l main -o echoServer
