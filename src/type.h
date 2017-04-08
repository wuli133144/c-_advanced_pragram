
#ifndef __TYPE__H
#define __TYPE__H


typedef  signed char _i8;

typedef  unsigned char _u8;
typedef  signed int _i32;
typedef  unsigned int _u32;

typedef char  _c;
typedef char * _s;


#define _STATIC_PREFIX  static 

//#include <stdarg.h>
#include <stdio.h>

#define _pos()  __info("%s","\n")

#define __info(fmt,...) do{\
     printf("[%s]<%s> [%d] :",__FILE__,__func__,__LINE__);\
     printf(fmt,__VA_ARGS__);\
  }while(0)


#define mkstr(symbol) #symbol

#define _error(exp,escape_lable,fmt,...) do{\
    if(exp){\
             __info("*******error occured*****|%s",mkstr(exp));\
             printf(fmt,__VA_ARGS__);\
             goto escape_lable;\
           }\
}while(0)






#define print(x)  fprintf(stdout," %d ",x)


#endif