CC=gcc
CFLAGS=-g -O -Wall -Werror -std=c11 -pedantic
all:
	$(CC) $(CFLAGS) program.c -o run
	./run<input.txt>TA_output.txt
clean:
	rm run TA_output.txt