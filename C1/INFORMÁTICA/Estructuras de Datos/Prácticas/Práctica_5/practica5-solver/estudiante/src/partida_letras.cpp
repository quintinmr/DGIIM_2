#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n) {
    if(n < 0) return 0;
    else if(n > 1) return n*factorial(n-1);
    return 1;
}

int main (){

    int contador = 1;

    while ((pow(100,contador) >= factorial(contador))){
        contador++;
    }

    cout << "El numero que buscas es " << contador;

    return 0;
}

/*
#include "solver.h"
#include "letters_bag.h"
#include "fstream"

int main (int argc, char *argv[]){

    // Inicializamos el generador de números aleatorios
    srand(time(NULL));

    string archivo1, archivo2;
    int cantidad_letras;
    fstream ruta_archivo_letras, ruta_archivo_diccionario;
    LetterSet c1;
    Dictionary d1;
    bool score_game;

    // Comprobamos los argumentos
    if (argc != 5){
        cout << "Error: debe de haber 4 parametros " << endl
             << "\t 1. Un fichero con las letras y su puntuación." << endl
             << "\t 2. Un fichero de con el diccionario" << endl
             << "\t 3. Modo de juego (L = Longitud, P = puntuación)" << endl
             << "\t 4. Cantidad de letras para la partida" << endl;
        exit(1);
    }
    else{
        archivo1        = argv[1];
        archivo2        = argv[2];
        if (argv[3][0] == 'P')
            score_game = true;
        else
            if (argv[3][0] == 'L')
                score_game = false;
        cantidad_letras = stod(argv[4]);
    }

    ruta_archivo_letras.open(archivo1);

    if (ruta_archivo_letras){
        ruta_archivo_letras >> c1;
    }
    else {
        cout << "Error al abrir el archivo: " << archivo1 << endl;
        exit(1);
    }

    ruta_archivo_diccionario.open(archivo2);

    if (ruta_archivo_diccionario){
        ruta_archivo_diccionario >> d1;
    }
    else
    {
        cout << "Error al abrir el archivo: " << archivo2 << endl;
        exit(1);
    }

    ruta_archivo_diccionario.close();
    ruta_archivo_letras.close();

    //Creación del LettersBag que se usará para la extracción de las letras
    LettersBag bolsa (c1);

    //Extracción de las letras
    vector<char> extraccion = bolsa.extractLetters(cantidad_letras);

    Solver resolver (d1, c1);

    //Buscamos las soluciones
    pair<vector<string>, int> soluciones;

    soluciones = resolver.getSolutions(extraccion, score_game);

    //Salida
    cout << "LETRAS DISPONIBLES: " << endl;
    for(int i=0; i<extraccion.size(); i++){
        cout << extraccion.at(i) <<" ";
    }
    cout << endl;

    cout << "SOLUCIONES: " << endl;
    for(int i=0; i<soluciones.first.size(); i++){
        cout << soluciones.first.at(i) << endl;
    }

    cout << "PUNTUACION:" << endl;
    cout << soluciones.second;

return 0;
}*/
