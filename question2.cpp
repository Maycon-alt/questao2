#include <stdio.h>
#include <iostream>
#include <cstdlib>

int buscabin(int vetor[], int num, int tam);

int main()
{
    int tam;
    scanf("%d", &tam);
    int vetor[tam];
    
    printf("digite os valores do vetor: \n");
    for(int i=1; i<=tam;i++){
        scanf("%d", &vetor[i]);
    }
    int num;
    printf("digite o numero procurado:\n");
    scanf("%d", &num);
    
    int posicao = buscabin(vetor, num, tam);
    
    if(posicao<0) printf("valor nao encontrado\n");
    else printf("valor encontrado na posicao %d", posicao);

    return 0;
}

int buscabin(int vetor[], int num, int tam){
    int p, q,r;
    p=1; r=(tam+1)/2;
    while(p<=r){
        int q=(p+r)/2;
        
        if(vetor[2*q-1]<num) p=q+1;
        else if(vetor[2*q-1]>num) p=q-1;
        else if(vetor[2*q-1]==num) return 2*q-1;
    }
    
    p=1; r=(tam/2);
    while(p<=r){
        int q=(p+r)/2;
        if(vetor[2*q]>num) p=q+1;
        else if(vetor[2*q]<num) p= q-1;
        else if(vetor[2*q]==num) return 2*q;
    }
    
    return -1;
    
}
