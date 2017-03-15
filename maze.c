#include "maze.h"

int strtoint(char *str, int tam)
{
    int i,temp=1;
    for( i=0; i < tam-1; i++)
    {
        temp+= ( (int)str[i] - 48)*(pow(10,(tam-i-2)));
    }
    return temp;
}

Vertice** aloca_matriz(int m, int n)
{
    Vertice **v;
    int i;
    /* aloca as linhas da matriz */
    v = (Vertice **) calloc (m, sizeof(Vertice *));
    /* aloca as colunas da matriz */
    for ( i = 0; i < m; i++ )
    {
        v[i] = (Vertice*) calloc (n, sizeof(Vertice));
    }
    return (v);
}

Vertice **Liberar_matriz_real (int n, Vertice **v)
{
    int  i;  /* variavel auxiliar */
    if (v == NULL) return (NULL);
    for (i=0; i < n; i++) free (v[i]); /* libera as linhas da matriz */
    free (v);      /* libera a matriz */
    return v; /* retorna um ponteiro nulo */
}
