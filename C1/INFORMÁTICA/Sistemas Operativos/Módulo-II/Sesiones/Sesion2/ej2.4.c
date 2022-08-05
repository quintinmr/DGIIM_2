/*
ejercicio2.4.c
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

#define S_IRWXGRPOTH 011
#define new_rule(mode) (((mode & ~S_IFMT) & 011) == S_IRWXGRPOTH)

void search_dir (DIR *dir, char rutilla[], int *regulares, int *tam){
  
  struct stat atributos;
  struct dirent *d;
  DIR *directorio;
  char cad[500];
  
  while ((d = readdir(dir)) != NULL){  //Mientras no se llegue al final del directorio
  
  	// Hacemos caso omiso de los directorios actual y superior
  	if (strcmp(d->d_name, ".") != 0 && strcmp(d->d_name, "..") != 0){ // La función strcmp compara dos strings y devuelve 0 si las las cadenas son iguales 
  	   sprintf (cad, "%s/%s", rutilla, d->d_name);
  	   
  	   if (stat(cad, &atributos) < 0){
  	   	printf("ERROR AL INTENTAR ACCEDER A LOS ATRIBUTOS DE ARCHIVO\n");
  	   	perror("ERROR en lstat\n");
  	   	exit(-1);
  	   }
  	   
  	   // Comprobamos si el archivo es un directorio
  	   if (S_ISDIR(atributos.st_mode)){
  	   
  	  	if ((directorio = opendir(cad)) == NULL)
  	  	   printf ("ERROR AL ABRIR EL DIRECTORIO %s\n", cad);
  	  	else
  	  	  search_dir (directorio, cad, regulares, tam);
  	   }
  	  else{
  	      
  	      if (S_ISREG(atributos.st_mode)){ // Comprobamos que el archivo es regular
  	      	 if (new_rule(atributos.st_mode)){ // Comprobamos que tenga permisos de ejecución para el grupo y otro   
  	      	 printf ("%s %ld \n", cad, atributos.st_ino);
  	      	 (*regulares)++;
  	      	 (*tam) += (int) atributos.st_size;
  	      	 }
  	      }
  	      
  	}
  	
  	closedir(dir);
 }
  		
 }
 }

int main (int argc, char * argv[]){

   DIR *dir;
   int num_regulares, tam_total;
   char ruta[500];
   
   //Comprobamos los argumentos que pasamos
   if (argc != 2)
       strcpy(ruta, ".");
   else
       strcpy(ruta,argv[1]);
        
   // Abrimos el directorio
   if ((dir = opendir(ruta)) == NULL){
      printf ("ERROR AL ABRIR EL DIRECTORIO\n");
      perror ("ERROR AL ABRIR EL DIRECTORIO\n");
      exit(-1);
   }
   
   printf ("Los inodos son:\n");
   search_dir(dir, ruta, &num_regulares, &tam_total);
   printf ("El número de archivos regulares con permiso de ejecución para grupo y otros es: %d\n", num_regulares);
   printf ("El total de bytes ocupados por dichos archivos es: %d\n", tam_total);
   
   return 0;
  
}
