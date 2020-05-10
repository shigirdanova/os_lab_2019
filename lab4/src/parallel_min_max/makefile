CC=gcc
CFLAGS=-I. -Wall

all: parallel_min_max #process_memory

#process_memory : process_memory.o
#	$(CC) process_memory.o -o process_memory
	
parallel_min_max : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) $(CFLAGS) -o parallel_min_max utils.o find_min_max.o parallel_min_max.c

#process_memory.o: process_memory.c
#	$(CC) $(CFLAGS) process_memory.c -o process_memory.o

utils.o : utils.h
	$(CC) $(CFLAGS) -o utils.o -c utils.c 

find_min_max.o : utils.h find_min_max.h
	$(CC) $(CFLAGS) -o find_min_max.o -c find_min_max.c


PHONY: clean 
clean:
	-rm *.o parallel_min_max 
	#process_memory

