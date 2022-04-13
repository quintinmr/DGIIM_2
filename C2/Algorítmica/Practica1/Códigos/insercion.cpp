/**

   @file Ordenacin por insercin

*/




   

#include <iostream>

using namespace std;

#include <ctime>

#include <cstdlib>

#include <climits>

#include <cassert>

#include <chrono>

using namespace std::chrono;



















/* ******************************************************** */ 

/*  Mtodo de ordenacin por insercin  */




/**

   @brief Ordena un vector por el mtodo de insercin.



   @param T: vector de elementos. Debe tener num_elem elementos.

             Es MODIFICADO.

   @param num_elem: nmero de elementos. num_elem > 0.



   Cambia el orden de los elementos de T de forma que los dispone

   en sentido creciente de menor a mayor.

   Aplica el algoritmo de insercin.

*/

inline static 

void insercion(int T[], int num_elem);










/**

   @brief Ordena parte de un vector por el mtodo de insercin.



   @param T: vector de elementos. Tiene un nmero de elementos 

                   mayor o igual a final. Es MODIFICADO.

   @param inicial: Posicin que marca el incio de la parte del

                   vector a ordenar.

   @param final: Posicin detrs de la ltima de la parte del

                   vector a ordenar. 

     inicial < final.



   Cambia el orden de los elementos de T entre las posiciones

   inicial y final - 1de forma que los dispone en sentido creciente

   de menor a mayor.

   Aplica el algoritmo de insercin.

*/

static void insercion_lims(int T[], int inicial, int final);










/**

   Implementacin de las funciones

**/




inline static void insercion(int T[], int num_elem)

{

  insercion_lims(T, 0, num_elem);

}







static void insercion_lims(int T[], int inicial, int final)

{

  int i, j;

  int aux;

  for (i = inicial + 1; i < final; i++) {

    j = i;

    while ((T[j] < T[j-1]) && (j > 0)) {

      aux = T[j];

      T[j] = T[j-1];

      T[j-1] = aux;

      j--;

    };

  };

}










int main(int argc, char* argv[])

{

  if(argc != 2){

    cout << "Syntax error: ./insercion <Num of elements>" << endl;

    return -1;

  }




  int n = stoi(argv[1]);

  double time_total = 0;

  




  high_resolution_clock::time_point tantes, tdespues;

  duration<double> transcurrido;




  int * T = new int[n];

  assert(T);




    for (int j = 0; j < n; j++)

      {

        T[j] = j;

      };




      tantes = high_resolution_clock::now();




      insercion(T, n);




      tdespues = high_resolution_clock::now();




      transcurrido = duration_cast<duration<double>>(tdespues-tantes);




      time_total = transcurrido.count();




  cout << n << " " << time_total << endl;




  delete [] T;




  return 0;

};



