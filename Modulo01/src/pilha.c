#include "stdlib.h"
#include "stdio.h"
#include "listase.h"

typedef struct pilha t_pilha;
struct pilha{
    t_lse *elems;
    int max_altura;
    int altura;
};

t_pilha* criar_pilha(int max_altura){
    t_pilha *p = malloc(sizeof(t_pilha));
    p->altura = 0;
    p->max_altura = max_altura; // se <=0 pilha de altura infinita
    p->elems = criar_lse(NULL,NULL);

    return p;
}

short empilhar(t_pilha*p, void* elem){
    short infinita = (p->max_altura<=0?1:0);
    short inseriu = 1;

    if ((p!=NULL) && ((infinita) || ((p->altura+1) <= p->max_altura))){
        inserir_inicio_lse(p->elems,elem);
        p->altura++;
    }else{
        inseriu = 0;
    }

    return inseriu;
}

void* desempilhar(t_pilha* p){
    void* elem = NULL;
    if ((p!=NULL) && (p->altura>=1)){
        elem = remover_inicio_lse(p->elems);
        p->altura--;
    }
    return elem;
}

void* topo_pilha(t_pilha *p){
    if((p!=NULL) && (p->altura>0))
        return acessar_lse(p->elems,1);
    else
        return NULL; 
}

int altura_pilha(t_pilha* p){

    return (p!=NULL?p->altura:-1);

}

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
    t_pilha *pratos = criar_pilha(0);
    t_pilha *xicaras = criar_pilha(5);

    for(int i=1;i<10;i++){
        empilhar(pratos, criar_prato(1,1,20));
        empilhar(pratos, criar_prato(1,1,20));
    }

    t_xicara* x;
    int i=0;

    do{
        x = criar_xicara(150,1);
        i++;
    }while(!empilhar(xicaras, x));
    free(x);
    i--;

    printf("altura pratos: %d", altura_pilha(pratos));
    printf("altura xicaras: %d", altura_pilha(xicaras));

    t_prato* p = desempilhar(pratos);
    x = desempilhar(xicaras);

    return 0;
}
