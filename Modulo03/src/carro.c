#include "carro.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
struct carro{
    char placa[8];
    int anoFabricacao;
    int hora, min;
};


t_carro* criar_carro(char placa[], int hora, int min, int anoFab){
    t_carro *c = malloc(sizeof(t_carro));

    strcpy(c->placa,placa);
    c->hora = hora;
    c->min = min;
    c->anoFabricacao = anoFab;

    return c;
}

t_carro* ler_carro(){
    t_carro* novo=malloc(sizeof(t_carro));
    scanf("%s", novo->placa);
    if (strcmp(novo->placa, "FIM")!=0){
        scanf("%d", &(novo->hora));
        scanf("%d", &(novo->min));
        scanf("%d",&(novo->anoFabricacao));
    }else{
        free(novo);
        novo=NULL;
    }
    return novo;
}

void destroy_carro(t_carro *c){
    free(c);
}

void* ler_chave_carro(char* placa){
    placa =(placa==NULL?malloc(12):placa); 
    scanf("%s", placa);
    if(strcmp(placa,"FIM")==0){
        free(placa);
        return NULL;
    }else{
        return placa;
    }
}

void imprimir_carro(t_carro* c){
    if (c)
        printf("Placa: %s %d:%d %d\n", c->placa, c->hora, c->min, c->anoFabricacao);

}

int comparar_carro(t_carro* c1, t_carro* c2){
    return strcmp(c1->placa,c2->placa);
}

