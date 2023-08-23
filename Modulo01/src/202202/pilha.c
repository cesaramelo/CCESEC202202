#include "stdlib.h"
#include "stdio.h"
#include "listase.h"
#include "pilha.h"

struct pilha{
    t_lse *elems; //container de elems
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

short empilhar(t_pilha* p, void* elem){
    short infinita = (p->max_altura<=0?1:0);
    short empilhou = 1;

    if ((p!=NULL) && ((infinita) || ((p->altura+1) <= p->max_altura))){
        inserir_inicio_lse(p->elems,elem);
        p->altura++;
    }else{
        empilhou = 0;
    }

    return empilhou;
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



