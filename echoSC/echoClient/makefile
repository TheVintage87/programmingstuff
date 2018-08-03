.PHONY: clean

all: echoClient

clean:
	rm -f *.o
	rm -f *.a
	rm -f echoClient

echoClient:client.c main.h
	gcc -Wall -c client.c -o client.o
	ar -rcs libclient.a client.o
	gcc -Wall client.c -L. -l client -o echoClient
