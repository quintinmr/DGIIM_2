#include<sys/types.h>							
#include<unistd.h>		
#include<errno.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char * argv[]){

   pid_t childpid;
   int nprocs = 20;
   
   
  /*
   	JERARQUÍA DE PROCESOS 1
   	
  */
  	for (int i = 0; i < nprocs; i++){
  	    if ((childpid = fork()) == -1){
  	       perror("COULD NOT CREATE A CHILD");
  	       exit(-1);
  	    }
  	    
  	    if (childpid){
  	    	printf("PID PROCESO: %d, $PID PADRE: %d \n", getpid(), getppid());
  	    	break;
  	    }
  	}
  	
  return 0;

}
