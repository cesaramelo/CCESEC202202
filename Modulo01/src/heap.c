#include "stdlib.h"
#include "stdio.h"

typedef struct heap t_heap;
struct heap{
    void* *elem;
    int ocupacao;
    int tamanho;
    int e_infinito;
};

t_heap* criar_heap(int tam){
    t_heap* h = malloc(sizeof(t_heap));
    h->tamanho = (tam>0?tam:2);
    h->e_infinito = (tam<=0?1:0);
    h->ocupacao = 0;
    h->elem = malloc(sizeof(void*)*h->tamanho);
    
    return h;
}

static void trocar(void* elem[], int i, int j){
    void* aux = elem[i];
    elem[i] = elem[j];
    elem[j] = aux;
}

static void desce_no_heap(void* elem[], int ocupa, int k){
    int imaior = k;
    if ((2*k+1<ocupa) && (elem[imaior]<elem[2*k+1])){
        imaior = 2*k+1;
    }
    if ((2*k+2<ocupa) && (elem[imaior]<elem[2*k+2])){
        imaior = 2*k+2;
    }
    if (imaior!=k){
        trocar(elem, k, imaior);
        desce_no_heap(elem,ocupa,imaior);
    }

}

static void sobe_no_heap(void* elem[], int k){
    int kancestral=(k/2.0)-1;
    if ((kancestral>=0)&&(elem[kancestral]<elem[k])){
        trocar(elem, k, kancestral);
        sobe_no_heap(elem, k);
    }
}

void heapifica(t_heap* heap){
    int n = heap->ocupacao;
    int k = (n/2.0)-1;

    do{
        desce_no_heap(heap->elem,heap->ocupacao,k);
        k--;
 
    }while(k>0);
}

void inserir_heap(t_heap* h, void* elem){

}

void* remover_heap(t_heap* h){

}

void* raiz_heap(t_heap* h){

}

