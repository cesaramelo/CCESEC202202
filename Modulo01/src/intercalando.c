#include "stdio.h"


void intercalar(double vetor[], int k, int l, int m){
    double aux[m-k+1];
    int ki = k;
    int mi = l+1;
    int n=0;
    while( (ki<=l) && (mi<=m) ){
        if (vetor[ki]<vetor[mi]){
            aux[n] = vetor[ki];
            ki++;
        }else{
            aux[n]=vetor[mi];
            mi++;
        }    
        n++;
    }
    while(ki<=l){
        aux[n] = vetor[ki];
        n++; ki++;
    }
    while(mi<=m){
        aux[n] = vetor[mi];
        n++;mi++;
    }
    for(int i=0;i<m-k+1;i++){
        vetor[k+i]=aux[i];
    }

}


int main(int argc, char const *argv[])
{
    double notas[] = {8.0,9.5,10.0,7.0,8.5,9.0};
    int tam=6;
    intercalar(notas, 0, 2, 5);
    for(int i=0;i<tam;i++){
        printf("%.2lf ",notas[i]);
    }
    printf("\n");
    return 0;

}
