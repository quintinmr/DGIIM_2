#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main (int argc, char * argv[]){

   int numero;
   pid_t pid;
   
   if (argc != 2){
      printf ("ERROR EN EL NÚMERO DE ARGUMENTOS\n");
      perror ("ARGUMENTOS MAL");
      exit(-1);
   }
   
   numero = atoi(argv[1]);
   
    if ((pid = fork()) < 0) printf ("ERROR EN EL FORK()");
   else{
   	if (pid == 0){
   	   if (numero % 2 == 0) printf ("El número %d es par\n", numero);
   	   else
   	       printf ("El número %d es impar\n", numero);
   	}
   
   	else{
   	    sleep(1);
   	    if (numero % 4 == 0) printf ("El número %d es divisile por 4\n", numero);
   	    else printf ("El número %d no es divisile por 4\n", numero);
   	}
   }

   
  /* if ((pid = fork()) < 0) printf ("ERROR EN EL FORK()");
   else
   	if (pid == 0){
   	   if (numero % 2 == 0) printf ("El número %d es par\n", numero);
   	   else
   	       printf ("El número %d es impar\n", numero);
   	}
   
   else{
   	sleep(1);
   	if (numero % 4 == 0) printf ("El número %d es divisile por 4\n", numero);
   	else printf ("El número %d no es divisile por 4\n", numero);
   }
   */
   
   return 0;
   }   
