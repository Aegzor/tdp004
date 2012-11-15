CFILTER=~/bin/gccfilter -a -c
CC=g++
CFLAGS=-c -Wall -Wextra -pedantic -g -std=c++11

all: app

app: main.o console.o ball.o paddle.o
	\$(CC) main.o console.o ball.o paddle.o -lncurses -o app
main.o: main.cc
	$(CFILTER) \$(CC) \$(CFLAGS) main.cc
console.o: console.cc console.h
	$(CFILTER) \$(CC) \$(CFLAGS) console.cc
ball.o: ball.cc ball.h
	$(CFILTER) \$(CC) \$(CFLAGS) ball.cc
paddle.o: paddle.cc paddle.h
	$(CFILTER) \$(CC) \$(CFLAGS) paddle.cc
clean:
	rm -fr *.o app