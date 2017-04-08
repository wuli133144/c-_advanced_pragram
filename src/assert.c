


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <unistd.h>
#include <errno.h>
//#include "type.h"



int g_val=100;
int val=100;

#define err_exit(m) do{\
     perror(m);\
     exit(0);\
}while(0)


int doit(int ,char **);

int main(int argc,char **argv){
   return doit(argc,argv);
}

int doit(int argc,char **argv){
   
    pid_t pid;

    pid=vfork();

    switch (pid)
    {
        case 0://child proc
        {
            //doit()
            val++;
            g_local++;
            
        
            break;
        }
        case -1://error proc
        {
             //doit()
             err_exit("vfork error");
            break;
        }

       default://parent proc
             //doit()
             val++;
             g_local++;
        break;
    }
    



}


