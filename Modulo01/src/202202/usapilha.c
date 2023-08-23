#include "stdio.h"
#include "stdlib.h"
#include "pilha.h"

//
// Espaço da Solução
//
typedef struct {
    int capacidade;
    int tipo;
}t_xicara;

t_xicara* criar_xicara(int capacidade, int tipo){
    t_xicara *x = malloc(sizeof(t_xicara));
    x->capacidade = capacidade;
    x->tipo = tipo;
    return x;
}

typedef struct {
    int tipo; // 1-sobremesa, 2-sopa, 3-casocontrario 
    int lava_na_maquina; // 1 - sim 2 - Nao
    int diametro; // cm
}t_prato;

t_prato* criar_prato(int tipo, int lava_na_maquina, int diametro){
    t_prato* p = malloc(sizeof(t_prato));
    p->tipo = tipo;
    p->diametro = diametro;
    p->lava_na_maquina = lava_na_maquina;

    return p;
}


int main(int argc, char const *argv[])
{
    t_pilha *pratos = criar_pilha(0); // pilha infinita
    t_pilha *xicaras = criar_pilha(5); // pilha de altura max = 5

    for(int i=1;i<10;i++){
        empilhar(pratos, criar_prato(1,1,20));
    }

    t_xicara* x;
    int i=0;
    do{
        x = criar_xicara(150,1);
        i++;
    }while(empilhar(xicaras, x));
    free(x);
    i--;

    printf("altura pratos: %d", altura_pilha(pratos));
    printf("altura xicaras: %d", altura_pilha(xicaras));

    t_prato* p = desempilhar(pratos);
    // imprimir_prato(p);
    x = desempilhar(xicaras);
    // imprimir_xicara(x);

    return 0;
}
