/**
 * bolsa_letras.cpp
 * Programa de prueba para la clase LettersBag
 *
 * Recibe como argumentos:
 * 1. Archivo a partir del cual crear un LettersSet
 *
 * Extrae aleatoriamente todas las letras de la LettersBag construída a patir del LetterSet , a su vez construído a partir del
 * fichero que se da como argumento, y las imprime por pantalla
 *
 */

#include <iostream>
#include <fstream>
#include "letters_bag.h"

int main(int argc, char * argv[]) {

    LetterSet conjunto_leer;
    ifstream rutaentrada;
    string nombre_fichero;

    if (argc != 2) {
        cout << "Error: debe de haber 1 parametro " << endl
             << "\t Un fichero con las letras, su repeticón y su puntuación" << endl;
        exit(1);
    }

    else
        nombre_fichero = argv[1];

    rutaentrada.open(nombre_fichero);

    if (rutaentrada){
        rutaentrada >> conjunto_leer;
    }
    else {
        cout << "Error al abrir el archivo: " << nombre_fichero << endl;
        exit(1);
    }

    rutaentrada.close();

    LettersBag bolsa (conjunto_leer);

    cout << bolsa;

    return 0;
}

