#include "stdio.h"
#include "stdlib.h"
#include "listase.h"
#include "fila.h"

struct fila{
    t_lse* elementos;
    int tamanho;
};

t_fila* criar_fila(int tamanho){
    t_fila* f = malloc(sizeof(t_fila));
    f->tamanho = tamanho;
    f->elementos = criar_lse(NULL,NULL);
    return f;
}
void enfileirar(t_fila* f, void* elem){
    if (f){
        f->tamanho++;
        inserir_final_lse(f->elementos, elem);
    }
}

void* desenfileirar(t_fila* f){
    void* elem = NULL;
    if (f && (f->tamanho>0)){
        elem = remover_lse(f->elementos);
        f->tamanho--;
    }
    return elem;
}

int tamanho_fila(t_fila* f){
    return f->tamanho;
}

