#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "ordenacao.h"

int ler_int(void* elem){
    
    return *((int*)elem);

}

int compararint(void* e1, void* e2){
    int* ee1 = (int*)e1;
    int* ee2 = (int*)e2;
    return (*ee1 - *ee2);
}

int* *criar_vetor_inteiro(int tam, int lim_i, int lim_s){
    int* *vetor = malloc(sizeof(int*)*tam);
    for(int i=0;i<tam;i++){
        vetor[i] = malloc(sizeof(int));
        int num = rand();
    
        *(vetor[i]) = lim_i+(((double)num/RAND_MAX)*(lim_s-lim_i));

        //printf("%d %d\n", num, *(vetor[i]));
    }
    return vetor;
}


void destroy_vetor(int* vetor[], int tam){
    for(int i=0;i<tam;i++)
        free(vetor[i]);
}

int main(int argc, char const *argv[])
{
    int tam = 1000000;

    printf("criando-------\n");
//    int* *vetor = criar_vetor_inteiro(tam,01000000,99999999);//{3,3,7,2,7,4,7,6,4,8,8,3,0,2,1,0,2};
    int* *vetor = criar_vetor_inteiro(tam,1,7);//{3,3,7,2,7,4,7,6,4,8,8,3,0,2,1,0,2};

    printf("ordenando-------\n");
    //contagem(vetor, tam, 9, ler_int);
    radix_sort(vetor,tam,8,ler_int);
    //heap_sort(vetor, tam, compararint);
    //quicksort(vetor, 0, tam-1, compararint);
    
    printf("Ordenado----\n");
    // for(int i=0;i<tam;i++){
    //      printf("%d %08d\n", i, *(vetor[i]));
    // }
    // printf("\n");

    return 0;
}

