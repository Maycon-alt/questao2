#include <iostream>
#include <cstdlib>
#include <stack>

typedef int TIPOCHAVE; // defino o tipo chave(onde vou guardar as coisas);

typedef struct aux{ // estrutura do no;
    TIPOCHAVE chave;
    int *esq;
    int *dir;
}NO;

typedef NO* PONT;

PONT inicializa(){  //cria arvore e retorna NULL;
    return NULL;
}

PONT criaNovoNo(TIPOCHAVE ch){
    PONT* novoNo = new PONT;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    return novoNo;
}
PONT adiciona(PONT raiz, PONT no){
    pilha1.push(&raiz);
    pilha2.push(&no);
    if(raiz==NULL){
        pilha1.pop();
        pilha2.pop();
        return no;
    }
    if(no->esq < raiz->chave){
        raiz->esq = adiciona(raiz->esq, no);
    }
    else{
        raiz->dir = adiciona(raiz->dir, no);
    }
    return raiz;
}

int main()
{
    int i;
    stack <int> pilha1;
    stack <int> pilha2;
    
    PONT r = inicializa();
    if(r==NULL){
        printf("criada com sucesso\n");
        for(i=0;i<5;i++){
            int x = rand()%10;
            PONT no = criaNovoNo(x);
            r = adiciona(r, no);
        }
    }
    else{
        printf("erro\n");
    }

    return 0;
}
