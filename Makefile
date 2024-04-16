# Makefile for building the Thread program

CC=gcc
CFLAGS=-Wall -lpthread

# Target to compile the whole program
all: threads

# Compiles the threads program
threads: threads.c
	$(CC) $(CFLAGS) threads.c -o threads
        chmod +x bash_script.sh


# Clean up the compiled files and any output
clean:
	rm -f threads
