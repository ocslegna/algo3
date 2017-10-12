CC = g++
CFLAGS = -c -g -Wall
OBJECTS = main.o Ej2.o


all: main 

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Ej2.o: ./Ej2.cpp
	$(CC) $(CFLAGS) ./Ej2.cpp

clean:
	rm -f *.o
	rm -f main
	rm -f output
	rm -rf ./__pycache__/
