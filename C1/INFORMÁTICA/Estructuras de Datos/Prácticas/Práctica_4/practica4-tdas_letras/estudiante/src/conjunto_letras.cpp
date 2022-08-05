/**
 * conjunto_letras.cpp
 * Programa de prueba para la clase LetterSet
 *
 * Recibe como argumentos:
 * 1. Archivo a partir del cual crear un LettersSet
 * 2. Palabra a la que calcular la puntuación
 *
 * Imprime por pantalla la puntuación de la palabra introducida como parámetro
 *
 */

#include <iostream>
#include <fstream>
#include "letters_set.h"

int main(int argc, char *argv[]) {

    string fichero, palabra;
    fstream ruta_fichero;
    LetterSet conjunto;

    if (argc != 3){
        cout << "Error: debe de haber 2 parametros " << endl
             << "\t 1. Un fichero con las letras, su repeticón y su puntuación" << endl
             << "\t 2. Una palabra a la que calcular su puntuación" << endl;
        exit(1);
    }

    else {
        fichero = argv[1];
        palabra = argv[2];
    }

    ruta_fichero.open(fichero);

    if (ruta_fichero) ruta_fichero >> conjunto;
    else {
        cout << "Error al abrir el archivo: " << fichero << endl;
        exit(1);
    }

    ruta_fichero.close();

    cout << conjunto.getScore(palabra) << endl;

    return 0;
}
