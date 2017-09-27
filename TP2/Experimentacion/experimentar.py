# coding=utf-8
"""
Experimentador de TP2.

La idea en principio es tener este script que realice los experimentos en base a
ciertos parámetros, tome el resultado obtenido de la ejecución, y parsee todo a
un archivo con formato csv listo para graficar y analizar.

=== Invocación a TP2
# TP2 [Ej] [Iter] [[argumentos adicionales]] --archivo.in
===

Modo de uso experimentar.py :
    python experimentar.py [Gen] [Ej] [Iter] [[argumentos adicionales]]
		[Ej] = ejercicio:
		    1 -  completar
		    2 -  completar
		    3 -  completar

		[Gen] = generador:
            0 - gen_ejemplo_ejercicio1                  [arg1] .. [argN]
            1 - gen_ejemplo_ejercicio2                  [arg1] .. [argN]
            2 - gen_ejemplo_ejercicio3                  [arg1] .. [argN]

		[Iter] = Cantidad de iteraciones.

        [arg1] = Describir arg1

        ..

        [argN] = Describir argN
"""

import glob
import os
import sys

from os.path import dirname
from os.path import join as path_join

import shutil
import subprocess
from subprocess import call as sp_call

import shlex

import itertools
import random
import re

import parser as p

import scripts.gen_ejemplo_ejercicio1 as ejemplo_ejercicio1
import scripts.gen_ejemplo_ejercicio2 as ejemplo_ejercicio2
import scripts.gen_ejemplo_ejercicio3 as ejemplo_ejercicio3

GENERADOR = {'0': 'ejemplo_ejercicio1',
             '1': 'ejemplo_ejercicio2',
             '2': 'ejemplo_ejercicio3'}

DICC_EJ = {'0': 'definir',
           '1': 'ej1',
           '2': 'ej2',
           '3': 'ej3'}

arg = sys.argv[1:]

# Inicializo python experimentar.py [Gen] [Ej] [iteraciones] [[argumentos adicionales]]
generador = arg[0]
ejercicio = arg[1]
iteraciones = arg[2]
arg3 = arg[3]

def main():
    # Tomo argumentos
    # Corro generador
    # Tomo carpeta con los .in generados recién y corro el experimento en cada uno

    # TODO: Modificar bien esto segun generador que depende ejercicio.
    if generador in ('0', '2'): # generadores que necesiten mismos argumentos
        nombre_carpeta = GENERADOR[generador] + '_' + arg[0] + '_' + arg[3]
        if generador == '0':
            ejemplo_ejercicio1.funcion_principal('input/' + nombre_carpeta, argumento)
        elif generador == '2':
            ejemplo_ejercicio2.funcion_principal('input/' + nombre_carpeta, argumento)

        resolver(nombre_carpeta, iteraciones, argumento)
    elif generador in ('1'): # otro tipo
        nombre_carpeta = GENERADOR[generador] + '_' + arg[0] + '_' + arg[3]
        if generador == '1':
            ejemplo_ejercicio3.funcion_principal('input/' + nombre_carpeta, argumento)

        resolver(nombre_carpeta, iteraciones, argumento)
    else:
        print 'Ingresá correctamente el generador.'
        sys.exit(0)


def dame_programa(ejercicio, iteraciones, argumento):
    my_program = dirname(os.getcwd()) + '/build/TP2'
    # TODO: Modificar
    if ejercicio in ('1','2','3'):
        my_program += ' ' + ejercicio + ' ' + iteraciones
    else:
        print "Ingrese ejercicio correcto."
        sys.exit(0)

    return my_program


def resolver(nombre_carpeta, ejercicio, iteraciones, argumento):
    nombre_carpeta_input = 'input/' + nombre_carpeta
    if not os.path.exists(nombre_carpeta_input):
        print "Error al tomar carpeta en resolver: '" + nombre_carpeta_input + "'"
        sys.exit(1)

    # Creo carpeta de outputs
    output_carpeta = 'output_' + arg[1] + '_' + nombre_carpeta
    output_carpeta_directorio = 'output/' + output_carpeta
    if not os.path.exists(output_carpeta_directorio):
        os.makedirs(output_carpeta_directorio)

    archivo_numero = 1
    for archivo in human_sort(os.listdir(nombre_carpeta_input)):
        if archivo.endswith(".in"):
            if os.path.isfile(path_join(nombre_carpeta_input, archivo)):
                print "Corriendo archivo de input " + archivo
                print "Corriendo archivo: " + str(archivo_numero)
                archivo_numero += 1
                archivo_nuevo = archivo[:-3] + '.out' # Saco .in y meto .out
                with open(path_join(nombre_carpeta_input, archivo), 'r') as my_input:
                    with open(path_join(output_carpeta_directorio, archivo_nuevo), 'w') as my_output:
                        #my_input = open(path_join(nombre_carpeta, archivo), 'r')
                        #my_output = open(path_join(output_carpeta, archivo_nuevo), 'w')
                        my_program = dame_programa(ejercicio, iteraciones, argumento)
                        programa = ['../build/TP2'] + shlex.split(my_program)[1:]
                        #sp_call(programa, stdin=my_input, stderr=my_output)
                        #subprocess.call(programa, stdin= my_input, stderr = my_output)
                        p_popen = subprocess.Popen(programa, stdin=my_input, stderr=my_output)
                        p_popen.wait()
                        #my_input.flush()
                        #my_output.flush()
                        #os.remove(path_join(nombre_carpeta, archivo))

    # os.rmdir(nombre_carpeta)
    # shutil.rmtree(nombre_carpeta)

    """ Tomar .out y correr parser.py """
    if not os.path.exists(output_carpeta_directorio):
        print "Error al tomar carpeta de output: '" + output_carpeta_directorio + "'"
        sys.exit(1)

    # Crear carpeta archivos_jupyter de ser necesario
    archivos_jupyter = 'archivos_jupyter'
    if not os.path.exists(archivos_jupyter):
        os.makedirs(archivos_jupyter)

    # TODO: Modificar si es necesario por ejercicio.
    archivo_nuevo = archivos_jupyter + '/' + GENERADOR[generador] + '_' + arg[0] + '_' + arg[1] + '_' + arg[2] +'.csv'
    for archivo in human_sort(os.listdir(output_carpeta_directorio)):
        """ Genero csv."""
        print "Parseando output " + archivo
        p.parsear_output(DICC_BT[ejercicio],
                         GENERADOR[generador],
                         '_'.join(arg[2:]),
                         path_join(output_carpeta_directorio, archivo),
                         archivo_nuevo)

        #os.remove(path_join(output_carpeta, archivo)) # DESCOMENTAR SI PRIMERA EXPERIMENTACION SALE BIEN, borra TEMP.
        # os.rmdir(output_carpeta)
        # shutil.rmtree(output_carpeta)


def tryint(s):
    try:
        return int(s)
    except Exception:
        return s


def alphanum_key(s):
    """String en lista de string y numbers "z23a" -> ["z", 23, "a"]"""
    return [tryint(c) for c in re.split('([0-9]+)', s)]


def human_sort(l):
    """Sort esperado por humano."""
    return sorted(l, key=alphanum_key)


if __name__ == '__main__':
    main()
