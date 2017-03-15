
#include "fila.h"

Fila* criaFila()
{
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

void InsereFila(Fila *f, int v)
{
    celula* novo = (celula*)malloc(sizeof(celula));
    novo->v = v;
    novo->prox = NULL;
    if(f->fim != NULL)
    {
        f->fim->prox = novo;
        f->fim = f->fim->prox;
    }
    else
    {
        f->ini = novo;
        f->fim = novo;
    }
}
int RetiraFila(Fila* f)
{
    celula* t;
    int v;
    if(filaVazia(f))
    {   
        printf("erro");exit(0);
    }
    t = f->ini;
    v = t->v;
    f->ini = t->prox;
    if( f->ini == NULL)f->fim = NULL;
    free(t);
    return v;
}

bool filaVazia(Fila* f)
{
    return(f->ini==NULL);
}
