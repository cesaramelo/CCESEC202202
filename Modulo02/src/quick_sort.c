#include "stdio.h"
#include "quick_sort.h"

static void trocar(void* elem[], int i, int j){
    void* aux = elem[i];
    elem[i] = elem[j];
    elem[j] = aux;
}

static int particionamento(void* vetor[], int lim_i, int lim_f, TCompararQS comparar){
    int ipivo = (lim_f+lim_i)/2;
    
    void* pivo = vetor[ipivo];
    trocar(vetor, ipivo, lim_f);
    
    int i=lim_i;
    int j=lim_f-1;

    do{
        while(comparar(vetor[i],pivo) < 0){
            i++;
        }
        while( (j>=lim_i) && (comparar(vetor[j],pivo)>0) ){ // detalhe
            j--;
        }

        if (i<j){
            trocar(vetor,i,j);
            i++;j--;
        }
    }while(i<=j);
    trocar(vetor,i,lim_f);

    return i;
}

void quicksort(void* vetor[], int lim_i, int lim_f, TCompararQS comparar){
    
    //detalhes
    if ((lim_f-lim_i) > 0){
        int meio = particionamento(vetor, lim_i, lim_f, comparar);
        quicksort(vetor, lim_i, meio-1, comparar);
        quicksort(vetor, meio+1, lim_f, comparar);
    }
}