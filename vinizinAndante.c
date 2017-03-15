#include "vinizinAndante.h"

int vinizinAndador(Grafo* gr,Vertice** maze, int n,int m, vini vinizin)
{
    int pos,melhorCaminho;
    Caminho path = encontraMenorCaminho(gr,maze,gr->v,vinizin);
    for(;;)/*Loop para verificar saida ate encontrar ou n caminho valido*/
    {
        if( path.tam == 0)/*sem caminho possivel*/
        {
            free(path.caminho);
            return pos=-1;
        }
        pos = verificaCaminho(gr,maze,vinizin,path);
        if( pos == -1)
        {
            melhorCaminho = path.tam;
            break;
        }
        else if( path.caminho[pos] == vinizin.ini+1 )/*deu ruim*/
        {
            melhorCaminho=-1;
            break;
        }
        else
        {
            gr = criaListaAdjacencia(maze,n,m);/*reseta grafo*/
            gr->lista[path.caminho[pos]].flag = false;
            path = encontraMenorCaminho(gr,maze,gr->v,vinizin);
        }
    }
    free(path.caminho);
    return melhorCaminho;

}

Caminho encontraMenorCaminho(Grafo* gr,Vertice **maze, int nVertices, vini vinizin)
{
    bool visitado[nVertices];
    int vPai[nVertices],v,vertice,dist[nVertices],x,y,ini;
    no* adj;
    ini= vinizin.ini;
    Caminho path;
    for( v=0; v< nVertices; v++)/*inicializa vetores auxiliares*/
    {
        visitado[v] = false;
        vPai[v] = -1;
        dist[v] = 0;
    }
    Fila *f = criaFila();/*Cria Fila de prioridades*/
    visitado[ini] = true;
    dist[vinizin.fim] = 0;
    InsereFila(f,ini);
    while( !filaVazia(f) && dist[vinizin.fim]== 0)
    {
        vertice = RetiraFila(f);
        for( adj = gr->lista[vertice].head; adj != NULL; adj = adj->prox )
        {
            if(visitado[adj->v] == false && gr->lista[vertice].flag )/*verifica se ja foi visitado*/
            {
                if( maze[adj->x][adj->y].buracoDeminhoca == true)/*verifica buraco de minhoca*/
                {
                    x = maze[adj->x][adj->y].x;/*coordenadas vertice destino*/
                    y = maze[adj->x][adj->y].y;
                    visitado[maze[x][y].v] = true;
                    vPai[maze[x][y].v] = vertice;
                    dist[maze[x][y].v] = dist[vertice]+1;
                    maze[adj->x][adj->y].buracoDeminhoca = false;
                    maze[adj->x][adj->y].conteudo = '.'; /*faz celula onde havia buraco virar caminho livre*/
                    InsereFila(f,maze[x][y].v);/*insere vertice apontado pelo buraco*/
                }
                else/*Caso n seja buraco de minhoca*/
                {
                    visitado[adj->v] = true;
                    vPai[adj->v] = vertice;
                    dist[adj->v] = dist[vertice]+1;
                    InsereFila(f,adj->v);
                }
            }
        }
    }
    if(!filaVazia(f)) vertice = RetiraFila(f);
    path.tam = dist[vinizin.fim];
    int* caminho = leCaminho(vinizin.fim,vPai,dist[vinizin.fim]);/*recebe vetor de caminhos*/
    path.caminho = caminho;
    free(f);
    f=NULL;
    return path;
}

int* leCaminho(int vAtual,int* vPai,int v)
{
    int *caminho,cont = 0;
    caminho = (int*)malloc(v*sizeof(int));
    while(vPai[vAtual] != -1)
    {
        caminho[cont] = vPai[vAtual];
        vAtual = vPai[vAtual];
        cont++;
    }
    return caminho;
}
int verificaCaminho(Grafo* gr, Vertice **maze, vini vinizin,Caminho path)
{
    int i=0,j,pos=-1;
    bool flag= false;
    int nPortas=0,nChaves=0;
    TipoPorta porta[path.tam];
    TipoChave chave[path.tam];
    no *adj;/*estrutura auxiliar*/
    for( i=0; i < path.tam; i++)/*pesquisa porta e chaves no caminho*/
    {
        porta[i].posicaoPorta = -1;
        chave[i].posicaoChave = -1;
        chave[i].tipoChave = -1;
        porta[i].tipoPorta = -1;
        adj = gr->lista[path.caminho[i]].info;
        if( maze[adj->x][adj->y].conteudo > 64 && maze[adj->x][adj->y].conteudo < 91 &&  maze[adj->x][adj->y].conteudo != 'V')/*Verifica se e porta*/
        {
            porta[nPortas].posicaoPorta = i;
            porta[nPortas].tipoPorta = maze[adj->x][adj->y].conteudo;
            nPortas++;
        }
        else if( maze[adj->x][adj->y].conteudo > 96 && maze[adj->x][adj->y].conteudo < 123 && nChaves < vinizin.t)
        {
            chave[nChaves].posicaoChave = i;
            chave[nChaves].tipoChave = maze[adj->x][adj->y].conteudo;
            nChaves++;
        }
    }
    if( nPortas !=0 && nChaves == 0)/*verifica se existe porta sem chave no caminho*/
    {
        return pos = path.caminho[nPortas];
    }
    if( nPortas == 0)/*caso o numero de portas seja zero encerra funcao*/
    {
        pos = -1;
        return pos;
    }

    for( j =nPortas-1; j >=0; j--)/*verifica Portas*/
    {
        for( i = 0; i<= nChaves; i++)
        {
            if( porta[j].tipoPorta == (chave[i].tipoChave -32) )
            {
                if( chave[i].posicaoChave > porta[j].posicaoPorta)/*verifica se a chave e lida antes da porta*/
                    flag = true;
            }
        }
        if(!flag)/*caso o caminho seja invalido*/
        {
            pos= porta[j].posicaoPorta;
            break;
        }
    }
    return pos;
}
