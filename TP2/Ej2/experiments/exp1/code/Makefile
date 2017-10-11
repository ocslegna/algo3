CC = g++
CFLAGS = -c -g
OBJECTS = main.o Ej2.o


all: main 

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Ej2.o: ./Ej2.cpp
	$(CC) $(CFLAGS) Ej2.cpp

clean:
	rm -f *.o
	rm -f main
	rm -f rinput
	rm -f output_basico
	rm -rf ./__pycache__/
	rm -rf *.pyc
