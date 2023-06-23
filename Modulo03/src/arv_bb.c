#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
#include "arv_bb.h"

typedef struct no TNo;
struct no{
    void* info;
    TNo* sae;
    TNo* sad;
    TNo* ancestral;
};

TNo* criar_no(TNo* ascentral, void* info){
    TNo* novo = malloc(sizeof(TNo));
    novo->info = info;
    novo->sae = NULL;
    novo->sad = NULL;
    novo->ancestral = ascentral;

    return novo;
}

typedef struct stat{
  int i_nro;
  int b_nro;
  int r_nro;  
  int b_cmps;
  int i_cmps;
  int r_cmps;
} t_stats;

struct abb{
    TNo* raiz;
    TImprimirABB imprimir;
    TCompararABB comparar;
    // removerInfoNo
    t_stats stats;
};

t_abb* criarABB(TImprimirABB imprimir, TCompararABB comparar){
    t_abb* abb = malloc(sizeof(t_abb));

    abb->raiz = NULL;
    abb->imprimir = imprimir;
    abb->comparar = comparar;
    abb->stats = (t_stats){.b_cmps=0,.i_cmps=0,.r_cmps=0,.i_nro=0,.b_nro=0,.r_nro=0};
    return abb;
}


static TNo* __inserirABB(TNo* raiz, void* info, TCompararABB comparar, t_stats* stats){
    //printf("Iniciou inserção \n");
    if (raiz == NULL){
        //printf("Inseriu no \n");
        stats->i_cmps++;
        TNo* novo = criar_no(raiz,info);
        return novo;
    }
    if (comparar(raiz->info, info) > 0){ // uso da propriedade ordem
        raiz->sae = __inserirABB(raiz->sae, info, comparar, stats);
        raiz->sae->ancestral = raiz;
        stats->i_cmps+=2;
    }else{
        raiz->sad = __inserirABB(raiz->sad, info, comparar, stats);
        raiz->sad->ancestral = raiz;
        stats->i_cmps+=3;
    }

    return raiz;
}

void estatisticaABB(t_abb *abb){
    t_stats* stats = &(abb->stats);
    printf("Estatísticas:\n");
    printf("Inserções: %d\n", stats->i_nro);
    printf("cmps nas inserções: %d\n", stats->i_cmps);
    printf("Buscas: %d\n", stats->b_nro);
    printf("cmps nas buscas: %d\n", stats->b_cmps);
    printf("Remoções: %d\n", stats->r_nro);
    printf("cmps nas remoções: %d\n", stats->r_cmps);

}

void inserirABB(t_abb *abb, void* info){
    t_stats* stats = &(abb->stats);
    stats->i_nro++; 
    abb->raiz = __inserirABB(abb->raiz, info, abb->comparar, stats);
    //printf("Terminou insercao\n");

}

TNo* __buscarABB(TNo* raiz, void* buscado, TCompararABB comparar, t_stats* stats){
    // base da recursão
    if (raiz == NULL){
        return NULL;
    }
    int status = comparar(raiz->info, buscado);
    if (status == 0){
        stats->b_cmps+=1;
        return raiz;
    }else if(status < 0){
        stats->b_cmps+=2;
        return __buscarABB(raiz->sad, buscado, comparar, stats); 
    }else{
        stats->b_cmps+=3;
        return __buscarABB(raiz->sae, buscado, comparar, stats); 
    }

}

void* buscarABB(t_abb *abb, void* buscado){
    t_stats* stats = &(abb->stats);
    stats->b_nro++; 

    TNo* no = __buscarABB(abb->raiz, buscado, abb->comparar, stats);
    return (no != NULL?no->info:NULL);

}

static void trocar(TNo* no, TNo* no2){
    void* aux = no->info;
    no->info = no2->info;
    no2->info = aux;
}


TNo * __removerABB(TNo* raiz, void* removivel, TCompararABB comparar, t_stats* stats){
    if (raiz == NULL){
        return NULL;
    }else if (comparar(raiz->info, removivel)>0){ // caminha para a SAE
        stats->r_cmps++;
        raiz->sae = __removerABB(raiz->sae, removivel, comparar);
        return raiz;
    }else if (comparar(raiz->info, removivel)<0){ // caminha para a SAD
        stats->r_cmps+=2;
        raiz->sad = __removerABB(raiz->sad, removivel, comparar);
        return raiz;
    }else{ // achou
        stats->r_cmps+=3;
        if ( (raiz->sae == NULL) &&  (raiz->sad == NULL)){
            free(raiz->info);
            free(raiz);
            return NULL;

        }else if (raiz->sae == NULL){
            raiz->sad->ancestral = raiz->ancestral;
            TNo* sad = raiz->sad;
            free(raiz->info);
            free(raiz);
            return sad;

        }else if (raiz->sad == NULL){
            raiz->sae->ancestral = raiz->ancestral;
            TNo* sae = raiz->sae;
            free(raiz->info);
            free(raiz);
            return sae;

        }else{ // Dois descendentes
            TNo* maior = raiz->sae;
            while(maior->sad!=NULL){
                maior = maior->sad;
            }
            trocar(raiz, maior);
            raiz->sae = __removerABB(raiz->sae, removivel, comparar, stats);
            return raiz;

        }

    }

}

void removerABB(t_abb *abb, void* removivel){
    t_stats* stats = &(abb->stats);
    stats->r_nro++; 

   abb->raiz = __removerABB(abb->raiz, removivel, abb->comparar, stats);    
}

static void __podarABB(TNo* raiz){
    if (raiz == NULL){
        return;
    }
    __podarABB(raiz->sae);
    __podarABB(raiz->sad);
    free(raiz->info); // precisa ajuste
    free(raiz);
}

void podarABB(t_abb* abb, void* info){
    TNo* no = __buscarABB(abb->raiz, info, abb->comparar);
    if (no != NULL){ // encontrou a info
        if (no == abb->raiz) { // poda drástica
            abb->raiz = NULL;
        } else {
            TNo* ancestral = no->ancestral;
            if (ancestral->sae == no){
                ancestral->sae = NULL;
            } else {
                ancestral->sad = NULL;
            }
        }
        __podarABB(no);
     }
}



#define MAX(a,b) (a>b?a:b)

static int __alturaABB(TNo *raiz){
    if (raiz == NULL)
        return -1;
    return MAX(__alturaABB(raiz->sae), __alturaABB(raiz->sad))+1;
}

int alturaABB(t_abb *abb){
    return __alturaABB(abb->raiz);
}

static int __tamanhoABB(TNo* raiz){
    if (raiz == NULL)
        return 0;
    return (__tamanhoABB(raiz->sae)+__tamanhoABB(raiz->sad))+1;
}

int tamanhoABB(t_abb *abb){
    return __tamanhoABB(abb->raiz);

}

static void __imprimirABB(TNo* raiz, TImprimirABB imprimir){
    if (raiz == NULL)
        return;
    __imprimirABB(raiz->sae, imprimir);
    imprimir(raiz->info);
    __imprimirABB(raiz->sad, imprimir);
}

void imprimirABB(t_abb* abb){
    __imprimirABB(abb->raiz, abb->imprimir);
}

