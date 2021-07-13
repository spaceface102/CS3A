CC = g++
DEBUG = -g -DDEBUG
CFLAGS = -ansi -std=c++11 -Wall $(DEBUG) -c
LFLAGS = -Wall $(DEBUG)
EXEC = a.out

all : main

main : main.o bboard.o message.o user.o
	$(CC) $(LFLAGS) $^ -o $(EXEC)

main.o: main.cpp bboard.h message.h user.h
	$(CC) $(CFLAGS) $<

bboard.o: bboard.cpp bboard.h message.h user.h
	$(CC) $(CFLAGS) $<

message.o: message.cpp message.h
	$(CC) $(CFLAGS) $<

user.o: user.cpp user.h
	$(CC) $(CFLAGS) $<

clean:
	rm -f *.o
	rm -f *.out
	rm -f *.exe