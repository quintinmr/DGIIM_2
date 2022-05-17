#include <stdio.h>
#include <stdlib.h>

#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thread_num() 0
#endif

int main(int argc, char **argv)
{
    int i, n=200, chunk, a[n], suma=0;
    
    if(argc < 3)
    {
        fprintf(stderr,"\nFalta iteraciones o chunk\n");
        exit(-1);
    }

    n = atoi(argv[1]);
    if (n>200)
        n=200;

    chunk = atoi(argv[2]); 

    for (i=0; i<n; i++)
        a[i] = i; 
        
    omp_sched_t kind; int chunk_v;
 
    #pragma omp parallel for firstprivate(suma) \
                lastprivate(suma) schedule(dynamic,chunk)
    for (i=0; i<n; i++)
    {
        suma = suma + a[i];
        printf(" thread %d suma a[%d]=%d suma=%d \n",
               omp_get_thread_num(),i,a[i],suma);
               
        //Modificación de variables
        if (i == 2){
           omp_set_dynamic(0);
           omp_set_num_threads(6);
           omp_set_schedule(1,2);
        }
  
        if (i == 0 || i == 2)  // lo ejecute una sola hebra
        {
           if (i == 0){
           	printf("////////////////////////////////////\n");
           	printf("ANTES DE LA MODIFICACIÓN dentro del 'parallel for'\n");
           	printf("////////////////////////////////////\n");
           }
           else{
           	printf("////////////////////////////////////\n");
           	printf("DESPUÉS DE LA MODIFICACIÓN dentro del 'parallel for'\n");
           	printf("////////////////////////////////////\n");
           }
           	
           omp_get_schedule(&kind, &chunk_v);
           printf("dyn-var = %d\n", omp_get_dynamic());
           printf("nthreads-var = %d\n", omp_get_max_threads());
           printf("thread-limit-var = %d\n", omp_get_thread_limit());
           printf("run-sched-var = %d,  chunk = %d\n", kind, chunk_v);
           printf("////////////////////////////////////\n");
           
        }
    }

    printf("////////////////////////////////////\n");
    printf("ANTES DE LA MODIFICACIÓN fuera de 'parallel for'\n"); 
    printf("////////////////////////////////////\n");
    printf("suma=%d\n",suma); 
    printf("dyn-var = %d\n", omp_get_dynamic());
    printf("nthreads-var = %d\n", omp_get_max_threads());
    printf("thread-limit-var = %d\n", omp_get_thread_limit());
    printf("run-sched-var = %d, chunk = %d\n", kind, chunk);
    printf("////////////////////////////////////\n");
    
    //Modificación de variables
    omp_set_dynamic(0);
    omp_set_num_threads(6);
    omp_set_schedule(1,2);
    
    printf("////////////////////////////////////\n");
    printf("DESPUÉS DE LA MODIFICACIÓN fuera de 'parallel for'\n"); 
    printf("////////////////////////////////////\n");
    printf("suma=%d\n",suma); 
    printf("dyn-var = %d\n", omp_get_dynamic());
    printf("nthreads-var = %d\n", omp_get_max_threads());
    printf("thread-limit-var = %d\n", omp_get_thread_limit());
    printf("run-sched-var = %d, chunk = %d\n", kind, chunk);
    printf("////////////////////////////////////\n");
    
    
}

