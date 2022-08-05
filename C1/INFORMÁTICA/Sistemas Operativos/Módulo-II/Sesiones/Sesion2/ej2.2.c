/*
ejercicio2.2.c
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include <string.h>
#include <dirent.h>

int main (int argc, char * argv[]){

   DIR *dir;
   struct dirent *entrance;
   struct stat atributos;
   char nombre_ruta[500];
  
   int permisos_antiguos, permisos_nuevos;
   
   if (argc != 3){
  	
     printf ("ERROR AL ABRIR EL ARCHIVO %d", errno);
     perror ("ERROR AL ABRIR EL ARCHIVO");
     exit(-1);
  }

   dir             = opendir(argv[1]);
   permisos_nuevos = strtol(argv[2], NULL, 8); // long int strtol(const char * nptr, NULL, int base)
   
   while ((entrance = readdir(dir)) != 0){
   
   	sprintf(nombre_ruta, "%s/%s", argv[1], entrance->d_name); //   <=> nombre_ruta = directorio/
   	                                                          // nombre_archivo
   	lstat(nombre_ruta, &atributos);  
   	permisos_antiguos = atributos.st_mode;
   	
   	if (chmod(nombre_ruta, permisos_nuevos) == 0){
   	   
   	   printf (entrance->d_name, "Antiguos:", permisos_antiguos, " ", "Nuevos:", permisos_nuevos);
   	   
   	}
   	else{
   	    printf (entrance->d_name, ":", errno, permisos_antiguos);
   	}
   	
   }
   
   closedir(dir);
   
   return 0;
}
