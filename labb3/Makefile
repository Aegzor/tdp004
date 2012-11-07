CC=g++
CFLAGS=-c -Wall -Wextra -pedantic -g -std=c++11

all: app

app: main.o console.o ball.o
	\$(CC) main.o console.o ball.o -lncurses -o app
main.o: main.cc
	\$(CC) \$(CFLAGS) main.cc
console.o: console.cc console.h
	\$(CC) \$(CFLAGS) console.cc
ball.o: ball.cc ball.h
	\$(CC) \$(CFLAGS) ball.cc
clean:
	rm -fr *.o app