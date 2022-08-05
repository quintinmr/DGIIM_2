#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

/*
    IMPLEMENTACION DEL CAUCE TERMIAL 

*/

int main(int argc, char *argv[]) 
{

  int fd[2];   // Vector descriptores de archivo
  pid_t PID;
  
  pipe(fd);    // Creamos con la llamada al sistema pipe un cauce sin nombre
  
  // A continuación creamos un proceso hijo (el fork después del pipe)
  
  if ((PID = fork()) < 0) {
     perror("ERROR EN EL FORK\n");
     exit(-1);
  }
  
  if (PID == 0){  //Empieza a ejecutarse el proceso hijo
    
    close(fd[0]); // Cerramos el descriptor del cauce de lectura porque no nos interesa
    
    close(STDOUT_FILENO); //Cerramos la salida estandar porque no queremos que se imprima la salida del hijo en consola
    
    // Duplicamos el descriptor de salida para redireccionar la salida estandar al descriptor de    
    // escritura del cauce.
    
    dup(fd[1]);
    
    execlp("ls", "ls", NULL);
   }
   
   else{  //Se ejecuta el padre (hay que decir que la llamada dup es bloqueante, para así evitar que se
          // ejecute el padre antes que el hijo
       
       close(fd[1]);  // Cerramos el descriptor de escritura del cauce dado que no nos interesa 
                      // escribir, sino leer
       close(STDIN_FILENO);  // Cerramos la entrada estandar porque no vamos a leer del teclado, sino 
                             // del descriptor de lectura del cauce       
       dup(fd[0]);   // Duplicamos el descritor de lectura porque queremos redireccionar la entrada 
                    // estandar al descritor de lectura del cauce
                    
       execlp("wc", "wc", NULL);
       
    }
    
    return 0;
    
}
   
