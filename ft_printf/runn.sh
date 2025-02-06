#!/bin/bash

# Instrucciones para ejecutar un programa printf_test.c con la librería libftprintf en DIR==.

# Elimino archivos .o, .exe previos
make fclean
rm printf_test.o
rm run

# Compilo mi librería
make

# Paso mi archivo tester a .o
gcc -c printf_test.o printf_test.c

# Creo un ejecutable "run" a partir de mi tester.o y mi librería compilada
gcc -o run printf_test.o -L. -lftprintf

# Ejecuto el archivo "run"
./run



##############################
# Instrucciones de comandos para ejecutar en la terminal

# make fclean && rm printf_test.o && rm run
# make && gcc -c printf_test.o printf_test.c && gcc -o run printf_test.o -L. -lftprintf
# ./run

##############################