/**
   @file Ejercicio_1_
*/

   
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <chrono>
using namespace std::chrono;

/**
  @brief Función que, dado un vector con n elementos, busca si existe un ínidce i tal que v[i] = i y devuelve dicha posición.
  @param v[] vector de enteros
  @param n número de elementos
  
*/

int buscaIgualIndice (int v[], int n)
{
    int i = 0;
    bool encontrado = false;
    
    for (i; i < n && encontrado; i++)
    
    	if (v[i] == i) encontrado = true; 
    
    return i;
        
}
