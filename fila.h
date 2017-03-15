#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct registro
{
    int v;
    struct registro *prox;
}celula;

typedef struct
{
    celula *ini,*fim;
}Fila;

bool filaVazia(Fila* f);
void InsereFila(Fila *f, int v);
int RetiraFila(Fila* f);
Fila* criaFila();
#endif // FILA_H_INCLUDED

