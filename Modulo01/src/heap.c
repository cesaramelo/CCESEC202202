#include "stdlib.h"
#include "stdio.h"
#include "heap.h"

struct heap{
    void* *elem;
    int ocupacao;
    int tamanho;
    int e_infinito;

    TCompararHeap comparar;
};

static void trocar(void* elem[], int i, int j){
    void* aux = elem[i];
    elem[i] = elem[j];
    elem[j] = aux;
}

static void desce_no_heap(t_heap* h, int k){

    int imaior = k;
    int childrenLeft = (k*2) + 1;
    int childrenRight = (k*2) + 2;
    
    if ((childrenLeft < h->ocupacao) && (h->comparar(h->elem[imaior],h->elem[childrenLeft])<0)){
        imaior = childrenLeft;
    }
    if ((childrenRight < h->ocupacao) && (h->comparar(h->elem[imaior],h->elem[ childrenRight ])<0)){
        imaior = childrenRight;
    }
    if (imaior!=k){
        trocar(h->elem, k, imaior);
        desce_no_heap(h,imaior);
    }

}

static void sobe_no_heap(t_heap* h, int k){
    
    int kancestral= (k-1)/2;

    if ((kancestral>=0)&&(h->comparar(h->elem[kancestral],h->elem[k])<0)){
        trocar(h->elem, k, kancestral);
        sobe_no_heap(h, kancestral);
    }
}

static void heapifica(t_heap* heap){
    int n = heap->ocupacao;
    int k = (n-1)/2;

    do{
        desce_no_heap(heap,k);
        k--;
 
    }while(k>0);
}

t_heap* criar_heap(int tam, TCompararHeap comparar){
    t_heap* h = malloc(sizeof(t_heap));
    h->tamanho = (tam>0?tam:2);
    h->e_infinito = (tam<=0?1:0);
    h->ocupacao = 0;
    h->elem = malloc(sizeof(void*)*h->tamanho);
    
    h->comparar = comparar;

    return h;
}

int inserir_heap(t_heap* h, void* elem){

    int inseriu = popular_heap(h, elem);
    
    if (inseriu)
        sobe_no_heap(h,h->ocupacao-1);
    
    return inseriu;
}

void* remover_heap(t_heap* h){

    if(h->ocupacao <= 0) return NULL; // Se a fila estiver vazia nem continua.

    trocar(h->elem, 0, h->ocupacao-1);
    h->ocupacao--;
    desce_no_heap(h,0);

    return h->elem[h->ocupacao];
}

void* raiz_heap(t_heap* h){
    return (h->ocupacao==0?NULL:h->elem[0]);
}

int popular_heap(t_heap* h, void* elem){
    int status = 0; // fals0

    if ((h->e_infinito) && (h->ocupacao == h->tamanho)){
        h->tamanho = h->tamanho*2;
        h->elem = realloc(h->elem,sizeof(void*)*h->tamanho);
    }
    if(h->ocupacao<h->tamanho){
        h->elem[h->ocupacao] = elem;
        h->ocupacao++;
        status = 1; // verdade
    }
    return status;
}

int ocupacao_heap(t_heap* h){
    return h->ocupacao;
}

int tamanho_heap(t_heap* h){
    return h->tamanho;
}