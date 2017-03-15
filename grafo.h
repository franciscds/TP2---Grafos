#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "maze.h"
#include <stdbool.h>

typedef struct listaNo
{
    int v;
    int x,y;
    struct listaNo* prox;
} no;

typedef struct
{
    no *info;
    bool flag;
    no *head;
} adjList;

typedef struct g
{
    int v;
    adjList *lista;
} Grafo;

Grafo* criaGrafo(int v);
no* criaNo(int i,int j, int v);
Grafo* criaListaAdjacencia( Vertice **maze, int n, int m);
void printGraph(Grafo* gr);
void addAresta( Grafo* gr,int v1,int i,int j,int v);
void addArestaHead( Grafo* gr,int v1,int i,int j,int v);
void freeGrafo(Grafo *gr);


#endif // GRAFO_H_INCLUDED
