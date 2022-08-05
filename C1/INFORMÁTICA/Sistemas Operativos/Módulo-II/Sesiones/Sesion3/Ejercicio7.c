#include<sys/types.h>	
#include<sys/wait.h>	
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main (int argc, char * argv[]){

   pid_t pid;
   char *arguments[argc];
   int parametros_programa = 0;
   bool es_back = false;
   
   if (argc < 2){
      perror ("ERROR EN ARGUMENTOS\n");
      exit(-1);
   }
   
   for (int i = 1; i < argc; i++){
       
       if (strcmp(argv[i], "bg") == 0){
          es_back = true;
       }
       
       else{
            arguments[parametros_programa] = (char *) malloc(strlen(argv[i]+1));
            strcpy(arguments[parametros_programa], argv[i]);
            parametros_programa++;
       }
       
   }
   
   int tamanio = parametros_programa;
   arguments[parametros_programa] = NULL;
   
   //Si el programa se tiene que ejecutar en background creamos el hijo a continuación
   if (es_back){
   
     if ((pid = fork()) < 0){
        perror ("ERROR EN EL FORK\n");
        exit(-1);
     }
     else if (pid == 0){  //Para que el programa se ejecute en background hacemos que los ejecute el hijo
     	    if ((execvp(argv[1], arguments)) < 0){
     	    	perror("ERROR EN EL EXEC\n");
     	    	exit(-1);
     	    }
    
      }
      
   }
   
   else{  //Si se tiene que ejecutar en foreground
   
   	if ((execvp(argv[1], arguments)) < 0){
   	   perror("ERROR EN EL EXEC\n");
     	   exit(-1);
     	}
     	
   }
   
   return (EXIT_SUCCESS);
     	 
}
