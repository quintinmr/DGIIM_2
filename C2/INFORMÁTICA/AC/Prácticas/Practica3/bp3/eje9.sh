#!/bin/bash

echo "STATIC MONOTONIC CHUNK=1\n"
export OMP_SCHEDULE="monotonic:static,1"
./pmtv-secuencial_matriz_t_inf 10000

echo "DYNAMIC MONOTONIC CHUNK=1\n"
export OMP_SCHEDULE="monotonic:dynamic,1"
./pmtv-secuencial_matriz_t_inf 10000

echo "GUIDED MONOTONIC CHUNK=1\n"
export OMP_SCHEDULE="monotonic:guided,1"
./pmtv-secuencial_matriz_t_inf 10000

echo "STATIC MONOTONIC CHUNK=64\n"
export OMP_SCHEDULE="monotonic:static,64"
./pmtv-secuencial_matriz_t_inf 10000

echo "DYNAMIC MONOTONIC CHUNK=64\n"
export OMP_SCHEDULE="monotonic:static,64"
./pmtv-secuencial_matriz_t_inf 10000


