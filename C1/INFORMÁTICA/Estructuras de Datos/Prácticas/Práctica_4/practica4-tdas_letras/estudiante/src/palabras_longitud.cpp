/**
 * palabras_longitud.cpp
 * Programa de prueba para la clase Dictionary
 *
 * Recibe como argumentos:
 * 1. Fichero con las palabras de un diccionario
 * 2. Entero con la longitud de las palabras que buscamos
 *
 * Construye un Dictionary con el fichero de las palabras, extrae de dicho diccionario las palabras de la longitud
 * que buscamos y las imprime por pantalla
 *
 */

#include <iostream>
#include <fstream>
#include "dictionary.h"

int main (int argc, char * argv[]){

    Dictionary diccionario;
    ifstream ruta_fichero;
    string fichero;
    int longitud;

    if (argc != 3){
        cout << "Error: debe de haber 2 parametros " << endl
             << "\t 1. Un fichero con las palabras de un diccionario" << endl
             << "\t 2. Un entero con la longitud de las palabras que buscamos" << endl;
        exit(1);
    }

    else{
        fichero  = argv[1];
        longitud = atoi(argv[2]);
    }

    ruta_fichero.open(fichero);

    if (ruta_fichero)
        ruta_fichero >> diccionario;
    else {
        cout << "Error al abrir el archivo: " << fichero << endl;
        exit(1);
    }

    vector<string> v = diccionario.wordsOfLenght(longitud);

    cout << "Palabras de longitud " << longitud << endl;
    for (int i = 0; i < v.size(); i++) cout << v.at(i) << endl;

    return 0;

}