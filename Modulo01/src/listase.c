#include "stdio.h"
#include "stdlib.h"

typedef struct elem_lse t_elemento_lse;
struct elem_lse{
    int cargautil;// carga util
    struct elem_lse* prox;// endereco prox
};

t_elemento_lse* criar_elemento_lse(int cargautil){
    t_elemento_lse* novo = malloc(sizeof(t_elemento_lse));
    novo->cargautil = cargautil;
    novo->prox = NULL;

    return novo;
}

typedef struct LSE{
    t_elemento_lse* inicio;
    // int tamanho;
    // int nro_ins;
    // int nro_del;
}T_LSE;

T_LSE* criarLSE(){

    T_LSE* nova = malloc(sizeof(struct LSE));
    nova->inicio = NULL;

    return nova;
}

// operacoes baseadas em posicao
// inserir_inicioLSE();
// remover_inicioLSE();
// acessar_LSE();
// inserir_fincalLSE();
// remover_finalLSE();