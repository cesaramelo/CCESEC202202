#include "stdio.h"
#include "stdlib.h"
#include "fila.h"

struct fila{
    void* *elems;
    int tamanho;
    int inicio;
    int fim;
    int ocupacao;
    short e_infinita;
};

t_fila* criar_fila(int tamanho){
    t_fila* f = malloc(sizeof(t_fila));

    f->e_infinita = (tamanho<=0?1:0);
    f->tamanho = (tamanho<=0?1:tamanho);
    f->inicio = 0;
    f->fim = 0;
    f->ocupacao=0;
    
    f->elems = malloc(sizeof(void*)*f->tamanho);

    return f;

}

int enfileirar(t_fila* f, void* elem){
    int status = 0; // fals0
    if ((f->e_infinita) && (f->ocupacao == f->tamanho)){
        f->tamanho = f->tamanho*2;
        f->elems = realloc(f->elems, sizeof(void*)*f->tamanho);
    }
    if (f->ocupacao < f->tamanho){
        f->elems[f->fim] = elem;
        f->fim = (f->fim+1) % f->tamanho;
        f->ocupacao++;
        status = 1; // verdade 
    }

    return status;
}

void* desenfileirar(t_fila* f){
    void* elem = NULL;

    if (f->ocupacao>0){
        elem = f->elems[f->inicio];
        f->inicio = (f->inicio+1) % f->tamanho;
        f->ocupacao--;
    }
    return elem;
}

void* primeiro_fila(t_fila* f){
    void* primeiro=NULL;
    if((f!=NULL) && (f->ocupacao>0)){
        primeiro = f->elems[f->inicio];
    }
    return primeiro;
}

int tamanho_fila(t_fila* f){
    if(f!=NULL){
        return f->tamanho;
    }
    return -1;
}

int ocupacao_fila(t_fila* f){
    if(f!=NULL){
        return f->ocupacao;
    }
    return -1;
}
// Espaço TAD
