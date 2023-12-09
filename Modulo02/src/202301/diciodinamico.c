#include "stdlib.h"
#include "vetordinamico.h"
#include "diciodinamico.h"
#include "../../../Modulo01/src/202301/listase.h"
#include "math.h"

struct dicio_dinamico{
    void* *elems;
    int fator_carga;
    int tamanho;
    t_comparar_dd comparar;
};

typedef int(*t_comparar_dd)(void*, void*);
typedef struct colisao{
    int chave;
    void* carga;
}t_colisao;


t_colisao* criar_colisao(int chave, void* carga){
    t_colisao* c = malloc(sizeof(t_colisao));
    c->chave = chave;
    c->carga = carga;

    return c;
}

int comparar_colisao(void* c1, void* c2){
    t_colisao* cc1 = c1;
    t_colisao* cc2 = c2;

    return cc1->chave - cc2->chave;
}

static int funcao_hashing(t_dd *dd , int chave){
    return chave % dd->tamanho;
}


t_dd* criar_dd(int fator_carga, int tam){
    t_dd* dd = malloc(sizeof(t_dd));
    dd->tamanho = tam;
    
    dd->elems = malloc(sizeof(void*)*dd->tamanho);
    for(int i=0;i<dd->tamanho;i++){
        dd->elems[i] = criar_lse(NULL, comparar_colisao);
    }
    dd->fator_carga = fator_carga;
    dd->comparar = comparar_colisao;

    return dd;    
};


int inserir_dd(t_dd *dd, int chave, void*carga){
    int k = funcao_hashing(dd, chave);
    t_lse* colisoes = dd->elems[k];
    t_colisao* colisao = buscar_lse(colisoes, (void*) &chave);
    if (colisao == NULL){
        inserir_lse(colisoes,criar_colisao(chave, carga));
        return 1;
    }
    return 0;
}

void* consultar_dd(t_dd *dd, int chave){

    int k = funcao_hashing(dd, chave);
    t_lse* colisoes = dd->elems[k];
    t_colisao* colisao = buscar_lse(colisoes, (void*) &chave);
    if (colisao != NULL){
        return colisao->carga;
    }
    return NULL;
}

void* remover_dd(t_dd *dd, int chave){
    int k = funcao_hashing(dd, chave);
    t_lse* colisoes = dd->elems[k];
    t_colisao* colisao = remover_lse(colisoes, (void*) &chave);
    void* carga = NULL;
    if (colisao != NULL){
        carga = colisao->carga;
        free(colisao);
    }
    return carga;
}

static int primo(int partida){
    int novo_primo;
    int tentativa=0;
    do{
        tentativa++;
        int k = floor((partida*k-1)/2);
        int A[k];
        for(int i=0;i<k;i++)
            A[k]=1;
        for(int i=1;i<sqrt(k);i++){
            int j = i;
            while ((i+j+2*i*j) <= k){
                A[i+j+2*i*j] = 0;
                j++;
            }
        }
        int i=k-1;
        while(A[i]==0){
            i--;
        }
        novo_primo = 2*i+1;
    }while (novo_primo == partida);
 

    return novo_primo;
}

static t_dd* rehashing(t_dd* velho){
    int novo_tamanho = primo(velho->tamanho);
    t_dd* novo = criar_dd(velho->fator_carga, novo_tamanho);
 
    for (int i=0;i<velho->tamanho;i++){
        t_lse *colisoes = velho->elems[i];
        t_colisao *colisao = remover_inicio_lse(colisoes);
        while(colisao){
            inserir_dd(novo, colisao->chave, colisao->carga);
            free(colisao);
            colisao = remover_inicio_lse(colisoes);
        }
    }

    return novo;
}