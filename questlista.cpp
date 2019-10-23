// -----------------------------------------------------------------
// ---- CODIGOS DOS EXERCICIOS DA LISTA 2 --------------------------
// -----------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <climits>
#include <cfloat>
#include <windows.h>
#include <stack>
#include <list>
using namespace std;


typedef struct vertice {
    int grau;
    list<int> AdjL;

    int pai;
    int tempo;
    int lowtp, fim;
    string cor;
} vertice;

typedef struct digraph {
	int N;// numero de vertices
	int M;// numero de arestas
	vertice* V;
} digraph;


void questao1(int N, int K);
void questao2(int N, int K);
int questao3(digraph& G);
void questao4(digraph& G, digraph& Gt);
void questao5(digraph& G, digraph& Q);
void questao6(digraph& G1, digraph& G2, digraph& Gp);
void questao7(digraph& G);
void questao8_9(digraph& G);




// ---------------------------------------
// Manutenção de grafos
// ---------------------------------------
int digraph_create(digraph& G);
void digraph_delete(digraph& G);
void digraph_print(digraph& G);


// -----------------------------------------------------------------
// ------ MAIN -----------------------------------------------------
// -----------------------------------------------------------------
int main() {
	// Para executar a questao, coloque 1 no vetor abaixo
	// QUESTAO ------- X 1 2 3 4 5 6 7 8 9 10
	int questao[11] = {0,1,1,1,1,1,1,1,1,1,0};



    digraph G;
    if (!digraph_create(G)) {cout<<"Arquivo inexistente"; return -1;};
    digraph_print(G);

    if (questao[1])
    {
        cout<<"\n---------------------------------------------";
        cout<<"\n---------------- QUESTAO 1 ------------------";
        cout<<"\n---------------------------------------------\n";
        questao1(31,2);

        cout<<"\n";
    }
    if (questao[2])
    {
        cout<<"\n---------------------------------------------";
        cout<<"\n---------------- QUESTAO 2 ------------------";
        cout<<"\n---------------------------------------------\n";
        questao2(15,2);

        cout<<"\n";
        questao2(40,3);

        cout<<"\n";
    }
    if (questao[3])
    {
        cout<<"\n---------------------------------------------";
        cout<<"\n---------------- QUESTAO 3 ------------------";
        cout<<"\n---------------------------------------------\n";
        if (questao3(G)) {
            cout<<"Esse digrafo representa SIM um grafo nao-direcionado\n\n";
        } else {
            cout<<"Esse digrafo NAO representa um grafo nao-direcionado\n\n";
        }
    }
    if (questao[4])
    {
        cout<<"\n---------------------------------------------";
        cout<<"\n---------------- QUESTAO 4 ------------------";
        cout<<"\n---------------------------------------------\n";
        digraph Gt;
        questao4(G,Gt);
        digraph_print(Gt);
        digraph_delete(Gt);
    }
    if (questao[5])
    {
        cout<<"\n---------------------------------------------";
        cout<<"\n---------------- QUESTAO 5 ------------------";
        cout<<"\n---------------------------------------------\n";
        digraph Q;
        questao5(G,Q);
        digraph_print(Q);
        digraph_delete(Q);
    }
    if (questao[6])
    {
        cout<<"\n---------------------------------------------";
        cout<<"\n---------------- QUESTAO 6 ------------------";
        cout<<"\n---------------------------------------------\n";
        digraph Gp;
        questao6(G,G,Gp);
        digraph_print(Gp);
        digraph_delete(Gp);
    }
    if (questao[7])
    {
        cout<<"\n---------------------------------------------";
        cout<<"\n---------------- QUESTAO 7 ------------------";
        cout<<"\n---------------------------------------------\n";
        questao7(G);
    }
    if (questao[8] || questao[9])
    {
        cout<<"\n---------------------------------------------";
        cout<<"\n---------------- QUESTAO 8/9 ----------------";
        cout<<"\n---------------------------------------------\n";
        questao8_9(G);
    }
    if (questao[10])
    {
        cout<<"\n---------------------------------------------";
        cout<<"\n---------------- QUESTAO 10 -----------------";
        cout<<"\n---------------------------------------------\n";

        cout<<"\n";
    }

    digraph_delete(G);
    return 0;
}


// -----------------------------------------------------------------
// ---- QUESTOES DA LISTA 2 DE EXERCICIOS --------------------------
// -----------------------------------------------------------------


// ------------------------------------------
// ---- QUESTAO 1 ---------------------------
// ------------------------------------------
typedef struct node {
	int valor;
	struct node* pai;// node pai
	struct node* filhoesq;// filho esquerdo
	struct node* irmaodir;// irmao direito
	struct node* anterior;// anterior (subindo da direita pra esquerda)
} node;

node* tree_create(int N, int K) {
    if (N<=0) return NULL;
    node* raiz = new node;
    raiz->valor = 1;
    raiz->pai = NULL;
    raiz->filhoesq = NULL;
    raiz->irmaodir = NULL;

    node** vet = new node*[N+1];
    vet[1] = raiz;
    for (int i=2; i<=N; i++) {
        node* noh = new node;
        vet[i] = noh;
        noh->valor = i;
        noh->filhoesq = NULL;
        noh->irmaodir = NULL;
        noh->anterior = vet[i-1];
    }
    raiz->anterior = vet[N];
    int pai = 1;
    int nfilhos=0;
    for (int i=2; i<=N; i++) {
        vet[i]->pai = vet[pai];
        if (nfilhos==0)
            vet[pai]->filhoesq = vet[i];
        else vet[i-1]->irmaodir = vet[i];
        nfilhos++;
        if (nfilhos>=K) {
            nfilhos=0; pai++;
        }
    }
    delete[] vet;
    return raiz;
}

void tree_delete(node* raiz) {
    if (raiz==NULL) return;
    tree_delete(raiz->irmaodir);
    raiz->irmaodir = NULL;
    tree_delete(raiz->filhoesq);
    raiz->filhoesq = NULL;
    delete raiz;
}

// Lista os elementos em Pre-Ordem
void pre_ordem(node* raiz) {
    if (raiz==NULL) return;
    cout << raiz->valor << " ";
    node* noh = raiz->filhoesq;
    while (noh!=NULL) {
        pre_ordem(noh);
        noh = noh->irmaodir;
    }
}

// Lista os elementos em Pos-Ordem
void pos_ordem(node* raiz) {
    if (raiz==NULL) return;
    node* noh = raiz->filhoesq;
    while (noh!=NULL) {
        pos_ordem(noh);
        noh = noh->irmaodir;
    }
    cout << raiz->valor << " ";
}

void questao1(int N, int K) {
    node* raiz = tree_create(N,K);

    cout<<"\n\n\n Pre-Ordem:   ";
    pre_ordem(raiz);

    cout<<"\n\n\n Pos-Ordem:   ";
    pos_ordem(raiz);

    tree_delete(raiz);
}


// ------------------------------------------
// ---- QUESTAO 2 ---------------------------
// ------------------------------------------
void Max_Heapify(node* raiz)
{
    if (raiz==NULL) return;
    node* maximo = raiz;
    node* noh = raiz->filhoesq;
    while (noh!=NULL) {
        if (noh->valor > maximo->valor) maximo = noh;
        noh = noh->irmaodir;
    }
    if (maximo==raiz) return;
    int aux = raiz->valor;
    raiz->valor = maximo->valor;
    maximo->valor = aux;

    Max_Heapify(maximo);
}

void BuildMaxHeap(node* raiz)
{
    node* noh = raiz->anterior;
    while (noh!=raiz) {
        Max_Heapify(noh);
        noh = noh->anterior;
    }
    Max_Heapify(raiz);
}

void questao2(int N, int K)
{
    node* raiz = tree_create(N,K);
    cout<<"\n\n\n Pre-Ordem:   ";
    pre_ordem(raiz);

    BuildMaxHeap(raiz);

    cout<<"\n\n\n BuildMaxHeap - Pre-Ordem:   ";
    pre_ordem(raiz);
    cout<<"\n\n HeapSort decrescente:\n";

    node* folha = raiz->anterior;
    while (folha!=raiz) {
        cout<<raiz->valor<<" ";
        raiz->valor = folha->valor;
        if (folha->anterior->irmaodir==folha) {
            folha->anterior->irmaodir = NULL;
        } else {
            folha->pai->filhoesq = NULL;
        }
        raiz->anterior = folha->anterior;
        delete folha;
        folha = raiz->anterior;
        Max_Heapify(raiz);
    }
    cout<<raiz->valor;
    delete raiz;
}
// ------------------------------------------
// ---- QUESTAO 3 ---------------------------
// ------------------------------------------
int questao3(digraph& G) {
    list<int>::iterator it;
    int x,y,N = G.N;
    int** A = new int*[N];

    for (x=0; x<N; x++) {
        A[x] = new int[N]();// inicializa com 0s
        for (it=G.V[x].AdjL.begin(); it!=G.V[x].AdjL.end(); ++it) {
            y = (*it);
            A[x][y] = 1;
        }
    }
    int naodir = 1;
    for (x=0; x<N; x++) {
        for (it=G.V[x].AdjL.begin(); it!=G.V[x].AdjL.end(); ++it) {
            y = (*it);
            if (A[y][x]==0) {naodir = 0; break;}
        }
        if (!naodir) break;
        
    }
    for (x=0; x<N; x++) delete A[x];
    delete A;
    return naodir;
}


// ------------------------------------------
// ---- QUESTAO 4 ---------------------------
// ------------------------------------------
void questao4(digraph& G, digraph& Gt) {
    list<int>::iterator it;
    int x,y;
    int N = G.N;
    Gt.N = N;
    Gt.V = new vertice[N];

    for (x=0; x<N; x++) {
        for (it=G.V[x].AdjL.begin(); it!=G.V[x].AdjL.end(); ++it) {
            y = (*it);
            Gt.V[y].AdjL.push_back(x);
        }
    }
    for (y=0; y<N; y++) {
        Gt.V[y].grau = Gt.V[y].AdjL.size();
    }
}


// ------------------------------------------
// ---- QUESTAO 5 ---------------------------
// ------------------------------------------
void questao5(digraph& G, digraph& Q) {
    list<int>::iterator it, it2;
    int x,y,z, N = G.N;
    Q.N = N;
    Q.V = new vertice[N];

    int* visit = new int[N]();
    for (x=0; x<N; x++) {
        for (it=G.V[x].AdjL.begin(); it!=G.V[x].AdjL.end(); ++it) {
            y = (*it);
            for (it2=G.V[y].AdjL.begin(); it2!=G.V[y].AdjL.end(); ++it2) {
                z = (*it2);
                visit[z] = 1;
            }
        }
        visit[x] = 0;
        for (z=0; z<N; z++) {
            if (visit[z]==1) {
                Q.V[x].AdjL.push_back(z);
                visit[z] = 0;
            }
        }
        Q.V[x].grau = Q.V[x].AdjL.size();
    }
    delete[] visit;
}


// ------------------------------------------
// ---- QUESTAO 6 ---------------------------
// ------------------------------------------
void questao6(digraph& G1, digraph& G2, digraph& Gp) {
    list<int>::iterator it;
    int v,x1,x2;
    int N1 = G1.N;
    int N2 = G2.N;
    Gp.N = N1 * N2;
    Gp.V = new vertice[Gp.N];

    for (x1=0; x1<N1; x1++) {
        for (x2=0; x2<N2; x2++) {
            v = x1*N2 + x2;
            int loop=0;
            for (it=G2.V[x2].AdjL.begin(); it!=G2.V[x2].AdjL.end(); ++it) {
                int y2 = (*it);
                if (x2==y2) loop=1;
                int w = x1*N2 + y2;
                Gp.V[v].AdjL.push_back(w);
            }
            for (it=G1.V[x1].AdjL.begin(); it!=G1.V[x1].AdjL.end(); ++it) {
                int y1 = (*it);
                if ((x1!=y1)||(!loop)) {// no caso de permitir loops
                    int w = y1*N2 + x2;
                    Gp.V[v].AdjL.push_back(w);
                }
            }
        }
    }
    for (v=0; v<Gp.N; v++) {
        Gp.V[v].grau = Gp.V[v].AdjL.size();
    }
}


// ------------------------------------------
// ---- QUESTAO 7 ---------------------------
// ------------------------------------------

// --------------------------------------------
// Busca em profundidade (original, recursiva)
// --------------------------------------------
void busca_prof_rec(digraph& G, int u, int& tempo) {
    list<int>::iterator it;
    if (G.V[u].cor=="branco") {
        G.V[u].cor = "cinza";
        G.V[u].tempo = tempo++;
        for (it=G.V[u].AdjL.begin(); it!=G.V[u].AdjL.end(); ++it) {
            int v = (*it);
            G.V[v].pai = u;
            busca_prof_rec(G,v,tempo);
        }
        G.V[u].cor = "preto";
        G.V[u].fim = tempo++;
    }
}

int busca_prof(digraph& G) {
    for (int i=0; i<G.N; i++) {
        G.V[i].cor = "branco";
        G.V[i].pai = -1;
        G.V[i].tempo=0;
    }
    int tempo = 0;
    for (int s=0; s<G.N; s++) {
        busca_prof_rec(G,s,tempo);
    }
    return tempo;
}
void questao7(digraph& G) {
    cout<<"Ordenacao topologica:"<<endl<<endl;
    int tempo_total = busca_prof(G);
    for (int s=0; s<G.N; s++) {
        cout<<"Vertice "<<s<<", Ordem "<<tempo_total-G.V[s].fim<<endl;
    }
}


// -----------------------------------------------
// ---- QUESTOES 8 e 9 ---------------------------
// -----------------------------------------------

// --------------------------------------------
// ARTICULACOES E PONTES DE UM GRAFO
// --------------------------------------------
void questao8_9_rec(digraph& G, int x, int& tempo) {
    list<int>::iterator it;
    G.V[x].tempo = ++tempo;
    G.V[x].lowtp = tempo;
    int root; if (G.V[x].pai==x) root=1; else root=0;
    for (it=G.V[x].AdjL.begin(); it!=G.V[x].AdjL.end(); ++it) {
        int y = (*it);
        if (G.V[y].tempo<=0) {
            G.V[y].pai = x;
            questao8_9_rec(G,y,tempo);
            if (G.V[x].lowtp>G.V[y].lowtp) G.V[x].lowtp = G.V[y].lowtp;
            if (G.V[x].tempo<G.V[y].lowtp) printf("ponte %d-%d\n",x,y);
            if (G.V[x].tempo<=G.V[y].lowtp) {
                if (root==0) {cout<<"articulacao "<<x<<endl;}
                if (root==2) {cout<<"articulacao "<<x<<endl; root=3;}
                if (root==1) root=2;
            }
        } else if (y!=G.V[x].pai) {
            if (G.V[x].lowtp>G.V[y].tempo) G.V[x].lowtp = G.V[y].tempo;
        }
    }
}
void questao8_9(digraph& G) {
    for (int x=0; x<G.N; x++) {
        G.V[x].tempo=0;
    }
    int tempo = 0;
    for (int x=0; x<G.N; x++) {
        if (G.V[x].tempo==0) {
            G.V[x].pai = x;
            questao8_9_rec(G,x,tempo);
        }
    }
}


// -----------------------------------------------------------------
// ---- MANUTENÇÃO DE GRAFOS ---------------------------------------
// -----------------------------------------------------------------

int digraph_create(digraph& G) {
    ifstream arq;
    arq.open("entrada_lista2_adjL.txt");
    if (arq.fail()) return 0;
    arq >> G.N;
    G.M=0; G.V = NULL;
    G.V = new vertice[G.N];

    for (int x=0; x<G.N; x++) {
        int grau;
        arq >> grau;
        G.V[x].grau = grau;
        G.M += grau;
        for (int i=1; i<=grau; i++) {
            int y;
            arq >> y;
            G.V[x].AdjL.push_back(y);
        }
    }
    arq.close();
    return 1;
}

void digraph_print(digraph& G) {
    list<int>::iterator it;
    cout << "\n" << G.N << "\n";

    for (int x=0; x<G.N; x++) {
        cout << G.V[x].grau <<" ";

        for (it=G.V[x].AdjL.begin(); it!=G.V[x].AdjL.end(); ++it) {
            cout << (*it) << " ";
        }
        cout << "\n";
    }
}

void digraph_delete(digraph& G) {
    delete[] G.V;
    G.V = NULL;
}
