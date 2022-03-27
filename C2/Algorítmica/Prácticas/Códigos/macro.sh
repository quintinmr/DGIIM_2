#!/bin/bash

echo "" >> salida5.dat
i=10000
a=200000

while [ $i -lt $a ]
do
	./seleccion $i >> salida5.dat
	let i+=7917
done




