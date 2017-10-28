#/************************************************************
#*					 MakeFile (2017/2018) 					*
#*					-- Carlos Carvalho --			        *
#*						 28 October						    *
#* 		 > Program to solve N Queen Problem with 			*
#*		    using Array.      	   						    *
#*************************************************************/

CFLAGS = -g -Wall -pedantic 
CC = gcc

all: queens

queens: queens.o numbers.o
	$(CC) $(CFLAGS) -o queens queens.o numbers.o

queens.o: queens.c numbers.h
	$(CC) $(CFLAGS ) -c queens.c 

numbers.o: numbers.c numbers.h
	$(CC) $(CFLAGS ) -c numbers.c 

clean:
	rm -f *.o queens
