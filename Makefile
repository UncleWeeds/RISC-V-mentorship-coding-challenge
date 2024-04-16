# Makefile for building the Thread program

CC=gcc
CFLAGS=-Wall -lpthread

# Target to compile the whole program
all: threads

# Compiles the threads program
threads: threads.c
	$(CC) $(CFLAGS) threads.c -o threads

permissions:
	chmod +x control_script.sh


# Clean up the compiled files and any output
clean:
	rm -f threads
