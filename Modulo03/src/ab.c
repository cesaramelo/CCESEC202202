#include "stdio.h"

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

conectaRaizSAE(TNo *raiz, TNo* sae){
    raiz->sae = sae;
    sae->ancestral = raiz;
}

conectaRaizSAD(TNo *raiz, TNo* sad){
    raiz->sad = sad;
    sad->ancestral = raiz;
}

TNo* inserirAB(TNo* raiz, void* info){
    if (raiz == NULL){
        TNo* novo = criar_no(raiz,info);
        return novo;
    }
    if ((rand()%2) == 1){ // relação aleatória
        TNo* sae = inserirAB(raiz->sae, info);
        conectaRaizSAE(raiz, sae);
    }else{
        TNo* sad = inserirAB(raiz->sad, info);
        concataRaizSAD(raiz->sad, sad);
    }
}

#define MAX(a,b) (a>b?a:b)

int alturaAB(TNo *raiz){
    if (raiz == NULL)
        return -1;
    return MAX(alturaAB(raiz->sae), alturaAB(raiz->sad))+1;
}

int tamanhoAB(TNo* raiz){
    if (raiz == NULL)
        return 0;
    return (tamanhoAB(raiz->sae)+tamanhoAB(raiz->sad))+1;
}

imprimirAB(TNo* raiz){
    if (raiz == NULL)
        return;
    imprimirAB(raiz->sae);
    printf("%p",raiz->info);
    imprimirAB(raiz->sad);
}

//====== USA AB

typedef struct carro{
    char placa[8];
    int hora, min;
}t_carro;

t_carro* criar_carro(char placa[], int hora, int min){
    t_carro *c = malloc(sizeof(t_carro));

    strcpy(c->placa,placa);
    c->hora = hora;
    c->min = min;

    return c;
}

void destroy_carro(t_carro *c){
    free(c);
}

void imprimir_carro(t_carro* c){

    printf("Placa: %s %d:%d\n", c->placa, c->hora, c->min);

}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    // leitura para inserir os dados AB;

    //imprimirAB(raiz);
    //alturaAB(raiz);
    //tamanhoAB(raiz->sad);
    return 0;
}
