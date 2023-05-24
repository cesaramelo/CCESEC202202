#include "stdio.h"
#include "math.h"


void contagem(int vetor_A[], int tam, int tam_c){
    //int tam_c = maior(vetor_A, tam);

    int vetor_B[tam];
    int vetor_C[tam_c];

    for(int i=0;i<tam_c;i++){
        vetor_C[i]=0;
    }

    for(int i=0;i<tam;i++){
        vetor_C[vetor_A[i]] = vetor_C[vetor_A[i]] + 1;
    }

    for(int i=1;i<tam_c;i++){
        vetor_C[i] = vetor_C[i] + vetor_C[i-1];
    }
    
    for(int i=tam-1;i>=0;i--){
        int j = vetor_C[vetor_A[i]];
        vetor_B[j-1] = vetor_A[i];
        vetor_C[vetor_A[i]] = vetor_C[vetor_A[i]] - 1;
    }

    for(int i=0;i<tam;i++){
        vetor_A[i] = vetor_B[i];
    }
}


int main(int argc, char const *argv[])
{
    int vetor[] = {3,3,7,2,7,4,7,6,4,8,8,3,0,2,1,0,2};

    contagem(vetor, 17, 9);
    for(int i=0;i<17;i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}


