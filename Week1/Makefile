# Simple Makefile to straight things out de-tedious the process ;)
#

CC=clang

CFLAGS= -ggdb -std=c99 -Wall -Werror

LDLIBS= -lcrypt -lcs50 -lm

target: *.c
	$(CC) $(CFLAGS) *.c $(LDLIBS) 
