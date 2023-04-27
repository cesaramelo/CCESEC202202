#include "stdio.h"
#include "stdlib.h"
#include "heap.h"
#include "filacomprioridade.h"

struct fila_cp{
    t_heap* heap;
    // 
};


t_fila_cp* criar_fila_cp(int tam, TCompararFilaCP comparar){
    
    t_fila_cp *fcp = malloc(sizeof(t_fila_cp));
    fcp->heap = criar_heap(tam, comparar);
    
    return fcp;

}

int enfileirarCP(t_fila_cp *f, void* elem){

    return inserir_heap(f->heap, elem);

}

void* desenfileirarCP(t_fila_cp *f){

    return remover_heap(f->heap);
}

void* primeiro_FCP(t_fila_cp *f){
    
    return raiz_heap(f->heap);

}

int ocupacao_FCP( t_fila_cp *f){
    return ocupacao_heap(f->heap);
}

int tamanho_FCP(t_fila_cp *f){
    return tamanho_heap(f->heap);
}
