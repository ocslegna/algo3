#!/usr/bin/env bash

FIELD1=$1
ITERATIONS=$2

# Run experiments.
echo Experimentos del TP2 con ${FIELD1} field:
echo Empezando experimentacion..
echo

for gen in 0 4 6 7 8 
do
    # ejercicio
    for ej in 1 2 3
    do
        # If generator in 0, 2 or 4 run.
        if [[ ${gen} =~ ^(0|2|4|6|7|8)$ ]];
        then
            echo    python experimentar.py ${gen} ${ej} ${ITERATIONS} ${FIELD1}
            python experimentar.py ${gen} ${ej} ${ITERATIONS} ${FIELD1}
        fi

        # If generator in 1, 3 or 5 run.
        if [[ ${gen} =~ ^(1|3|5)$ ]];
        then
            # Por ej, argumento adicional
            for gen_mode in 0 1 2 3 4
            do
                echo    python experimentar.py ${gen} ${ej} ${ITERATIONS} ${FIELD1} ${gen_mode}
                python experimentar.py ${gen} ${ej} ${ITERATIONS} ${FIELD1} ${gen_mode}
            done
        fi
    done
done
