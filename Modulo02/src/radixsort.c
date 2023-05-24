#include "stdio.h"
#include "math.h"


void contagem_rs_mins(int vetor_A[], int tam, int d){
    //int tam_c = maior(vetor_A, tam);

    int vetor_B[tam];
    int vetor_C[10] = {0};

    for(int i=0;i<tam;i++){
        int k = (int)(vetor_A[i]/pow(10,d=1)) % 10; 
        //printf("---- K=%d %d\n",k, vetor_A[i]);
        vetor_C[k] = vetor_C[k] + 1;
    }

    for(int i=1;i<10;i++){
        vetor_C[i] = vetor_C[i] + vetor_C[i-1];
    }
    
    for(int i=tam-1;i>=0;i--){
        int k = (int)(vetor_A[i]/pow(10,d))%10;
        int j = vetor_C[k];
        vetor_B[j-1] = vetor_A[i];
        vetor_C[k] = vetor_C[k] - 1;
    }

    for(int i=0;i<tam;i++){
        vetor_A[i] = vetor_B[i];
        //printf("->%d\n", vetor_A[i]);
    }
}


void contagem_rs_maxs(int vetor_A[], int tam, int d){
    //int tam_c = maior(vetor_A, tam);

    int vetor_B[tam];
    int vetor_C[10] = {0};

    for(int i=0;i<tam;i++){
        int k = (int)(vetor_A[i]/pow(10,d)) % 10; 
        printf("---- K=%d %d\n",k, vetor_A[i]);
        vetor_C[k] = vetor_C[k] + 1;
    }

    for(int i=1;i<10;i++){
        vetor_C[i] = vetor_C[i] + vetor_C[i-1];
    }
    
    for(int i=0;i<tam;i++){
        int k = (int)(vetor_A[i]/pow(10,d))%10;
        int j = vetor_C[k];
        vetor_B[j-1] = vetor_A[i];
        vetor_C[k] = vetor_C[k] - 1;
    }

    for(int i=0;i<tam;i++){
        vetor_A[i] = vetor_B[i];
        printf("->%d\n", vetor_A[i]);
    }
}


void radixsort(int vetor[], int tam, int digs){
    for(int i=0;i<digs;i++){
        //contagem_rs_mins(vetor,tam,i);
        contagem_rs_maxs(vetor,tam,digs-i-1);
    }
}


int main(int argc, char const *argv[])
{
    int vetor[] = {3,3,7,2,7,4,7,6,4,8,8,3,0,2,1,0,2};
    int vetor_rs[] = {30,15,10,19,23,32,21};

    radixsort( vetor_rs, 7, 2);
    
    for(int i=0;i<7;i++){
        printf("%d ", vetor_rs[i]);
    }
    printf("\n");

    return 0;
}


