#include <iostream>
#include <cstdlib>
#include <list>
#include <queue> 
#include <fstream>

using namespace std;
int tempo=0;
int aux;

typedef struct vertice{
    int grau;
    int pai;
    int dist;
    int tempo;
    char cor;
    list<int> adj;
}vertice;

typedef struct grafo{
    int numvert; // numero de vertices
    int arestas; // nunmero de arestas
    vertice *v;  // estrutura de 1 vertice;
}grafo;

bool criaGrafo(grafo &g); // cria o grafo
bool buscaP(grafo &g, int u, int num); //passa o grafo, o vertice inicial e o numero a ser procurado


int main()
{
    grafo g;
    int num;
    bool test1, test2;
    printf("digite o numero a ser procurado:\n");
    scanf("%d", &num);
    
    test1 = criaGrafo(g);
    if(test1) printf("grafo criado\n");
    else printf("grafo nao criado\n");
    
    test2 = buscaP(g, 0, num);
    if(test2) printf("numero encontrado\n");
    else printf("numero nao encontrado\n");
    

    return 0;
}

bool criaGrafo(grafo &g){
    g.numvert=0; g.arestas=0; g.v=NULL;
    ifstream arq; arq.open("arquivo.txt"); if(arq.fail()) return false;
    arq >> g.numvert; //passa do arquivo para a variavel g.numvert o numero de vertices
    g.v = new vertice[g.numvert]; //alocação dinamica de memoria para os vertices
    
    for(int i=0; i<g.numvert;i++){
        arq >> g.v[i].grau;// passa o grau de cada vertices
        g.v[i].pai = -1;
        g.v[i].tempo = 9999;
        g.v[i].dist = 0;
        g.v[i].cor = 'b';
        for(int k=0; k<g.v[i].grau;k++){
            arq >> aux; //passa os vizinhos do arquivo pra aux
            g.v[i].adj.push_back(aux); //coloca os vizinhos na lista
        }
    }
    return true;
}

bool buscaP(grafo &g, int u, int num){
    list<int>::iterator it;
    g.v[u].cor = 'c';
    g.v[u].tempo = ++tempo;
    for(it=g.v[u].adj.begin(); it!=g.v[u].adj.end(); ++it){
        aux = *it;
        if(aux==num){
            return true;
        }
        if(g.v[u].cor=='b'){
            g.v[u].cor = 'c';
            g.v[u].pai = u;
            buscaP(g, aux, num);
        }
    }
    g.v[u].cor = 'p';
    return false;
}
