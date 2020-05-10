CC=gcc
CFLAGS=-I. -Wall

all: parallel_sum

parallel_sum: parallel_sum.o utils.o utils.h sum.o
	$(CC) -o parallel_sum utils.o parallel_sum.o -lpthread -L. sum.o $(CFLAGS)

parallel_sum.o: 
	$(CC) -c parallel_sum.c $(CFLAGS) $(CFLAGS)

utils.o : utils.h
	$(CC) $(CFLAGS) -o utils.o -c utils.c 


sum.o : sum.h
	$(CC) -o sum.o sum.c $(CFLAGS)


clean:
	rm *.o parallel_sum