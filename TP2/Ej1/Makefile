CC = g++
CFLAGS = -c -g -Wall -std=c++11
OBJECTS = ej1.o

REPETITIONS = 25
N_INSTANCES = 25
MIN_N_WORKS = 5
MAX_N_WORKS = 500
STEP = 20

all: ej1 

ej1: $(OBJECTS)
	$(CC) $(OBJECTS) -o ej1

ej1.o: ej1.cpp
	$(CC) $(CFLAGS) ej1.cpp

create_exp_dir:
	mkdir -p exp
	mkdir -p exp/inputs
	mkdir -p exp/outputs

prepare_exp: create_exp_dir
	i=$(MIN_N_WORKS) ; while [[ $$i -le $(MAX_N_WORKS) ]] ; do \
		python generator.py $(N_INSTANCES) $$i > exp/inputs/input_$$i.in ; \
		(( i = i + $(STEP) )) ; \
	done

run_exp: ej1
	mkdir -p exp/outputs
	i=$(MIN_N_WORKS) ; while [[ $$i -le $(MAX_N_WORKS) ]] ; do \
		./ej1 $(REPETITIONS) < exp/inputs/input_$$i.in >> exp/outputs/output.csv ; \
		(( i = i + $(STEP) )) ; \
	done
	echo "n_works,instance,repetition,algorithm,ticks,time,cost,res_length" > temp_header
	cat temp_header exp/outputs/output.csv > temp_aux && mv temp_aux exp/outputs/output.csv;
	rm -f temp_header

clean_exp:
	rm -rf exp

clean_exp_inputs:
	rm -rf exp/inputs

clean_exp_outputs:
	rm -rf exp/outputs

clean:
	rm -f *.o
	rm -f ej1
