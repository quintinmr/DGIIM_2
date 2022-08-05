#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<libgen.h>
#define __USE_XOPEN_EXTENDED 1
#include<ftw.h>


// Constantes globales
int contador = 0;
int tam = 0;


int buscar(const char* path, const struct stat *atributes, int flags, struct FTW* ftw){
 if(flags == FTW_D){
 printf("El directorio %s tiene %ld inodos contiene a los siguientes archivos: \n", path, atributes->st_ino);
 }else{
  if(flags == FTW_F){
  printf("%s\t%ld\n", path, atributes->st_ino);
  }
 }
 
 if((atributes->st_mode & S_IXOTH) == S_IXOTH && (atributes->st_mode & S_IXGRP) == S_IXGRP){
  contador++;
  tam+=atributes->st_size;
 }
 
 return 0;

}

int main(int argc, char *argv[]){
if(nftw(argc >= 2 ? argv[1]:".", buscar, 10, 0) != 0){
 perror("nftw");
}

 printf("Hay %d archivos regulares con permiso x para grupo y otros\n", contador);
 printf("El tamaño total ocupado por dichos archivos es %d bytes\n", tam);
return 0;
}

