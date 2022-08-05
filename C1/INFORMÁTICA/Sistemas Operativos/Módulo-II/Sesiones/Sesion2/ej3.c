/*
ejercicio3.c
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include <string.h>

#define S_ISREG2(mode) ((mode & S_IFMT) == S_IFREG)

int main (int argc, char * argv[]){

  int fdin;
  struct stat atributos;

  // Le pasamos al programa el nombre del fichero del cual queremos saber si es regular o no
  
  if (argc != 2){
  	
     printf ("ERROR AL ABRIR EL ARCHIVO %d", errno);
     perror ("ERROR AL ABRIR EL ARCHIVO");
     exit(-1);
  }
  else{
  	if ((fdin = open (argv[1], O_RDONLY)) < 0){
  	   printf ("ERROR AL ABRIR EL ARCHIVO %d", errno);
     	   perror ("ERROR AL ABRIR EL ARCHIVO");
           exit(-1);
        }
        
        else{
        
            if ((lstat(argv[1], &atributos)) < 0){
             printf ("ERROR EN EL ALMACENAMIENTO DE LOS METADATOS\n");
             exit(-1);
             }
            
            if ((S_ISREG2(atributos.st_mode))) printf ("Es regular\n");
            else printf ("No es regular\n");
        }
  }
  
  
  close(fdin);
  
  return 0;
            
            
}
