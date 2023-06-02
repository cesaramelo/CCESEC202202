#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

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

typedef void(*TImprimirAB)(void* info);
typedef struct ab{
    TNo* raiz;
    TImprimirAB imprimir;
    // removerInfoNo
} t_ab;

t_ab* criarAB(TImprimirAB imprimir){
    t_ab* ab = malloc(sizeof(t_ab));

    ab->raiz = NULL;
    ab->imprimir = imprimir;

    return ab;
}


void conectaRaizSAE(TNo *raiz, TNo* sae){
    raiz->sae = sae;
    sae->ancestral = raiz;
}

void conectaRaizSAD(TNo *raiz, TNo* sad){
    raiz->sad = sad;
    sad->ancestral = raiz;
}

static TNo* _inserirAB(TNo* raiz, void* info){
    //printf("Iniciou inserção \n");
    if (raiz == NULL){
        //printf("Inseriu no \n");
        TNo* novo = criar_no(raiz,info);
        return novo;
    }
    if ((rand()%2) == 1){ // relação aleatória
        TNo* sae = _inserirAB(raiz->sae, info);
        conectaRaizSAE(raiz, sae);
    }else{
        TNo* sad = _inserirAB(raiz->sad, info);
        conectaRaizSAD(raiz, sad);
    }

    return raiz;
}

void inserirAB(t_ab *ab, void* info){

    ab->raiz = _inserirAB(ab->raiz, info);
    //printf("Terminou insercao\n");

}

#define MAX(a,b) (a>b?a:b)

static int _alturaAB(TNo *raiz){
    if (raiz == NULL)
        return -1;
    return MAX(_alturaAB(raiz->sae), _alturaAB(raiz->sad))+1;
}

int alturaAB(t_ab *ab){
    return _alturaAB(ab->raiz);
}

static int _tamanhoAB(TNo* raiz){
    if (raiz == NULL)
        return 0;
    return (_tamanhoAB(raiz->sae)+_tamanhoAB(raiz->sad))+1;
}

int tamanhoAB(t_ab *ab){
    return _tamanhoAB(ab->raiz);

}

static void _imprimirAB(TNo* raiz, TImprimirAB imprimir){
    if (raiz == NULL)
        return;
    _imprimirAB(raiz->sae, imprimir);
    imprimir(raiz->info);
    _imprimirAB(raiz->sad, imprimir);
}

void imprimirAB(t_ab* ab){
    _imprimirAB(ab->raiz, ab->imprimir);
}
//====== USA AB

typedef struct carro{
    char placa[8];
    int anoFabricacao;
    int hora, min;
}t_carro;

t_carro* criar_carro(char placa[], int hora, int min, int anoFab){
    t_carro *c = malloc(sizeof(t_carro));

    strcpy(c->placa,placa);
    c->hora = hora;
    c->min = min;
    c->anoFabricacao = anoFab;

    return c;
}

void destroy_carro(t_carro *c){
    free(c);
}

void imprimir_carro(t_carro* c){

    printf("Placa: %s %d:%d %d\n", c->placa, c->hora, c->min, c->anoFabricacao);

}

int main(int argc, char const *argv[])
{
    char placa[9];
    int hora, min, anoFab;

    srand(time(NULL));

    t_ab *carros = criarAB(imprimir_carro);

    // leitura para inserir os dados AB;
    scanf("%s", placa);    
    while(strcmp(placa,"FIM")!=0){
        scanf("%d", &hora);
        scanf("%d", &min);
        scanf("%d", &anoFab);
        t_carro* novo = criar_carro(placa, hora, min, anoFab);
       
        inserirAB(carros, novo);
       
        scanf("%s", placa);    
    }

    imprimirAB(carros);
    printf("Altura: %d\n", alturaAB(carros));
    printf("Tamanho: %d\n", tamanhoAB(carros)); 

    return 0;
}
