CC=gcc
CFLAGS=-I. -Wall
objects=utils.o find_min_max.o

all: sequential_min_max parallel_min_max separate_process_min_max

sequential_min_max : $(objects) utils.h find_min_max.h
	$(CC) -o sequential_min_max $(objects) sequential_min_max.c $(CFLAGS)

parallel_min_max : $(objects) utils.h find_min_max.h
	$(CC) -o parallel_min_max $(objects) parallel_min_max.c $(CFLAGS)

utils.o : utils.h
	$(CC) -o utils.o -c utils.c $(CFLAGS)

find_min_max.o : utils.h find_min_max.h
	$(CC) -o find_min_max.o -c find_min_max.c $(CFLAGS)

separate_process_min_max.o:
	$(CC) $(CFLAGS) -o separate_process_min_max.o -c separate_process_min_max.c

PHONY: clean 
clean:
	-rm *.o sequential_min_max parallel_min_max separate_process_min_max