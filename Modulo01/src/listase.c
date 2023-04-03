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

    printf("Criando: %p %d %p\n", novo, novo->cargautil, novo->prox);

    return novo;
}

/**
 * Definição do tipo Lista Simplesmente Encadeada
*/
typedef struct lse{
    t_elemento_lse* inicio; // Primeiro elemento
    int tamanho; 
    // int nro_ins;
    // int nro_del;
}t_lse;

t_lse* criar_lse(){
     t_lse* nova;
     
    nova  = malloc(sizeof(t_lse));
    nova->inicio = NULL;
    nova->tamanho=0;

    return nova;
}

// operacoes baseadas em posicao
void inserir_inicio_lse(t_lse* lse, int carga){
    
    t_elemento_lse* novo = criar_elemento_lse(carga);

    novo->prox = lse->inicio;
    lse->inicio = novo;
    lse->tamanho++;

}

int remover_inicio_lse(t_lse* lse){
    int carga=0;
    t_elemento_lse* removivel = lse->inicio;
    if (lse->inicio != NULL){    
        lse->inicio = removivel->prox;
        lse->tamanho--;
        carga = removivel->cargautil;

        free(removivel);
    }
    return carga;
}

int acessar_lse(t_lse* lse, int pos){
    int i=1;
    int carga=-1; // entrada invalida

    t_elemento_lse* cam = lse->inicio;
    if ((pos<=lse->tamanho)){
        while(i<pos){
            cam = cam->prox;
            i++;
        }
        carga = cam->cargautil;
    }
    return carga;
}

// void inserir_final_lse(t_lse* lse, int carga){}
// int remover_final_lse(t_lse* lse){}

int main(){
    t_lse* musicas = criar_lse();

    for(int i=1;i<10;i++ ){
        inserir_inicio_lse(musicas, i);
    }

    int musica = remover_inicio_lse(musicas);
    printf("removeru: %d\n", musica);

    musica = acessar_lse(musicas, -6);
    printf("acessou: %d\n", musica);

    return 0;

}