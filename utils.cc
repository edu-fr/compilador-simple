#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#include "stdio.h"

extern "C" DLLEXPORT void imprimei(long int i)
{
    printf("%ld\n", i); 
}