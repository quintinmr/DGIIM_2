#!/bin/bash

#Titulo: Ejercicio 1 Práctica 1
#Fecha: 20/09/2021
#Autor: Quintín Mesa Romero

cp Descargas/*.gz /tmp

cd /tmp

gunzip *.gz

chmod u+x kernel32-3.0.4

./kernel32-3.0.4 ubda=./Fedora14-x86-root_fs mem=1024m

