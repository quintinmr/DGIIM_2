// Fichero: subimagen.cpp
// Extrae una subimagen de una imagen PGM
//
#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main (int argc, char *argv[]){

    char *origen, *destino; // nombres de los fichero
    int  fil, col, fil_sub, col_sub;
    Image image;

    // Comprobar validez de la llamada
    if (argc != 7){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: subimagen <FichImagenOriginal> <FichImagenDestino>\n";
        exit (1);
    }

    // Obtener argumentos
    origen  = argv[1];
    destino = argv[2];
    fil     = atoi(argv[3]);
    col     = atoi(argv[4]);
    fil_sub = atoi(argv[5]);
    col_sub = atoi(argv[6]);


    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << "Fichero resultado: " << destino << endl;
    cout << "Fila en la que comienza la subimagen: "<< fil << endl;
    cout << "Columna en la que comienza la subimagen: " << col << endl;
    cout << "Número de filas de la subimagen: " << fil_sub << endl;
    cout << "Número de columnas de la subimagen: " << col_sub << endl;

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

    // Calcular la subimagen
    Image subimage;
    subimage = image.Crop(fil, col, fil_sub, col_sub);

    // Guardar la imagen resultado en el fichero
    if (subimage.Save(destino))
        cout  << "La imagen se guardo en " << destino << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    return 0;
}



