// Fichero: icono.cpp
// Calcula el icono de una imagen PGM
//
#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main (int argc, char *argv[]){

    char *origen, *destino; // nombres de los ficheros
    Image image;
    int factor;

    // Comprobar validez de la llamada
    if (argc != 4){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino>\n";
        exit (1);
    }

    // Obtener argumentos
    origen    = argv[1];
    destino   = argv[2];
    factor = atoi(argv[3]);



    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << "Fichero resultado: " << destino << endl;
    cout << "Factor de reducción: "<< factor << "x" << factor << endl;

    // Leer la imagen del fichero de entrada
    if (!image.Load(origen)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    // Mostrar los parametros de la Imagen
    cout << endl;
    cout << "Dimensiones de " << origen << ":" << endl;
    cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;

    // Creación del icono

    Image icono;
    icono = image.Subsample(factor);

    // Mostrar parámetros del icono
    cout << endl;
    cout << "Dimensiones de " << destino << ":" << endl;
    cout << "   Icono: " << icono.get_rows() << " filas x " << icono.get_cols() << " columnas " << endl;
    cout << endl;

    // Guardar la imagen resultado en el fichero
    if (icono.Save(destino))
        cout  << "La imagen se guardo en " << destino << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    return 0;
}


