#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    bool buracoDeminhoca;
    int x,y;
    int i,j;
    int conteudo;
    int v;

} Vertice;

Vertice** aloca_matriz(int m, int n);
int strtoint(char *str, int tam);
Vertice **Liberar_matriz_real (int m, Vertice **v);
#endif // MAZE_H_INCLUDED
