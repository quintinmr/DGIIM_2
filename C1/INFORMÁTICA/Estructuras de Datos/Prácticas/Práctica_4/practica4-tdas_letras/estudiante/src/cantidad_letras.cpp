/**
 * cantidad_letras.cpp
 * Programa de prueba de la clase Dictionary

  Recibe dos argumentos
    1. Un fichero con las palabras de un diccionario
    2. Un fichero de letras

    Construye un Dictionary con el fichero de palabras, un LettersSet con el fichero de letras, e imprime
    por pantalla, para cada letra en el LettersSet, el número de ocurrencias de la letra en el diccionario y
    su frecuencia relativa (es decir, el número total de ocurrencias de la letra entre el número total de
    letras en el diccionario).

*/

#include "letters_set.h"
#include "dictionary.h"
#include <fstream>
using namespace std;

int main (int argc, char * argv[]) {

    Dictionary diccionario;
    LetterSet conjuntoletras;
    string rutaDiccionario, rutaConjuntoLetras;
    ifstream fi1, fi2;
    double ocurrencias = 0, totalLetrasDiccionario = 0;
    char letra;

    if (argc != 3) {
        cout << "Error: debe de haber 2 parametros " << endl
             << "\t 1. Un fichero con las palabras de un diccionario." << endl
             << "\t 2. Un fichero de letras" << endl;
        exit(1);
    } else {
        rutaDiccionario = argv[1];
        rutaConjuntoLetras = argv[2];
    }

    fi1.open(rutaDiccionario);
    fi2.open(rutaConjuntoLetras);

    if (fi1) {
        fi1 >> diccionario;
    } else {
        cout << "Error al abrir el archivo: " << rutaDiccionario << endl;
        exit(1);
    }

    if (fi2) {
        fi2 >> conjuntoletras;
    } else {
        cout << "Error al abrir el archivo: " << rutaConjuntoLetras << endl;
        exit(1);
    }

    fi1.close();
    fi2.close();

    totalLetrasDiccionario = diccionario.getTotalLetters();

    cout << "Letra" << "\t" << "FAbs." << "\t" << "Frel." << endl;
    for (LetterSet::iterator i = conjuntoletras.begin(); i != conjuntoletras.end(); ++i) {
        letra = (*i).first;
        ocurrencias = diccionario.getOccurrences(letra);
        cout << letra << "\t" << ocurrencias << "\t" << ocurrencias/totalLetrasDiccionario << endl;
    }

    return 0;
}

