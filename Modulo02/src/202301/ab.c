#include "time.h" 
#include "stdio.h"
#include "stdlib.h"
#include "ab.h"

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

struct ab{
    t_no* raiz;
    int tamanho;
    t_comparar_ab comparar;
};

t_ab* criar_ab(t_comparar_ab comparar){
    t_ab *ab = malloc(sizeof(t_ab));
    ab->raiz = NULL;
    ab->tamanho = 0;
    ab->comparar = comparar;
    return ab;
}

#define MAX(a,b) (a>b?a:b)
static int _altura_ab(t_no* raiz){
    if (raiz != NULL){
        return MAX(_altura_ab(raiz->sae), _altura_ab(raiz->sad)) + 1;
    }else{
        return -1;
    }
}

int altura_ab(t_ab *ab){

    return _altura_ab(ab->raiz);
}

static int _tamanho_ab(t_no* no){
    if (no == NULL)
        return 0;
    return _tamanho_ab(no->sae) + _tamanho_ab(no->sad) + 1;
}

int tamanho_ab(t_ab *ab){
    return ab->tamanho;
}

void* _buscar_ab(t_no* raiz, t_comparar_ab comparar, void* chave){
    if(raiz == NULL){
        return NULL;
    }else if(comparar(raiz->info, chave) == 0){
        return raiz->info;
    }else{
        void* buscado =_buscar_ab(raiz->sae,comparar,chave);
        if (buscado == NULL){
            buscado =_buscar_ab(raiz->sad,comparar,chave);
        }
        return buscado;
    }
}

void* buscar_ab(t_ab *ab, void* chave){
    return _buscar_ab(ab->raiz, ab->comparar, chave);
}

static int sorteio(){
    static int primeira_vez = 1;
    if (primeira_vez){
        primeira_vez = 0;
        srand(time(NULL));
    }
    return (rand() % 2); // gera o valor entre [0,1]
}

static t_no* _inserir_ab(t_no* raiz, t_no* ancestral, void* info){
    if (raiz == NULL){
        return criar_no(info, ancestral);
    }else{
        
        if (sorteio()==0){ // inserir SAE 
            raiz->sae = _inserir_ab(raiz->sae, raiz, info);
        }else{ // SAD
            raiz->sad = _inserir_ab(raiz->sad, raiz, info);
        }
        return raiz;
    }
}

void inserir_ab(t_ab *ab, void* info){
    ab->raiz = _inserir_ab(ab->raiz,NULL,info);
    ab->tamanho++;
}

t_no* _podar_ab(t_no *raiz, int *tamanho){
    if(raiz==NULL){
        return;
    }
    _podar_ab(raiz->sae, tamanho);
    _podar_ab(raiz->sad, tamanho);
    free(raiz->info);
    free(raiz);
    *tamanho = *tamanho-1;
    return NULL;
}

void podar_ab(t_ab *ab, void* podavel){
    t_no* raiz = _buscar_ab(ab->raiz,ab->comparar, podavel);
    if(raiz->ancestral != NULL){
        if (raiz->ancestral->sad == raiz){
            raiz->ancestral->sad = NULL;
        }else{
            raiz->ancestral->sae = NULL;
        }
    }
//    ab->tamanho -= _tamanho_ab(raiz);
   _podar_ab(raiz, &(ab->tamanho));

}

void _imprimir_ab(t_no* raiz){
    if (raiz == NULL){
        return;
    }
    _imprimir_ab(raiz->sae);
    _imprimir_ab(raiz->sad);
    printf("%p\n", raiz->info);

}

void imprimir_ab(t_ab *ab){
    _imprimir_ab(ab->raiz);
}

