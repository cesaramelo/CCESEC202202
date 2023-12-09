#include "time.h" 
#include "stdio.h"
#include "stdlib.h"
#include "abb.h"

typedef struct no t_no;
struct no{
    void* info;
    t_no* ancestral;
    t_no* sae;
    t_no* sad;
};

static t_no* criar_no(void* info, t_no* ancestral){
    t_no* novo = malloc(sizeof(t_no));
    novo->info = info;
    novo->sad = NULL;
    novo->sae = NULL;
    novo->ancestral = ancestral;

    return novo;
}

struct abb{
    t_no* raiz;
    int tamanho;
    t_comparar_abb comparar;
    t_destruir_abb destruir;
    t_imprimir_abb imprimir;
};


t_abb* criar_abb(t_comparar_abb comparar, t_destruir_abb destruir, t_imprimir_abb imprimir){
    t_abb *abb = malloc(sizeof(t_abb));
    abb->raiz = NULL;
    abb->tamanho = 0;
    abb->comparar = comparar;
    abb->destruir = destruir;
    abb->imprimir = imprimir;
    
    return abb;
}

#define MAX(a,b) (a>b?a:b)
static int _altura_abb(t_no* raiz){
    if (raiz != NULL){
        return MAX(_altura_abb(raiz->sae), _altura_abb(raiz->sad)) + 1;
    }else{
        return -1;
    }
}

int altura_abb(t_abb *abb){

    return _altura_abb(abb->raiz);
}

static int _tamanho_abb(t_no* no){
    if (no == NULL)
        return 0;
    return _tamanho_abb(no->sae) + _tamanho_abb(no->sad) + 1;
}

int tamanho_abb(t_abb *abb){
    return abb->tamanho;
}

void* _buscar_abb(t_no* raiz, t_comparar_abb comparar, void* chave){
    if(raiz == NULL){
        return NULL;
    }
    int status = comparar(raiz->info, chave);
    if( status == 0){
        return raiz->info;
    }else if (status > 0){
       return _buscar_abb(raiz->sae,comparar,chave);
    }else{
       return _buscar_abb(raiz->sad,comparar,chave); 
    }
}

void* buscar_abb(t_abb *abb, void* chave){
    return _buscar_abb(abb->raiz, abb->comparar, chave);
}

static t_no* _inserir_abb(t_no* raiz, t_no* ancestral, void* info, t_comparar_abb comparar){
    if (raiz == NULL){
        return criar_no(info, ancestral);
    }else{
        int status = comparar(raiz->info, info);
        if (status > 0){ // inserir SAE 
            raiz->sae = _inserir_abb(raiz->sae, raiz, info, comparar);
        }else{ // SAD
            raiz->sad = _inserir_abb(raiz->sad, raiz, info, comparar);
        }
        return raiz;
    }
}

void inserir_abb(t_abb *abb, void* info){
    abb->raiz = _inserir_abb(abb->raiz,NULL,info,abb->comparar);
    abb->tamanho++;
}

t_no* _podar_abb(t_no *raiz, int *tamanho, t_destruir_abb destruir){
    if(raiz==NULL){
        return NULL;
    }
    _podar_abb(raiz->sae, tamanho, destruir);
    _podar_abb(raiz->sad, tamanho, destruir);
    destruir(raiz->info);
    free(raiz);
    *tamanho = *tamanho-1;
    return NULL;
}

void podar_abb(t_abb *abb, void* podavel){
    t_no* raiz = _buscar_abb(abb->raiz,abb->comparar, podavel);
    if(raiz->ancestral != NULL){
        if (raiz->ancestral->sad == raiz){
            raiz->ancestral->sad = NULL;
        }else{
            raiz->ancestral->sae = NULL;
        }
    }
//    ab->tamanho -= _tamanho_ab(raiz);
   _podar_abb(raiz, &(abb->tamanho), abb->destruir);

}

void _imprimir_abb(t_no* raiz, t_imprimir_abb imprimir){
    if (raiz == NULL){
        return;
    }
    _imprimir_abb(raiz->sae, imprimir);
     imprimir(raiz->info);
    _imprimir_abb(raiz->sad, imprimir);
    
}

void imprimir_abb(t_abb *abb){
    _imprimir_abb(abb->raiz, abb->imprimir);
}

static void _trocar(t_no *n1, t_no* n2){
    void* info = n1->info;
    n1->info = n2->info;
    n2->info = info;
}

static t_no* _remover_abb(t_no* raiz, t_comparar_abb comparar, t_destruir_abb destruir, void *buscado){
    if (raiz == NULL){
        return NULL;
    }
    int status = comparar(raiz->info, buscado);
    if(status > 0){
        raiz->sae = _remover_abb(raiz->sae,comparar, destruir,buscado);
    }else if(status < 0){
        raiz->sad = _remover_abb(raiz->sad, comparar, destruir, buscado);
    }else{
        if ((raiz->sae == NULL) && (raiz->sad == NULL)){ // folha
            destruir(raiz->info);
            free(raiz);
            return NULL;
        }else if (raiz->sae == NULL){ //descendente dir
            raiz->sad->ancestral = raiz->ancestral;
            t_no* sad = raiz->sad;
            destruir(raiz->info);
            free(raiz);

            raiz = sad;
        } else if(raiz->sad == NULL){ //descendente esq
            raiz->sae->ancestral = raiz->ancestral;
            t_no* sae = raiz->sae;
            destruir(raiz->info);
            free(raiz);

            raiz = sae;
        }else{ // tem descendentes sae sad
            t_no* maior = raiz->sae;
            while(maior->sad != NULL){
                maior = maior->sad;
            } 
            _trocar(raiz, maior);
            raiz->sae = _remover_abb(raiz->sae,comparar,destruir,buscado);
        }
    }
    return raiz;
}

void remover_abb(t_abb *abb, void* chave){
    abb->raiz = _remover_abb(abb->raiz, abb->comparar, abb->destruir, chave);
}