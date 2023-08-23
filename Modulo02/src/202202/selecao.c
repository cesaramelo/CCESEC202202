#include "stdio.h"

void selecao(int vetor[], int tam){
    for(int i=0;i<tam;i++){
        int imenor=i;
        for(int j=i+1;j<tam;j++){
            if (vetor[j]<vetor[imenor]){
                imenor = j;
            }
        }
        trocar(vetor,i,imenor);
    }
}

void bolha(int vetor[], int tam){
    for(int i=tam-1;i>=1;i--){
        for(int j=i-1;j>=0;j--){
            if (vetor[j]>vetor[j+1]){
                trocar(vetor,j,j+1);
            }
        }
    }
}
