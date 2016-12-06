CC=gcc
CFLAGS=-Wall

all: part1 part2

part1: part1.c
	$(CC) $(CFLAGS) part1.c -o part1.out -lssl -lcrypto

part2: part2.c
	$(CC) $(CFLAGS) part2.c -o part2.out

clean:
	rm -rf part*.out
