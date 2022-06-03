/**
 * 
 * Programa que calcula PI. Código paralelo basado en las construcciones/
 * directivas OpenMP para ejecutar código en coprocesadores.
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <omp.h>
#define MAX 33554432
int inf[MAX][4];
/**
 * @file  pi.c 
 * @brief PI paralelo con integración numérica, área de rectángulos
 * @author Quintín Mesa Romero
 *  
 * Compilación
 * @code
 *  sbatch -pac4 -Aac --wrap "nvc -O2 -openmp -mp=gpu pi.c -o pi"
 * @endcode
 * 
 *  Ejecución
 * ~~~~~~~~~~~~~~~~~
 *   srun -pac4 -Aac pi 10000000 > pi.txt   (1000000 intervalos de integración)
 * ~~~~~~~~~~~~~~~~~
 *
 * Resultados
 * ~~~~~~~~~~~~~~~~~
 * cat pi.txt
 * 
*/
int main(int argc, char **argv)
{
  register double width;
  double sum;
  register int intervals, i; 
  double t1 = 0.0, t2 = 0.0, t3 = 0.0, t4 = 0.0;
  
  double PI = acos(-1.0);
  
    
  //Los procesos calculan PI en paralelo
  if (argc<2) {printf("Falta número de intevalos");exit(-1);}
  intervals=atoi(argv[1]);  
  if (intervals<1) {intervals=1E6; printf("Intervalos=%d",intervals);}
  width = 1.0 / intervals;
  sum = 0;
  
  t1 = omp_get_wtime();
  
  #pragma omp target enter data map(to: width, intervals, sum) 

  t2 = omp_get_wtime();
  
  #pragma omp target teams distribute parallel for reduction(+:sum)
  				       // Hemos de hacer privada la variable suma
  				       // y sumar todas las sumas al final del bucle
  				       // --> ponemos reduction(:sum)
    for (i=0; i<intervals; i++) {
        register double x = (i + 0.5) * width;
        sum += 4.0 / (1.0 + x * x);
    }
    
    t3 = omp_get_wtime();
  
 #pragma omp target exit data map(delete: intervals, width) map(from: sum)
    
    sum *= width;
    t4 = omp_get_wtime();
    
  
  double total = t4-t1;
  double error = fabs(PI-sum);
  
  //Salida de datos
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Iteraciones:\t%d\nPI:\t%26.24f\nTiempo:\t%8.6f\n", intervals,sum,total);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Error cometido: \t%26.30f\n", error);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("TIEMPOS:\n");
  printf("\ttarget enter data : \t%11.9f\n\ttarget teams distribute parallel for: \t%11.9f\n\ttarget exit data: \t%11.9f\n", t2-t1, t3-t2, t4-t3);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
 


  return(0);
}
