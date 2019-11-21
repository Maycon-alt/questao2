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

















