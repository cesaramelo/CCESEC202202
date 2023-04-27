#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "filacomprioridade.h"

typedef struct carro{
    char placa[9];
    int hora, min;
}t_carro;

t_carro* criar_carro(char placa[], int hora, int min){
    t_carro *c = malloc(sizeof(t_carro));

    strcpy(c->placa,placa);
    c->hora = hora;
    c->min = min;

    return c;
}

int compararCarro(void* c1, void* c2){
    t_carro* cc1 = c1;
    t_carro* cc2 = c2;

    return strcmp(cc2->placa, cc1->placa);
}

void destroy_carro(t_carro *c){
    free(c);
}

void imprimir_carro(t_carro* c){

    printf("Placa: %s %d:%d\n", c->placa, c->hora, c->min);

}

int main(int argc, char const *argv[])
{
    t_fila_cp* estacionados = criar_fila_cp(-1, compararCarro);

    char placa[9]="placa";
    int hora, min;
    
    scanf("%s", placa);
    while(strcmp(placa,"FIM")!=0){
        scanf("%d",&hora);
        scanf("%d",&min);

        t_carro* novo = criar_carro(placa, hora, min);
        
        enfileirarCP(estacionados, novo);
        scanf("%s", placa);
    }

    int qtd_vagas;
    do{
        t_carro* saindo = desenfileirarCP(estacionados);
    
        imprimir_carro(saindo);
        printf("Ocupacao: %d\n", ocupacao_FCP(estacionados));
        
        qtd_vagas = (tamanho_FCP(estacionados)-ocupacao_FCP(estacionados));

        printf("Quantas vagas?: %d\n",qtd_vagas);

    }while(qtd_vagas!=tamanho_FCP(estacionados));

    return 0;
}
