#include "inout.h"
#include "maze.h"
#include <math.h>
#include <string.h>

Vertice** LeEntrada(Parametro *p, int *ini, int *fim)
{
    int nlinhas,ncolunas,t,x,y,i,j,tam,cont;
    char temp[10];
    int aux;
    Vertice **maze;
    scanf("%d %d %d",&nlinhas,&ncolunas,&t);
    p->n = nlinhas;p->m =ncolunas;p->t = t;
    maze = aloca_matriz(nlinhas,ncolunas);
    cont = nlinhas*ncolunas-1;
    for( i=nlinhas-1; i >=0; i-- )
    {
        for( j=0; j< ncolunas; j++ )
        {
            scanf("%s",temp);
            if( temp[0] == 'V') *ini = cont;
            else if( temp[0] == 'E') *fim= cont;
            if( temp[0] > 47 && temp[0] < 58 )/* verifica buraco de minhoca*/
            {
                tam = strlen(temp);
                y = temp[tam-1] - '0';
                if( tam < 3)
                {
                    x = temp[0] - '0';
                }
                else
                {
                    x = strtoint(temp,tam);
                }
                maze[i][j].conteudo = '.';
                maze[i][j].buracoDeminhoca = true;
                maze[i][j].x = x;
                maze[i][j].y = y;
                maze[i][j].v = cont;
                maze[i][j].i = i;
                maze[i][j].j = j;
            }
            else/*qualquer outro caso*/
            {
                aux =(int)temp[0];
                maze[i][j].conteudo = aux;
                maze[i][j].v = cont;
                maze[i][j].i = i;
                maze[i][j].j = j;
            }
            cont--;
        }
    }
    return maze;
}
