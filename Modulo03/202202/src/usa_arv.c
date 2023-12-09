#include "stdio.h"
#include "stdlib.h"
#include "./arv_bb.h"
//#include "arv_avl.h"
//#include "arv_red.h"
#include "carro.h"
//#include "medidas.h"

int comparar_dado(void* s1, void* s2){
    
    //return comparar_medida(s1,s2);
    return comparar_carro(s1, s2);
}

// ler os dados
void* ler_dado(){
    void* novo=NULL;
    //novo = ler_medida();
    
    novo = ler_carro();

    return novo;
}

void* ler_chave_dado(void* chave){

    //chave = ler_chave_medida(chave);

    chave = ler_chave_carro(chave);
    return chave;
}

void destroy_dado(void* s1){

    (s1!=NULL?free(s1):NULL);
}

void imprimir_dado(void* dado){

    //imprimir_medida(dado);
    imprimir_carro(dado);
}


int main(int argc, char const *argv[])
{

    t_abb *arv = criarABB(imprimir_dado, comparar_dado);

    // inserir dados na abb;
    void* novo = ler_dado();    
    while(novo!=NULL){       
        inserirABB(arv, novo);
       
        novo = ler_dado();   
    }
    estatisticaABB(arv);

    // altura e tamanho
    printf("Altura: %d\n", alturaABB(arv));
    printf("Tamanho: %d\n", tamanhoABB(arv)); 

    // buscar dados
    void* chave = ler_chave_dado(NULL);
    while(chave!=NULL){

        void* buscado = buscarABB(arv, chave);
        imprimir_dado(buscado);
        chave = ler_chave_dado(chave);
    }
    estatisticaABB(arv);

    // remover dados
    chave = ler_chave_dado(NULL);
    while(chave!=NULL){

        removerABB(arv, chave);
        
        chave = ler_chave_dado(chave);
    }
    estatisticaABB(arv);
    
    return 0;
}
