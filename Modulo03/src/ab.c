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
typedef int(*TCompararAB)(void* s1, void* s2);
typedef struct ab{
    TNo* raiz;
    TImprimirAB imprimir;
    TCompararAB comparar;
    // removerInfoNo
} t_ab;

t_ab* criarAB(TImprimirAB imprimir, TCompararAB comparar){
    t_ab* ab = malloc(sizeof(t_ab));

    ab->raiz = NULL;
    ab->imprimir = imprimir;
    ab->comparar = comparar;

    return ab;
}


static void conectaRaizSAE(TNo *raiz, TNo* sae){
    raiz->sae = sae;
    sae->ancestral = raiz;
}

static void conectaRaizSAD(TNo *raiz, TNo* sad){
    raiz->sad = sad;
    sad->ancestral = raiz;
}

static TNo* __inserirAB(TNo* raiz, void* info){
    //printf("Iniciou inserção \n");
    if (raiz == NULL){
        //printf("Inseriu no \n");
        TNo* novo = criar_no(raiz,info);
        return novo;
    }
    if ((rand()%2) == 1){ // relação aleatória
        TNo* sae = __inserirAB(raiz->sae, info);
        conectaRaizSAE(raiz, sae);
    }else{
        TNo* sad = __inserirAB(raiz->sad, info);
        conectaRaizSAD(raiz, sad);
    }

    return raiz;
}

void inserirAB(t_ab *ab, void* info){

    ab->raiz = __inserirAB(ab->raiz, info);
    //printf("Terminou insercao\n");

}

#define MAX(a,b) (a>b?a:b)

static int __alturaAB(TNo *raiz){
    if (raiz == NULL)
        return -1;
    return MAX(__alturaAB(raiz->sae), __alturaAB(raiz->sad))+1;
}

int alturaAB(t_ab *ab){
    return __alturaAB(ab->raiz);
}

static int __tamanhoAB(TNo* raiz){
    if (raiz == NULL)
        return 0;
    return (__tamanhoAB(raiz->sae)+__tamanhoAB(raiz->sad))+1;
}

int tamanhoAB(t_ab *ab){
    return __tamanhoAB(ab->raiz);

}

static void __imprimirAB(TNo* raiz, TImprimirAB imprimir){
    if (raiz == NULL)
        return;
    __imprimirAB(raiz->sae, imprimir);
    imprimir(raiz->info);
    __imprimirAB(raiz->sad, imprimir);
}

void imprimirAB(t_ab* ab){
    __imprimirAB(ab->raiz, ab->imprimir);
}

TNo* __buscarAB(TNo* raiz, void* buscado, TCompararAB comparar){
    // base da recursão
    if (raiz == NULL){
        return NULL;
    }else if( comparar(raiz->info, buscado) == 0){
        return raiz;
    }

    // caminhar na AB
    TNo* no = __buscarAB(raiz->sae, buscado, comparar);
    if (no == NULL){
        no = __buscarAB(raiz->sad, buscado, comparar);
    }
    return no;
}

void* buscarAB(t_ab *ab, void* buscado){
    TNo* no = __buscarAB(ab->raiz, buscado, ab->comparar);
    return (no != NULL?no->info:NULL);

}


static void __podarAB(TNo* raiz){
    if (raiz == NULL){
        return;
    }
    __podarAB(raiz->sae);
    __podarAB(raiz->sad);
    free(raiz->info); // precisa ajuste
    free(raiz);
}

void podarAB(t_ab* ab, void* info){
    TNo* no = __buscarAB(ab->raiz, info, ab->comparar);
    if (no != NULL){ // encontrou a info
        if (no == ab->raiz) { // poda drástica
            ab->raiz = NULL;
        } else {
            TNo* ancestral = no->ancestral;
            if (ancestral->sae == no){
                ancestral->sae = NULL;
            } else {
                ancestral->sad = NULL;
            }
        }
        __podarAB(no);
     }
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

int comparar_carro(t_carro* c1, t_carro* c2){
    return strcmp(c1->placa,c2->placa);
}

int main(int argc, char const *argv[])
{
    char placa[9];
    int hora, min, anoFab;

    srand(time(NULL));

    t_ab *carros = criarAB(imprimir_carro, comparar_carro);

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

    printf("INforme a placa: ");
    scanf("%s",placa);
    
    t_carro* buscado = buscarAB(carros, placa);
    
    imprimir_carro(buscado);

    do{
        printf("informe placa para podar:");
        scanf("%s", placa);

        podarAB(carros, placa);
        buscado = buscarAB(carros, placa);
        if (buscado == NULL){
            printf("Ramo podado\n");
        }else{
            printf("Tem erro na poda\n");
        }
    }while(strcmp(placa,"FIM")!=0);

    return 0;
}
