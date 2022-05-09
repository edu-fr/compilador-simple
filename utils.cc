#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#include "stdio.h"

extern "C" DLLEXPORT void imprimei(long i)
{
    printf("%ld\n", i);
}