#include "stdio.h"
#include "stdlib.h"
#include "listase.h"

typedef struct elem_se{
    void* carga_util;
    struct elem_se* prox;
} t_elemento_lse;

/**
 * cria um elemento da LSE
*/
t_elemento_lse* criar_elemento_lse(void* carga_util){
    t_elemento_lse* novo = malloc(sizeof(t_elemento_lse));
    novo->carga_util = carga_util;
    novo->prox = NULL;

    printf("Criando: %p %p %p\n", novo, novo->carga_util, novo->prox);

    return novo;
}

typedef struct lse t_lse;
struct lse{
    t_elemento_lse* inicio;
    t_elemento_lse* fim;
    int tamanho;
    // operacoes
    t_imprimir_lse imprimir;
    t_comparar_lse comparar;

};

t_lse* criar_lse(t_imprimir_lse imprimir, t_comparar_lse comparar){
    t_lse *l = malloc(sizeof(t_lse));
    l->inicio = l->fim = NULL;
    l->tamanho = 0;
    l->imprimir = imprimir;
    l->comparar = comparar;
    return l;
}

void inserir_lse(t_lse* lse, void* carga_util){
    t_elemento_lse* novo = criar_elemento_lse(carga_util);

    if (lse->inicio == NULL){
        lse->inicio = lse->fim = novo; 
    }else{
        novo->prox = lse->inicio;
        lse->inicio = novo;
    }

    lse->tamanho++;
}

void inserir_final_lse(t_lse* lse, void* carga_util){
    
    t_elemento_lse* novo = criar_elemento_lse(carga_util);

    if (lse->inicio == NULL){
        lse->inicio = lse->fim = novo;
    }else{
       lse->fim->prox = novo;
        lse->fim = novo;
    }
    lse->tamanho++;

}

void* remover_lse(t_lse* lse){
    void* carga_util = NULL;
    t_elemento_lse *removivel = lse->inicio;
    if (lse->inicio != NULL){
        carga_util = removivel->carga_util;
        lse->inicio = removivel->prox;
        free(removivel);
        lse->tamanho--;
    }
    return carga_util;
}

void* acessar_lse(t_lse* lse, int pos){
    pos = (pos>lse->tamanho?pos%lse->tamanho:pos);
    t_elemento_lse *cam = lse->inicio;
    void* carga_util=NULL;

    if (lse->inicio){
        int i=1;
        while(i<pos){
            cam = cam->prox;
            i++;
        }
        carga_util = cam->carga_util;  
    }
    return carga_util;
}

void imprimir_lse(t_lse *lse){
    t_elemento_lse *cam = lse->inicio;
    while(cam){
        lse->imprimir(cam->carga_util);
        cam = cam->prox;
    }
}