#!/bin/bash

echo "" >> peorselec.dat
i=10000
a=200000

while [ $i -lt $a ]
do
	./seleccion $i >> peorselec.dat
	let i+=7917
done




