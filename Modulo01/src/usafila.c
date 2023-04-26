#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "fila.h"

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
    t_fila* estacionados = criar_fila(10);

    char placa[8]="placa";
    int hora, min;
    
    scanf("%s", placa);
    while(strcmp(placa,"FIM")!=0){
        scanf("%d",&hora);
        scanf("%d",&min);

        t_carro* novo = criar_carro(placa, hora, min);
        
        enfileirar(estacionados, novo);
        scanf("%s", placa);
    }

    t_carro* saindo = desenfileirar(estacionados);
    
    imprimir_carro(saindo);
    printf("Ocupacao: %d\n", ocupacao_fila(estacionados));

    printf("Tem vaga?:",(ocupacao_fila(estacionados)<tamanho_fila(estacionados)?"SIM":"NAO"));



    return 0;
}
