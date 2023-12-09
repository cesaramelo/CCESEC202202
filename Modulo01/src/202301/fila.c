#include "stdio.h"
#include "stdlib.h"
#include "listase.h"
#include "fila.h"

struct fila{
    t_lse* elementos;
    int tamanho;
    int ocupa;
};

t_fila* criar_fila(int tamanho){
    t_fila* f = malloc(sizeof(t_fila));
    f->tamanho = tamanho;
    f->ocupa=0;
    f->elementos = criar_lse(NULL,NULL);
    return f;
}
void enfileirar(t_fila* f, void* elem){
    if (f){
        f->ocupa++;
        inserir_final_lse(f->elementos, elem);
    }
}

void* desenfileirar(t_fila* f){
    void* elem = NULL;
    if (f && (f->ocupa>0)){
        elem = remover_inicio_lse(f->elementos);
        f->ocupa--;
    }
    return elem;
}

int tamanho_fila(t_fila* f){
    return f->ocupa;
}

