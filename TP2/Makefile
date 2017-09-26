CC=g++
CFLAGS=-std=c++11
BINARIES=main
DEPENDENCIES=build/Ej1.o build/Ej2.o build/Ej3.o
def = defines.o

all: $(BINARIES)

main: $(DEPENDENCIES) main.cpp $(def)
	$(CC) $(CFLAGS) -o ./build/TP2 main.cpp parser.cpp $(def) $(DEPENDENCIES)

build/Ej1.o: Ej1/Ej1.cpp Ej1/Ej1.h $(def)
	$(CC) $(CFLAGS) -o $@ -c $<

build/Ej2.o: Ej2/Ej2.cpp Ej2/Ej2.h $(def)
	$(CC) $(CFLAGS) -o $@ -c $<

build/Ej3.o: Ej3/Ej3.cpp Ej3/Ej3.h $(def)
	$(CC) $(CFLAGS) -o $@ -c $<

defines.o: defines.cpp defines.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f ./build/*

