
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <unistd.h>
#include <errno.h>
#include "type.h"



int g_local=6;

_s pstr="a write to buf\n";



#define p_error(m)  do{\
    perror(m);\
     exit(0);\                  
}while(0)




int main(int argc,char **argv){
    
   // assert(argc>2);
   int val=100;
   pid_t pid;

   if(write(STDOUT_FILENO,pstr,strlen(pstr))<=0){
         p_error("write failed");
   }

   printf("before fork");
   //fork
   //create it
   
   if((pid=fork())<0){
      
       p_error("fork failed");

   }else if(pid==0){//child proc
       g_local++;
       val++;
   }else{
        sleep(2);
   }

   printf("pid=%d,g_local=%d val=%d",getpid(),g_local,val);
    return 0;
}