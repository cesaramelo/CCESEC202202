#include "stdlib.h"
#include "math.h"
#include "heap.h"
#include "stdio.h"

struct heap{
    void* *elems;
    int tamanho;
    int ocupacao;
    t_heap_comparar comparar;
};

static void trocar(void* elems[], int i, int j){
    void* aux = elems[i];
    elems[i] = elems[j];
    elems[j] = aux;
}

t_heap* criar_heap(int tamanho, t_heap_comparar comparar){
    t_heap* heap = malloc(sizeof(t_heap));
    heap->elems = malloc(sizeof(void*)*tamanho);
    heap->tamanho = tamanho;
    heap->ocupacao = 0;
    heap->comparar = comparar;

    return heap;
}

void* primeiro_heap(t_heap* heap){
    void* elem = NULL;
    if (heap->ocupacao > 0){
        elem = heap->elems[0];
    }
    return elem;
}

static void desce_heap(void* elems[], int ocupa, int i, t_heap_comparar comparar){
    int imaior = i;
    
    if ( (2*i+1 < ocupa) && (comparar(elems[imaior],elems[2*i+1])<0) ){
        imaior = 2*i + 1;
    }
    if ( (2*i+2 < ocupa) && (comparar(elems[imaior],elems[2*i+2])<0) ){
        imaior = 2*i + 2;
    }
    if (imaior != i){
        trocar(elems,imaior,i);
        desce_heap(elems, ocupa, imaior,comparar);
    }
}

void* remover_heap(t_heap* heap){
    void* elem = NULL;
    if (heap->ocupacao > 0){
        elem = heap->elems[0];
        heap->ocupacao--;
        if (heap->ocupacao>=1){
            trocar(heap->elems,0,heap->ocupacao);
            desce_heap(heap->elems, heap->ocupacao, 0,  heap->comparar);
        }
    }    
    return elem;
}

void sobe_heap(void* elems[], int i, t_heap_comparar comparar){
    if (i > 0){
        int anc_i = (int)floor((i-1)/2);
        if (comparar(elems[anc_i],elems[i])<0){
            trocar(elems,anc_i,i);
            sobe_heap(elems,anc_i,comparar);
        }
    }
}

void inserir_heap(t_heap* heap, void* elem){
    heap->elems[heap->ocupacao] = elem;
    sobe_heap(heap->elems, heap->ocupacao, heap->comparar);
    heap->ocupacao++;

}

void colocar_heap(t_heap* heap, void* elem){
    heap->elems[heap->ocupacao] = elem;
    heap->ocupacao++;
}

void heapifica(t_heap* heap){
    int k = floor(heap->ocupacao/2.0) - 1;
    k=(k<0?0:k);
    for(int i=k;i>=0;i--){
        desce_heap(heap->elems,heap->ocupacao,i,heap->comparar);
    }
}

heap_sort(void* elems[], int tam, t_heap_comparar comparar){
    t_heap* heap = criar_heap(tam,comparar);
    for (int i=0; i<tam;i++){
        colocar_heap(heap,elems[i]);
    }
    
    heapifica(heap);
    
    for(int i=tam-1;i>=0;i--){
        elems[i] = remover_heap(heap);
    }

    free(heap->elems);
    free(heap);
}
int comparar_int(int* p1, int* p2){
    return (*p1 - *p2);
}

int* ler_int(){
    int* inteiro = malloc(4);
    scanf("%d", inteiro);
    return inteiro;
}

int main(){
    int* inteiros[10];
    for(int i=0;i<10;i++){
        inteiros[i] = ler_int();
    }
    heap_sort(inteiros, 10, comparar_int);

   for(int i=0;i<10;i++){
        printf("%d ", *inteiros[i]);
    }
    printf("\n");
 
}