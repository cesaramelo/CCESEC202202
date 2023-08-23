#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "heap.h"

typedef struct {
    int chave;
    char msg[100];
}t_carga;

int comparar_carga(void* c1, void* c2){
    t_carga *cc1=c1;
    t_carga *cc2=c2;
    return (cc1->chave - cc2->chave);
}

t_carga* criar_carga(int chave, char* msg){
    t_carga* c= malloc(sizeof(t_carga));
    c->chave=chave;
    strcpy(c->msg,msg);

    return c;
}

int main(){
    t_heap *h = criar_heap(11, comparar_carga);
    for (int i=0;i<10;i++){

        t_carga *c = criar_carga(i, "mesma msg");
        printf("%p %d\n", c, c->chave);
        inserir_heap(h, c);
    }
    for (int i=0;i<10;i++){
        t_carga *c = remover_heap(h);
        printf("%d %s\n",c->chave, c->msg);
    }
    return 0;
}