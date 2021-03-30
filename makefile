CC=gcc
CFLAGS=-Wall -std=c99 

A4: testA4.o helper.o queueFunctions.o miscFunctions.o
	$(CC) testA4.o helper.o queueFunctions.o miscFunctions.o -o A4 
testA4.o: testA4.c headerA4.h 
	$(CC) $(CFLAGS) -c testA4.c 
miscFunctions.o: miscFunctions.c headerA4.h
	$(CC) $(CFLAGS) -c  miscFunctions.c 
queueFunctions.o: queueFunctions.c headerA4.h
	$(CC) $(CFLAGS) -c queueFunctions.c 
helper.o: helper.c headerA4.h
	$(CC) $(CFLAGS) -c helper.c 

clean:
	rm *.o A4
