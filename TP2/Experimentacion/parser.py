"""
Parser de output a csv.

Este archivo parsea el output del ejercicio y lo tira en el formato que
definimos en un archivo csv.
"""

import sys
from os.path import isfile as file_exists

def parsear_output(ejercicio, generador, argumentos, f_output, f_destino):
    # TODO: inicializacion de variables y archivo segun ejercicio.
    campo_exp1, campo_exp2, campo_exp3 = '', '', ''
    with open(f_output, 'r') as f_output_open:
        for linea in f_output_open.read().splitlines():
            if linea.startswith('campo_exp1'):
                campo_exp1 = linea[len('campo_exp1') + 1:]
            elif linea.startswith('campo_exp2'):
                campo_exp2 = linea[len('campo_exp2') + 1:]
            elif linea.startswith('campo_exp3'):
                campo_exp3 = linea[len('campo_exp3') + 1:]

    titulos = not file_exists(f_destino)
    with open(f_destino, 'a') as f_destino_open:
        if titulos:
            # TODO: modificar
            f_destino_open.write("ejercicio,generador,argumentos,campo_exp1,campo_exp2,campo_exp3\n")

        # TODO: modificar
        lista_cosas = [ejercicio,generador,argumentos,campo_exp1,campo_exp2,campo_exp3]
        f_destino_open.write(','.join(lista_cosas))
        f_destino_open.write('\n')

if __name__ == '__main__':
    args = sys.argv[1:]
    # TODO: modificar
    # Determinar cantidad de parametros necesarios, segun ejercicio.
    if len(args) < 5:
        print ("Necesito 5 parametros minimo")
        sys.exit(1)
    # TODO: modificar
    parsear_output(args[0], args[1], args[2], args[3], args[4])
