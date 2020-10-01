package tabela;
public interface AppTabela {
    public abstract void consultarTime();
    public abstract void jogo();
    public abstract void consultarTabela();
    public abstract void verJogador(); 
    public abstract void verTecnico();
}


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


