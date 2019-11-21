#include <iostream>



typedef struct node{
    int chave;
    struct node* pai;
    struct node* esq;
    struct node* dir;
}node;

int main()
{
    bool certo;
    node* raiz=NULL; int aux;
    printf("Bem vindo! Comece criando um no, no caso a raiz\n");
    scanf("%d", &aux);
    raiz = new node;
    raiz->chave = aux; raiz->pai=NULL; raiz->esq=NULL; raiz->dir=NULL;
    
    do{
        printf("Digite:\n1-para inserir o no\n2-deletar um no\n3-para imprimir\n0-para sair\n");
        scanf("%d", &aux);
        
        if(aux==1){
            node* n;
            printf("Digite o valor do no a ser criado:\n");
            scanf("%d", &aux);
            n = new node;
            n->chave = aux; n->pai=NULL; n->esq=NULL; n->dir=NULL;
            tree_insert(r, n);
        }
        
    }while(aux!=0);

    return 0;
}


//funcoes
node* tree_insert(node* raiz, node* n){
    node* y=NULL; node* x=raiz;
    while(x!=NULL){
        y=x;
        if(n->chave < x->chave) x = x->esq;
        else x = x->dir;
    }
    n->pai = y;
    if(y==NULL)raiz = n;
    else if(n->chave < y->chave) y->esq = n;
    else y->dir = n;
}

void transplant(node* raiz, node* u, node* v){
    if(u->pai==NULL) raiz = v;
    else if(u==u->pai->esq) u->pai->esq = v;
    else u->pai->dir = v;
    if(v!=NULL){
        v->pai = u->pai;
    }
};



void tree_delete(node* z, node* raiz){
    if(z->esq==NULL) transplant(raiz, z, z->dir);
    else if(z->dir==NULL) transplant(raiz, z, z->esq);
    else{
        node* y = tree_minimum(z->dir);
        if(y->pai!=z){
            transplant(raiz, y, y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }
        transplant(raiz, z, y);
        y->esq = z->esq;
        y->esq->pai = y;
    }
}


