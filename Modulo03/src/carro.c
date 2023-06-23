//====== USA abb
#include "carro.h"

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

