CC = g++
CFLAGS = -c -g -Wall
OBJECTS = main.o Ej1.o


all: main 

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Ej1.o: ./Ej1.cpp
	$(CC) $(CFLAGS) ./Ej1.cpp

clean:
	rm -f *.o
	rm -f main
	rm -f output
	rm -rf ./__pycache__/
