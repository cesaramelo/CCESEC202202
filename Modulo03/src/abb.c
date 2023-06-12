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

typedef void(*TImprimirABB)(void* info);
typedef int(*TCompararABB)(void* s1, void* s2);
typedef struct abb{
    TNo* raiz;
    TImprimirABB imprimir;
    TCompararABB comparar;
    // removerInfoNo
} t_ab;

t_ab* criarABB(TImprimirABB imprimir, TCompararABB comparar){
    t_ab* abb = malloc(sizeof(t_ab));

    abb->raiz = NULL;
    abb->imprimir = imprimir;
    abb->comparar = comparar;

    return abb;
}


static void conectaRaizSAE(TNo *raiz, TNo* sae){
    raiz->sae = sae;
    sae->ancestral = raiz;
}

static void conectaRaizSAD(TNo *raiz, TNo* sad){
    raiz->sad = sad;
    sad->ancestral = raiz;
}

static TNo* __inserirABB(TNo* raiz, void* info, TCompararABB comparar){
    //printf("Iniciou inserção \n");
    if (raiz == NULL){
        //printf("Inseriu no \n");
        TNo* novo = criar_no(raiz,info);
        return novo;
    }
    if (comparar(raiz->info, info) > 0){ // uso da propriedade ordem
        TNo* sae = __inserirABB(raiz->sae, info, comparar);
        conectaRaizSAE(raiz, sae);
    }else{
        TNo* sad = __inserirABB(raiz->sad, info, comparar);
        conectaRaizSAD(raiz, sad);
    }

    return raiz;
}

void inserirABB(t_ab *abb, void* info){

    abb->raiz = __inserirABB(abb->raiz, info, abb->comparar);
    //printf("Terminou insercao\n");

}

TNo* __buscarABB(TNo* raiz, void* buscado, TCompararABB comparar){
    // base da recursão
    if (raiz == NULL){
        return NULL;
    }
    int status = comparar(raiz->info, buscado);
    if (status == 0){
        return raiz;
    }else if(status < 0){
        return __buscarABB(raiz->sad, buscado, comparar); 
    }else{
        return __buscarABB(raiz->sae, buscado, comparar); 
    }

}

void* buscarABB(t_ab *abb, void* buscado){
    TNo* no = __buscarABB(abb->raiz, buscado, abb->comparar);
    return (no != NULL?no->info:NULL);

}

static void trocar(TNo* no, TNo* no2){
    void* aux = no->info;
    no->info = no2->info;
    no2->info = aux;
}

TNo* __removerABB(TNo* raiz, void* removivel, TCompararABB comparar){

    TNo* no = __buscarABB(raiz, removivel, comparar);
    if (no == NULL){
        return raiz;
    }else if((no->sae == NULL) && (no->sad == NULL)){
        if(no->ancestral == NULL){
            free(no->info);
            free(no);
            return NULL;
        }else{
            if (no->ancestral->sae == no){
                no->ancestral->sae = NULL;
            }else{
                no->ancestral->sad = NULL;
            }
            free(no->info);
            free(no);
            return raiz;
        }
    }else if ((no->sae == NULL) && (no->sad != NULL)){
        if (no->ancestral == NULL){
            no->sad->ancestral = NULL;
            raiz = no->sad;
            free(no->info);
            free(no);
            return raiz;
        }else{
            if (no->ancestral->sae == no){
                no->ancestral->sae = no->sad;
            }else{
                no->ancestral->sad = no->sad;
            }
            free(no->info);
            free(no);
            return raiz;
        }
    }else if ((no->sae != NULL) && (no->sad == NULL)){
        if (no->ancestral == NULL){
            no->sae->ancestral = NULL;
            raiz = no->sae;
            free(no->info);
            free(no);
            return raiz;
        }else{
            if (no->ancestral->sae == no){
                no->ancestral->sae = no->sae;
            }else{
                no->ancestral->sad = no->sae;
            }
            free(no->info);
            free(no);
            return raiz;
        }
    
    }else{ // Raiz com dois descendentes
        // encontando nó maior na SAE
        TNo* maior = no->sae;
        while(maior->sad!=NULL){
            maior = maior->sad;
        }

        trocar(no,maior);
        __removerABB(no->sae,removivel,comparar);
        return raiz;
    }
}

// TNo * __removerABB(TNo* raiz, void* removivel, TCompararABB comparar){
//     if (raiz == NULL){
//         return NULL;
//     }else if (comparar(raiz->info, removivel)>0){ // caminha para a SAE
//         raiz->sae = __removerABB(raiz->sae, removivel, comparar);
//         return raiz;
//     }else if (comparar(raiz->info, removivel)<0){ // caminha para a SAD
//         raiz->sad = __removerABB(raiz->sad, removivel, comparar);
//         return raiz;
//     }else{ // achou
//         if ( (raiz->sae == NULL) &&  (raiz->sad == NULL)){
//             free(raiz->info);
//             free(raiz);
//             return NULL;

//         }else if (raiz->sae == NULL){
//             raiz->sad->ancestral = raiz->ancestral;
//             TNo* sad = raiz->sad;
//             free(raiz->info);
//             free(raiz);
//             return sad;

//         }else if (raiz->sad == NULL){
//             raiz->sae->ancestral = raiz->ancestral;
//             TNo* sae = raiz->sae;
//             free(raiz->info);
//             free(raiz);
//             return sae;

//         }else{ // Dois descendentes
//             TNo* maior = raiz->sae;
//             while(maior->sad!=NULL){
//                 maior = maior->sad;
//             }
//             trocar(raiz, maior);
//             raiz->sae = __removerABB(raiz->sae, removivel, comparar);
//             return raiz;

//         }

//     }

// }

void removerABB(t_ab *abb, void* removivel){
   abb->raiz = __removerABB(abb->raiz, removivel, abb->comparar);    
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

void podarABB(t_ab* abb, void* info){
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

int alturaABB(t_ab *abb){
    return __alturaABB(abb->raiz);
}

static int __tamanhoABB(TNo* raiz){
    if (raiz == NULL)
        return 0;
    return (__tamanhoABB(raiz->sae)+__tamanhoABB(raiz->sad))+1;
}

int tamanhoABB(t_ab *abb){
    return __tamanhoABB(abb->raiz);

}

static void __imprimirABB(TNo* raiz, TImprimirABB imprimir){
    if (raiz == NULL)
        return;
    __imprimirABB(raiz->sae, imprimir);
    imprimir(raiz->info);
    __imprimirABB(raiz->sad, imprimir);
}

void imprimirABB(t_ab* abb){
    __imprimirABB(abb->raiz, abb->imprimir);
}


//====== USA abb

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
    if (c)
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

    t_ab *carros = criarABB(imprimir_carro, comparar_carro);

    // leitura para inserir os dados abb;
    scanf("%s", placa);    
    while(strcmp(placa,"FIM")!=0){
        scanf("%d", &hora);
        scanf("%d", &min);
        scanf("%d", &anoFab);
        t_carro* novo = criar_carro(placa, hora, min, anoFab);
       
        inserirABB(carros, novo);
       
        scanf("%s", placa);    
    }

    imprimirABB(carros);
    printf("Altura: %d\n", alturaABB(carros));
    printf("Tamanho: %d\n", tamanhoABB(carros)); 

    printf("INforme a placa: ");
    scanf("%s",placa);
    
    t_carro* buscado = buscarABB(carros, placa);
    
    imprimir_carro(buscado);

    do{
        printf("informe placa para podar:");
        scanf("%s", placa);

        podarABB(carros, placa);
        buscado = buscarABB(carros, placa);
        if (buscado == NULL){
            printf("Ramo podado\n");
        }else{
            printf("Tem erro na poda\n");
        }
    }while(strcmp(placa,"FIM")!=0);

    do{
        printf("informe placa para remoção:");
        scanf("%s", placa);

        buscado = buscarABB(carros, placa);
        if (buscado != NULL){
            removerABB(carros, placa);
            buscado = buscarABB(carros, placa);
            if (buscado == NULL){
                printf("No removido\n");
            }else{
                printf("Tem erro na remoção\n");
            }
        }else{
            printf("Conteudo não existe\n"); 
        }
    }while(strcmp(placa,"FIM")!=0);
    
    return 0;
}
