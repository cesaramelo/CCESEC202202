#include "stdlib.h"
#include "vetordinamico.h"

struct vd{
    void* *elems;
    int tamanho;
    int ocupa;
};

t_vd* criar_vd(){

    t_vd* vd = malloc(sizeof(t_vd));
    vd->tamanho=2; 
    vd->elems = malloc(sizeof(void*)*vd->tamanho);
    vd->ocupa=0;

    return vd;
}

void* acessar_vd(t_vd* vd, int pos){
    if (pos < vd->ocupa){
        return vd->elems[pos];
    }
    return NULL;
}

void inserir_vd(t_vd* vd, void* elem){
    
    if (vd->ocupa == vd->tamanho){
        vd->tamanho = vd->tamanho*2;
        vd->elems = realloc(vd->elems,sizeof(void*)*vd->tamanho);
    }
    vd->elems[vd->ocupa] = elem;
    vd->ocupa++;
}

int ocupacao_de(t_vd* vd){
    return vd->ocupa;
}




