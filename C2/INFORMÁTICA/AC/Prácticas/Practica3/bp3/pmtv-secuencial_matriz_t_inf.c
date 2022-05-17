/**
 * 
 Código para multimplicación secuencial matriz cuadrada triangular superior por vector: v2 = m * v1 pmtv-secuencial.c
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

//#define VECTOR_GLOBAL
#define VECTOR_DYNAMIC

#ifdef VECTOR_GLOBAL
#define MAX 16375	
double v1[MAX], v2[MAX], m[MAX][MAX]; 
#endif

/**
 * @file  pmv-secuencial.c  
 * @brief multimplicación secuencial matriz cuadrada triangular superior por vector: v2 = m * v1
 * 
 * @param int n=atoi(argv[1])  número de componentes de los vectores y número de filas y columnas de la matriz
 * @return 0 upon exit success (print tiempo de cálculo de la multiplicación, longitud vectores y resultados (primer y último componente del resultado para longitudes mayores que 9))
 *  
 * **Compilación**
 * @code
	gcc  -O2  pmtv-secuencial.c -o pmtv-secuencial -lrt
    (-lrt: real time library, es posible que no sea necesario usar -lrt)
 * @endcode
* **Generar ensamblador**
 * @code
 * gcc  -O2 -S pmv-secuencial.c -lrt
 * @endcode
 *  **Ejecución**
 * ~~~~~~~~~~~~~~~~~~~~~{.c}
 * pmtv-secuencial 8    (para 8 componentes en los vectores)
 * ~~~~~~~~~~~~~~~~~~~~~
 * 
**/
int main(int argc, char** argv){
    unsigned int N;
    int i,j;

    if (argc < 2){
        printf("Uso: %s tamaño\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    N = atoi(argv[1]);

    #ifdef VECTOR_GLOBAL
    if (N > MAX)  N = MAX;
    #endif
    
    #ifdef VECTOR_DYNAMIC
    double *v1, *v2, **m;
    v1 = (double*)malloc(N*sizeof(double));
    v2 = (double*)malloc(N*sizeof(double));
    m = (double**)malloc(N*sizeof(double*));
    if ((v1 == NULL) || (v2 == NULL) || (m == NULL)) {
        printf("No hay suficiente espacio para v1, v2 y m \n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < N; i++) {
        m[i] = (double*)malloc(N*sizeof(double));
        if (m[i] == NULL) {
            printf("No hay suficiente espacio para m \n");
            exit(EXIT_FAILURE);
        }
    }
    #endif

    // Inicializar vector y matriz
    // La inicialización de los datos la debe de hacer la hebra 0
    // por lo tanto, como en secuencial es esta la que se encarga de ejecutar
    // el código no paralelizamos nada de la inicialización.
    for (i = 0; i < N; i++){
        v1[i] = 0.1*i + N*0.1;
        v2[i] = 0;
        
        for (j = 0; j < N; j++){
          if (i > j)
            m[j][i] = 0;
          else m[j][i] = N*0.1+i*0.1-j*01;
        }
    }

    /**********Calcular v2 = m * v1*********/
    
    // Variables destinadas a oobtener el chunk y el kind
    omp_sched_t kind;
    int chunk;
    
    // Variables para el cálculo del tiempo
    double inic, fin, ncgt;
    
    // Producto
    double product;
    
    
    // REGIÓN PARALELA  (producto de la matriz por el vector)
    #pragma omp parallel
    {
    	#pragma omp single
    	  inic = omp_get_wtime();
    	
    	#pragma omp for firstprivate(product) schedule(runtime)
 
    	  for(i = 0; i < N; i++){
            
            #ifdef DEFAULT_CHUNK
               if (i == 0){
                  omp_get_schedule(&kind, &chunk);
                  printf("kind: %d\n", kind);
                  printf("chunk: %d\n", chunk);
               }
            #endif
            
            product = 0;
            for (j = i; j < N; j++){
		product += m[i][j] * v1[j];
	    }
	    
	    v2[i] = product;
	 }
	 
	 #pragma omp single 
	   fin = omp_get_wtime();
	     
    }
    
    ncgt=fin-inic;

    // Imprimir resultados
    if (N < 10){
        printf("Tiempo: %11.9f\t Tamaño: %u\n", ncgt, N);
        printf("Matriz:\n\t");
        for (i = 0; i < N; i++){
            for (j = 0; j < N; j++)
                printf("%8.6f \t ", m[i][j]);
            printf("\n\t");
        }
        printf("\nVector:\n\t");
        for (i = 0; i < N; i++)
            printf("%8.6f ", v1[i]);
        printf("\n\nVector resultado:\n\t");
        for (i = 0; i < N; i++)
            printf("%8.6f ", v2[i]);
        printf("\n");
    } else {
        printf("Tiempo: %11.9f \t Tamaño: %u \t v2[0]: %8.6f \t v2[N-1]: %8.6f \n",ncgt, N, v2[0], v2[N-1]);
    }
    
    //PASO 7: LIBERACION DE LA MEMORIA DINAMICA EMPLEADA
    #ifdef VAR_DYNAMIC
      free(v1);
      free(v2);
      for(int i=0; i<tam; i++)
        free(m[i]);
      free(m);
    #endif
    return(0);
}
