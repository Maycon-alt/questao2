#include <iostream>
#include <cstdlib>
#include <fstream>
#include <list>

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
    int grau;
    int arestas;
    vertice *v;
}grafo;

bool criarGrafo(grafo &g);


int main()
{
    grafo g;
    bool ver;
    ver = criarGrafo(g);
    
    if(ver==true){
        printf("criado\n");
    }
    else printf("erro\n");

    return 0;
}
bool criarGrafo(grafo &g){
    g.grau=0; g.arestas=0; g.v=NULL;
    ifstream arq; 
    arq.open("arquivo.txt");
    if(arq.fail()) return false;
    arq >> g.grau;
    g.v = new vertice[g.grau];
    
    for(int i; i<g.grau;i++){
        arq>> g.v[i].grau;
        
        g.v[i].pai = -1;
        g.v[i].tempo = 9999;
        g.v[i].dist = 0;
        g.v[i].cor = 'b'; //branco
        
        for(int k; k<g.v[i].grau;k++){
            arq>>aux;
            g.v[i].adj.push_back(aux);
        }
    }
    return true;
}
