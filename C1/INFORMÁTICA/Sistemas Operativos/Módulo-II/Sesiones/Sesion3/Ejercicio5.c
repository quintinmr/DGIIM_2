#include<sys/types.h>							
#include<unistd.h>		
#include<errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int main (int argc, char * argv[]){

   int hijos[5];
   int espera;
   pid_t pid;
   int a = getpid();
   int n_hijos = 5;
   
   for (int i = 0; i < 5 && pid!=0; i++){
   	if ((pid = fork()) < 0){
   	   perror("ERROR EN EL FORK\n");
   	   exit(-1);
   	}
   	
   	hijos[i] = pid; // Almacenamos en el vector hijos los PID de cada uno de los hijos
   	if (hijos[i] == 0) printf("Hola, soy el hijo %d\n", getpid());
   }
   
   // Se esperan primero a los impares 
   
   for (int h = 0; h < 5 && a == getpid(); h+=2){
   	
   	int wstats1;
   	espera = waitpid(hijos[h], &wstats1, 0);
   	
   	if (espera < 0){
  	      perror("ERROR EN EL WAIT\n");
  	      exit(-1);
  	   }
  	   
  	else{ 
  	      n_hijos--;
  	      printf("Acaba de finalizar mi hijo %d con PID %d\n", h, espera);
  	      printf("Solo me quedan %d hijos vivos\n", n_hijos);
  	}
   }
   

   // Ahora se espera a los pares 
   
   for (int k = 1; k < 5 && a == getpid(); k +=2){
   	
   	int wstats2;
   	espera = waitpid(hijos[k], &wstats2, 0);
   	
   	if (espera < 0){
  	      perror("ERROR EN EL WAIT\n");
  	      exit(-1);
  	   }
  	   
  	else{ 
  	      n_hijos--;
  	      printf("Acaba de finalizar mi hijo %d con PID %d\n",k, espera);
  	      printf("Solo me quedan %d hijos vivos\n", n_hijos);
  	}
  }
  
  	
  return 0;

}
