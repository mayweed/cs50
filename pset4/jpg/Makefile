# Simple Makefile to straight things out de-tedious the process ;)
#

CC=clang

CFLAGS= -ggdb -O0 -std=c99 -Wall -Werror

LDLIBS= -lcrypt -lcs50 -lm

target: *.c
	$(CC) $(CFLAGS) *.c $(LDLIBS) 
