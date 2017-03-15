#include "grafo.h"

Grafo* criaListaAdjacencia( Vertice **maze, int n, int m)
{
    int i=0,j=0;
    Grafo* gr = criaGrafo(n*m);

    for( i=0; i < n ; i++)
    {
        for( j=0; j < m; j++)
        {
            addArestaHead(gr,maze[i][j].v,maze[i][j].i,maze[i][j].j,maze[i][j].v);/*adiciona Dados do Vertice*/
            if( maze[i][j].conteudo != 35)
            {
                if(j>0)
                {
                    if(maze[i][j-1].conteudo != 35 )/* Verifica se vizinho da esquerda e adjacente*/
                    {
                        addAresta(gr,maze[i][j].v,maze[i][j-1].i,maze[i][j-1].j,maze[i][j-1].v);
                    }
                }
                if(j<m-1)
                {
                    if(maze[i][j+1].conteudo != 35 )/* Verifica se vizinho da direita e adjacente*/
                    {
                        addAresta(gr,maze[i][j].v,maze[i][j+1].i,maze[i][j+1].j,maze[i][j+1].v);
                    }
                }
                if(i>0)
                {
                    if( maze[i-1][j].conteudo != 35 )/*Verifica se vizinho de baixo e adjacente*/
                    {
                        addAresta(gr,maze[i][j].v,maze[i-1][j].i,maze[i-1][j].j,maze[i-1][j].v);
                    }
                }
                if(i<n-1)
                {
                    if(maze[i+1][j].conteudo != 35 )/*Verifica se vizinho de cima e adjacente*/
                    {
                        addAresta(gr,maze[i][j].v,maze[i+1][j].i,maze[i+1][j].j,maze[i+1][j].v);
                    }
                }
            }
        }
    }
    return gr;
}
Grafo* criaGrafo(int v)
{
    int i=0;
    Grafo* gr = (Grafo*)malloc(sizeof(Grafo));
    gr->v = v;
    gr->lista = (adjList*)malloc(v*sizeof(adjList));
    for(i = 0; i < v; i++)
    {
        gr->lista[i].head = NULL;
        gr->lista[i].flag = true;
    }
    return gr;
}
void addArestaHead( Grafo* gr,int v1,int i,int j,int v)
{
    no* novo = criaNo(i,j,v);
    novo->prox = gr->lista[v1].head;
    gr->lista[v1].info = novo;
}
void addAresta( Grafo* gr,int v1,int i,int j,int v)
{
    no* novo = criaNo(i,j,v);
    novo->prox = gr->lista[v1].head;
    gr->lista[v1].head = novo;
}

no* criaNo(int i,int j, int v)
{
    no* novo_no = (no*)malloc(sizeof(no));
    novo_no->v = v;
    novo_no->x = i;
    novo_no->y = j;

    return novo_no;
}

void freeGrafo(Grafo *gr)
{
    if(gr)
    {
        if(gr->lista)
        {
            int v;
            /*liberas nos*/
            for (v = 0; v < gr->v; v++)
            {
                no *adjList = gr->lista[v].head;
                no *adjList2= gr->lista[v].info;
                while (adjList)
                {
                    no* tmp = adjList;
                    adjList = adjList->prox;
                    free(tmp);
                }
                free(adjList2);
            }
            /*libera ponteiro pra lista*/
            free(gr->lista);
        }
        /*libera grafo*/
        free(gr);
    }
}
