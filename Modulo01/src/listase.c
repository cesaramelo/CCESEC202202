#include "stdio.h"
#include "stdlib.h"

/* Tipo elemento da LSE*/
typedef struct elem_lse t_elemento_lse;
struct elem_lse{
    void* cargautil;// carga util
    struct elem_lse* prox;// endereco prox
};

/**
 * cria um elemento da LSE
*/
t_elemento_lse* criar_elemento_lse(void* cargautil){
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
void inserir_inicio_lse(t_lse* lse, void* carga){
    
    t_elemento_lse* novo = criar_elemento_lse(carga);

    novo->prox = lse->inicio;
    lse->inicio = novo;
    lse->tamanho++;

}

void* remover_inicio_lse(t_lse* lse){
    void* carga=NULL;
    t_elemento_lse* removivel = lse->inicio;
    if (lse->inicio != NULL){    
        lse->inicio = removivel->prox;
        lse->tamanho--;
        carga = removivel->cargautil;

        free(removivel);
    }
    return carga;
}

void* acessar_lse(t_lse* lse, int pos){
    int i=1;
    void* carga=NULL; // entrada invalida
    if (pos<0){
        pos = (pos % lse->tamanho) + (lse->tamanho+1); 
        pos = (pos==0?1:pos);
    }else if(pos>0){
        pos = pos % lse->tamanho;
        pos = (pos==0?lse->tamanho:pos);
    }else{
        return carga;
    }

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

void inserir_final_lse(t_lse* lse, void* carga){
    t_elemento_lse* novo = criar_elemento_lse(carga);
    if(lse->tamanho == 0){ // lse->inicio == NULL
        lse->inicio = novo;
    }else{
        t_elemento_lse* cam = lse->inicio;
        while(cam->prox!=NULL){
            cam=cam->prox;
        }
        cam->prox = novo;
    }
    lse->tamanho++;
}

void* remover_final_lse(t_lse* lse){
    void* carga=NULL;

    t_elemento_lse* ant=NULL;
    t_elemento_lse* cam=lse->inicio;
    if (lse->tamanho == 0){
        return carga;
    }else if(lse->tamanho == 1){
        cam = lse->inicio;
        lse->inicio=NULL;
    }else{
        while(cam->prox!=NULL){
            ant = cam;
            cam = cam->prox;
        }
        ant->prox = NULL;
    }
    carga = cam->cargautil;
    free(cam);
    lse->tamanho--;
    return carga;
}

// Lista no contexto neutralizado (genérico)

//----------

// Contexto especialista
typedef struct musica{
    char nome[60];
    int duracao_seg;
    char genero[30];
}t_musica;

t_musica* criar_musica(char nome[], int duracao, char genero[]){
    t_musica* musica = malloc(sizeof(t_musica));

    musica->duracao_seg = duracao;
    strcpy(musica->genero, genero);
    strcpy(musica->nome, nome);

    return musica;
}   


int main(){
    t_lse* musicas = criar_lse();
    char nome[60], genero[30];
    int duracao;

    for(int i=1;i<10;i++ ){
        scanf("%s", nome);
        scanf("%s", genero);
        scanf("%d", &duracao);
        t_musica* m = criar_musica(nome, duracao, genero);
//        inserir_inicio_lse(musicas, i);
        inserir_final_lse(musicas, m);
    }

    t_musica*  musica_inicio = remover_inicio_lse(musicas);
    //printf("removeu: %d\n", musica);
    free(musica_inicio);
    
    t_musica* musica_ult = remover_final_lse(musicas);
    //printf("removeu: %d\n", musica_ult);
    free(musica_ult);

    t_musica* segunda = acessar_lse(musicas, -2);
    //printf("acessou: %d\n", segunda);
    free(segunda);

    t_musica* outra_musica = acessar_lse(musicas, 15);
    //printf("acessou: %d\n", outra_musica);
    free(outra_musica);

    return 0;

}