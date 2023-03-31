#include "stdio.h"
#include "stdlib.h"

/* Tipo elemento da LSE*/
typedef struct elem_lse t_elemento_lse;
struct elem_lse{
    int cargautil;// carga util
    struct elem_lse* prox;// endereco prox
};

/**
 * cria um elemento da LSE
*/
t_elemento_lse* criar_elemento_lse(int cargautil){
    t_elemento_lse* novo = malloc(sizeof(t_elemento_lse));
    novo->cargautil = cargautil;
    novo->prox = NULL;

    return novo;
}

/**
 * Definição do tipo Lista Simplesmente Encadeada
*/
typedef struct lse{
    t_elemento_lse* inicio; // Primeiro elemento
    // int tamanho; 
    // int nro_ins;
    // int nro_del;
}t_lse;

t_lse* criar_lse(){
     t_lse* nova;
     
    nova  = malloc(sizeof(t_lse));
    nova->inicio = NULL;

    return nova;
}

// operacoes baseadas em posicao
void inserir_inicio_lse(t_lse* lse, int carga){
    
    t_elemento_lse* novo = criar_elemento_lse(carga);

    novo->prox = lse->inicio;
    lse->inicio = novo;

}
// int remover_inicio_lse(){}
// acessar_lse(){}
// void inserir_final_lse(){}
// int remover_final_lse(){}