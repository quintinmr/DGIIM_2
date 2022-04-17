/**
   @file Ordenación por montones
*/

   
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <chrono>
using namespace std::chrono;






/* ************************************************************ */ 
/*  Método de ordenación por montones  */

/**
   @brief Ordena un vector por el método de montones.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: número de elementos. num_elem > 0.

   Cambia el orden de los elementos de T de forma que los dispone
   en sentido creciente de menor a mayor.
   Aplica el algoritmo de ordenación por montones.
*/
inline static 
void heapsort(int T[], int num_elem);



/**
   @brief Reajusta parte de un vector para que sea un montón.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: número de elementos. num_elem > 0.
   @param k: índice del elemento que se toma com raíz
   
   Reajusta los elementos entre las posiciones k y num_elem - 1 
   de T para que cumpla la propiedad de un montón (APO), 
   considerando al elemento en la posición k como la raíz.
*/
static void reajustar(int T[], int num_elem, int k);




/**
   Implementación de las funciones
**/


static void heapsort(int T[], int num_elem)
{
  int i;
  for (i = num_elem/2; i >= 0; i--)
    reajustar(T, num_elem, i);
  for (i = num_elem - 1; i >= 1; i--)
    {
      int aux = T[0];
      T[0] = T[i];
      T[i] = aux;
      reajustar(T, i, 0);
    }
}
  

static void reajustar(int T[], int num_elem, int k)
{
  int j;
  int v;
  v = T[k];
  bool esAPO = false;
  while ((k < num_elem/2) && !esAPO)
    {
      j = k + k + 1;
      if ((j < (num_elem - 1)) && (T[j] < T[j+1]))
	j++;
      if (v >= T[j])
	esAPO = true;
      T[k] = T[j];
      k = j;
    }
  T[k] = v;
}
  
      
int main(int argc, char* argv[])
{
  if (argc != 2){
    cout << "Syntax error: ./heapsort <Num of elements>" << endl;
  }

  int n = stoi(argv[1]);
  double time_total = 0;

  int * T = new int[n];
  assert(T);

  srandom(time(0));

  high_resolution_clock::time_point tantes, tdepues;
  duration<double> transcurrido;

  for (int j = 0; j < 15; j++){
    for (int i = 0; i < n; i++)
      {
        T[i] = random();
      };

    // escribe_vector(T, n);

    tantes = high_resolution_clock::now();

    heapsort(T, n);

    tdepues = high_resolution_clock::now();
    
    transcurrido = duration_cast<duration<double>>(tdepues - tantes);

    time_total += transcurrido.count();

    // escribe_vector(T, n);

  }
  time_total /= 15;

  cout << n << " " << time_total << endl;

  delete [] T;

  return 0;
};

