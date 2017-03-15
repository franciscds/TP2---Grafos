#ifndef VINIZINANDANTE_H_INCLUDED
#define VINIZINANDANTE_H_INCLUDED
#include "fila.h"
#include "maze.h"
#include "grafo.h"
#include <stdbool.h>

typedef struct v
{
    int nChaves,t;
    int ini,fim;

}vini;

typedef struct
{
    int tam,*caminho;

}Caminho;

typedef struct
{
    int posicaoPorta,tipoPorta;
}TipoPorta;

typedef struct
{
    int posicaoChave,tipoChave;
}TipoChave;
int vinizinAndador(Grafo* gr,Vertice** maze, int n, int m, vini v);

Caminho encontraMenorCaminho(Grafo* gr,Vertice **maze, int nVertices, vini v);

int* leCaminho(int vAtual, int *vPai,int v );

int verificaCaminho(Grafo* gr, Vertice **maze, vini vinizin,Caminho path);

#endif // VINIZINANDANTE_H_INCLUDED
