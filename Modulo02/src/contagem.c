#include "stdio.h"
#include "math.h"
#include "ordenacao.h"

void contagem(void* vetor_A[], int tam, int tam_c, TLerIdContagem ler_id){
    //int tam_c = maior(vetor_A, tam);

    void* vetor_B[tam];
    int vetor_C[tam_c];

    for(int i=0;i<tam_c;i++){
        vetor_C[i]=0;
    }

    for(int i=0;i<tam;i++){
        int k = ler_id(vetor_A[i]);
        vetor_C[k] = vetor_C[k] + 1;
    }

    for(int i=1;i<tam_c;i++){
        vetor_C[i] = vetor_C[i] + vetor_C[i-1];
    }
    
    for(int i=tam-1;i>=0;i--){
        int k = ler_id(vetor_A[i]);
        int j = vetor_C[k];
        vetor_B[j-1] = vetor_A[i];
        vetor_C[k] = vetor_C[k] - 1;
    }

    for(int i=0;i<tam;i++){
        vetor_A[i] = vetor_B[i];
    }
}



