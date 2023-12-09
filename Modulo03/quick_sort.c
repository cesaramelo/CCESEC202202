#include "stdio.h"
#include "stdlib.h"

int comparar_int(int* p1, int* p2){
    return (*p1 - *p2);
}

int* ler_int(){
    int* inteiro = malloc(4);
    scanf("%d", inteiro);
    return inteiro;
}

void mostrar_int(int* inteiros[], int tam){
       for(int i=0;i<tam;i++){
        printf("%d ", *inteiros[i]);
    }
    printf("\n");
}


typedef int(*t_qs_comparar)(void*, void*);

static void __trocar(void* vetor[], int i, int j){
    void* aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}


static int __particionar(void* vetor[], int inicio, int fim, t_qs_comparar comparar){
    int ipivo = (inicio+fim)/2;
    __trocar(vetor,ipivo,fim);
    int i=inicio;
    int j=fim-1;
    while(i<=j){
        while(comparar(vetor[i], vetor[fim])<0){ // < pivo
            i++;
        }
        while((j>=0) && (comparar(vetor[j], vetor[fim])>0) ){ //> pivo
            j--;
        }
        if (i<=j){ // <= ou <?
            __trocar(vetor,i,j);
            i++;
            j--;
        }
    }
    __trocar(vetor,i,fim);
    return i;
}

static void __qs(void* vetor[], int inicio, int fim, t_qs_comparar comparar){
    if ((fim-inicio) <= 0)
        return;
    int meio = __particionar(vetor, inicio, fim, comparar);
    __qs(vetor,inicio,meio-1,comparar);
    __qs(vetor,meio+1,fim,comparar);
}

void qs(void* vetor[], int tam, t_qs_comparar comparar){
    __qs(vetor, 0, tam-1, comparar);
}


int main(){
    int TAM = 10;
    int* inteiros[TAM];
    for(int i=0;i<TAM;i++){
        inteiros[i] = ler_int();
    }
    qs(inteiros, TAM, comparar_int);

    mostrar_int(inteiros,TAM);
}
