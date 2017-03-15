#ifndef INOUT_H_INCLUDED
#define INOUT_H_INCLUDED
#include "maze.h"
typedef struct
{
    int n,m,t;
}Parametro;

Vertice** LeEntrada(Parametro *p, int *ini, int *fim);
#endif // INOUT_H_INCLUDED
