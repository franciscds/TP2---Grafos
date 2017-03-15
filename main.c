#include "maze.h"
#include "inout.h"
#include "grafo.h"
#include "vinizinAndante.h"
int main()
{
    int menorCaminho;
    Parametro p;
    vini v;
    Vertice **maze;
    Grafo *gr;

    maze = LeEntrada(&p,&v.ini,&v.fim); /*Le entrada e armazena numa matriz*/
    gr = criaListaAdjacencia(maze,p.n,p.m); /*Cria grafo*/
    v.t = p.t;
    menorCaminho = vinizinAndador(gr,maze,p.n,p.m,v); /*encontra Menor Caminho*/
    printf("%d\n",menorCaminho);
    Liberar_matriz_real(p.n,maze);
    maze = NULL;
    freeGrafo(gr);
    gr = NULL;
    return 0;

}
