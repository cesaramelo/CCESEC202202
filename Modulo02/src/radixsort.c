#include "stdio.h"
#include "math.h"
#include "ordenacao.h"
//#include "../../Modulo01/src/listase.h"

void contagem_rs_mins(void* vetor_A[], int tam, int d, TLerIdRadixSort ler_id){
    //int tam_c = maior(vetor_A, tam);

    void* vetor_B[tam];
    int vetor_C[10] = {0};

    int denominador = pow(10,d);
    for(int i=0;i<tam;i++){
        int k = (int)(ler_id(vetor_A[i])/denominador) % 10; 
        //printf("---- K=%d %d\n",k, vetor_A[i]);
        vetor_C[k] = vetor_C[k] + 1;
    }

    for(int i=1;i<10;i++){
        vetor_C[i] = vetor_C[i] + vetor_C[i-1];
    }
    
    for(int i=tam-1;i>=0;i--){
        int k = (int)(ler_id(vetor_A[i])/denominador)%10;
        int j = vetor_C[k];
        vetor_B[j-1] = vetor_A[i];
        vetor_C[k] = vetor_C[k] - 1;
    }

    for(int i=0;i<tam;i++){
        vetor_A[i] = vetor_B[i];
        //printf("->%d\n", vetor_A[i]);
    }
}

void distribuindo(void* vetor_A[], int tam, int d, TLerIdRadixSort ler_id){
    //int tam_c = maior(vetor_A, tam);

    void* vetor_B[tam];

    //t_lse* caixas[10];

    for(int i=0;i<10;i++){
        //caixas[i] = criar_lse(NULL, NULL);
    }

    // Para ser implementado

    // usar a inserir no final

    // remover no inicio

    // reconstruir os vetor original

}

void radix_sort(void* vetor[], int tam, int digs, TLerIdRadixSort ler_id){
    for(int i=0;i<digs;i++){
        contagem_rs_mins(vetor, tam, i, ler_id);
    }
}




