#include "stdlib.h"
#include "vetordinamico.h"

typedef struct elem{
    int chave;
    void* carga;
}t_elem_de;

static t_elem_de* criar_elem(int chave, void* carga){
    t_elem_de *e = malloc(sizeof(t_elem_de));
    e->chave =chave;
    e->carga = carga;

    return e;
}

typedef struct dicio_estatico{
    t_vd* vd;
    
}t_de;

t_de* criar_dicio_estatico(){
    t_de* de = malloc(sizeof(t_de));

    de->vd = criar_vd();

    return de;
}

void inserir_de(t_de* de, int chave, void* carga){

    inserir_vd(de->vd, criar_elem(chave,carga) );

}

void* buscar_de(t_de *de, int chave){
    //busca_binaria
    int lim_i = 0;
    int lim_s = ocupacao_vd(de->vd);

    while(lim_i<=lim_s){
        int pos = (lim_i+lim_s)/2;
        t_elem_de* e = acessar_vd(de->vd, pos);
        if (e->chave == chave){
            return e->carga;
        }else if(e->chave > chave){
            lim_s = pos-1;
        }else{
            lim_i = pos+1;
        }
    }
    return NULL;
}