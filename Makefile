CC = gcc
SOURCES = $(basename $(wildcard examples/*.c))

.PHONY: examples tests

tests:
	$(CC) -o tests/main tests/main.c src/bingenere.c tests/unity/src/unity.c
	./tests/main

examples:
	$(foreach file,$(SOURCES),$(CC) -o $(file) $(file).c src/bingenere.c;)