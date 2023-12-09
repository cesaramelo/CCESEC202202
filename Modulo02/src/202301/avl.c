#include "time.h" 
#include "stdio.h"
#include "stdlib.h"
#include "avl.h"

typedef struct no t_no;
struct no{
    void* info;
    t_no* ancestral;
    t_no* sae;
    t_no* sad;
    int fb;
};

static t_no* criar_no(void* info, t_no* ancestral){
    t_no* novo = malloc(sizeof(t_no));
    novo->info = info;
    novo->sad = NULL;
    novo->sae = NULL;
    novo->ancestral = ancestral;
    novo->fb = 0;

    return novo;
}

struct avl{
    t_no* raiz;
    int tamanho;
    t_comparar_avl comparar;
    t_destruir_avl destruir;
    t_imprimir_avl imprimir;
};


t_avl* criar_avl(t_comparar_avl comparar, t_destruir_avl destruir, t_imprimir_avl imprimir){
    t_avl *avl = malloc(sizeof(t_avl));
    avl->raiz = NULL;
    avl->tamanho = 0;
    avl->comparar = comparar;
    avl->destruir = destruir;
    avl->imprimir = imprimir;
    
    return avl;
}

#define MAX(a,b) (a>b?a:b)
static int _altura_avl(t_no* raiz){
    if (raiz != NULL){
        return MAX(_altura_avl(raiz->sae), _altura_avl(raiz->sad)) + 1;
    }else{
        return -1;
    }
}

int altura_avl(t_avl *avl){

    return _altura_avl(avl->raiz);
}

static int _tamanho_avl(t_no* no){
    if (no == NULL)
        return 0;
    return _tamanho_avl(no->sae) + _tamanho_avl(no->sad) + 1;
}

int tamanho_avl(t_avl *avl){
    return avl->tamanho;
}



void* _buscar_avl(t_no* raiz, t_comparar_avl comparar, void* chave){
    if(raiz == NULL){
        return NULL;
    }
    int status = comparar(raiz->info, chave);
    if( status == 0){
        return raiz->info;
    }else if (status > 0){
       return _buscar_avl(raiz->sae,comparar,chave);
    }else{
       return _buscar_avl(raiz->sad,comparar,chave); 
    }
}

void* buscar_avl(t_avl *avl, void* chave){
    return _buscar_avl(avl->raiz, avl->comparar, chave);
}


static int _calcular_fb(t_no* raiz){
    return (_altura_avl(raiz->sad) - _altura_avl(raiz->sae));
}

static t_no* _RSD(t_no* A, t_no* B){
    A->sae = B->sad;
    B->sad = A;

    B->ancestral = A->ancestral;
    A->ancestral = B;

    if (A->sae)
        A->sae->ancestral = A;

    return B;
}

static t_no* _RSE(t_no* A, t_no* B){
    A->sad = B->sae;
    B->sae = A;

    B->ancestral = A->ancestral;
    A->ancestral = B;

    if (A->sad)
        A->sad->ancestral = A;

    return B;
}


static t_no* _inserir_avl(t_no* raiz, t_no* ancestral, void* info, t_comparar_avl comparar){
    if (raiz == NULL){
        return criar_no(info, ancestral);
    }else{
        int status = comparar(raiz->info, info);
        if (status > 0){ // inserir SAE 
            raiz->sae = _inserir_avl(raiz->sae, raiz, info, comparar);
            int fb = _calcular_fb(raiz);
            if (fb == -2){
                if (_calcular_fb(raiz->sae) == 1) {
                    // rotação dupla para esquerda
                    t_no* sad = _RSE(raiz->sae, raiz->sae->sad);
                    raiz = _RSD(raiz,sad); 
                } else {
                    // rotação para direita
                    raiz = _RSD(raiz, raiz->sae);
                }
            }
        } else { // SAD
            raiz->sad = _inserir_avl(raiz->sad, raiz, info, comparar);
            int fb = _calcular_fb(raiz);
            if (fb == 2){
                if (_calcular_fb(raiz->sad) == -1) {
                    // rotação dupla para direita
                    t_no* sae = _RSD(raiz->sad, raiz->sad->sae);
                    raiz = _RSE(raiz,sae);
                }else{
                    // rotacao para esquerda
                    raiz = _RSE(raiz, raiz->sad);
                }
            }
        }
        return raiz;
    }
}

void inserir_avl(t_avl *avl, void* info){
    avl->raiz = _inserir_avl(avl->raiz,NULL,info,avl->comparar);
    avl->tamanho++;
}


static void _trocar(t_no *n1, t_no* n2){
    void* info = n1->info;
    n1->info = n2->info;
    n2->info = info;
}

static t_no* _remover_avl(t_no* raiz, t_comparar_avl comparar, t_destruir_avl destruir, void *buscado){
    if (raiz == NULL){
        return NULL;
    }
    int status = comparar(raiz->info, buscado);
    if(status > 0){
        raiz->sae = _remover_avl(raiz->sae,comparar, destruir,buscado);
        // revisitar FB

    }else if(status < 0){        
        raiz->sad = _remover_avl(raiz->sad, comparar, destruir, buscado);
        // Revisitar FB

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
            raiz->sae = _remover_avl(raiz->sae,comparar,destruir,buscado);
            // Revisitar o FB
        }
    }
    return raiz;
}

void remover_avl(t_avl *avl, void* chave){
    avl->raiz = _remover_avl(avl->raiz, avl->comparar, avl->destruir, chave);
}

t_no* _podar_avl(t_no *raiz, int *tamanho, t_destruir_avl destruir){
    if(raiz==NULL){
        return NULL;
    }
    _podar_avl(raiz->sae, tamanho, destruir);
    _podar_avl(raiz->sad, tamanho, destruir);
    destruir(raiz->info);
    free(raiz);
    *tamanho = *tamanho-1;
    return NULL;
}

void podar_avl(t_avl *avl, void* podavel){
    t_no* raiz = _buscar_avl(avl->raiz,avl->comparar, podavel);
    if(raiz->ancestral != NULL){
        if (raiz->ancestral->sad == raiz){
            raiz->ancestral->sad = NULL;
        }else{
            raiz->ancestral->sae = NULL;
        }
    }
//    ab->tamanho -= _tamanho_ab(raiz);
   _podar_avl(raiz, &(avl->tamanho), avl->destruir);

}

void _imprimir_avl(t_no* raiz, t_imprimir_avl imprimir){
    if (raiz == NULL){
        return;
    }
    _imprimir_avl(raiz->sae, imprimir);
     printf("raiz: %p sae: %p ancestral: %p sad: %p \n", raiz, raiz->sae, raiz->ancestral, raiz->sad);
     imprimir(raiz->info);
    _imprimir_avl(raiz->sad, imprimir);
    
}

void imprimir_avl(t_avl *avl){
    _imprimir_avl(avl->raiz, avl->imprimir);
}


