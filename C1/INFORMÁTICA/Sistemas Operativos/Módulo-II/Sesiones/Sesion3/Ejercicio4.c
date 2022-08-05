#include<sys/types.h>							
#include<unistd.h>		
#include<errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int main (int argc, char * argv[]){

   int childpid[5];
   int espera;
   int nprocs = 5;
   char buf[500];
   int a = getpid();
  
   //childpid=malloc(nprocs*sizeof(int));
   
   setvbuf(stdout, buf, _IONBF, strlen(buf));
   
  	for (int i = 0; i < nprocs && a == getpid(); i++){
  	   childpid[i] = 0;
  	 
  	   if ((childpid[i] = fork()) < 0){
  	     perror ("CANNOT CREATE CHILD");
  	     exit(-1);
  	   }
  	     
  	  else if ((childpid[i] == 0)){
  	       printf("Soy el hijo PID: %d\n", getpid());
  	  }
  	    
  	}
  	
  	for (int j = 1; j <= nprocs && a == getpid(); j++){
  	   
  	   espera = wait(0); // Le paso el PID del proceso que quiero esperar; 0 --> el hijo, devuelv el PID del hijo al que espera
  
  	   if (espera == -1){
  	      perror("ERROR EN EL WAIT\n");
  	      exit(-1);
  	   }
  	   
  	   else{
  	   	printf("Acaba de finalizar mi hijo con PID %d\n", espera);
  	   	printf("Solo me quedan %d hijos vivos\n", nprocs - j);
  	   }
  	   
  	}
  	
  return 0;

}
