#include "stdio.h"

void intercalar(double notas01[], int tam_notas01, double notas02[], int tam_notas02, double resultado[]){
    int j=0, k=0, l=0;
    while((j<tam_notas01) && (k<tam_notas02)){
        if (notas01[j] > notas02[k]){
            resultado[l] = notas02[k];
            k++;
        }else{
            resultado[l] = notas01[j];
            j++;        
        }
        l++;    
    }
    while(j<tam_notas01){
        resultado[l] = notas01[j];
        l++;j++;
    }
    while(k<tam_notas02){
        resultado[l] = notas02[k];
        l++;k++;
    }

}

void ler_notas(double vetor_notas[], int tam){
    for(int i=0;i<tam;i++){
        scanf("%lf", &vetor_notas[i]);
    }
}

int main(int argc, char const *argv[])
{
    int tam_EC = 3;
    int tam_CC = 3;
    int tam_ES = 3;

    double notas_EC[tam_EC];
    double notas_CC[tam_CC];
    double notas_ES[tam_ES];

    ler_notas(notas_EC, tam_EC);
    ler_notas(notas_CC, tam_CC);
    ler_notas(notas_ES, tam_ES);

    double medias_CC_EC[tam_CC+tam_EC];
    double medias[tam_CC+tam_EC+tam_ES];
    
    intercalar(notas_CC, tam_CC, notas_EC, tam_EC, medias_CC_EC);
    intercalar(medias_CC_EC, tam_CC+tam_EC, notas_ES, tam_ES, medias);

    for(int i=0;i<tam_CC+tam_EC+tam_ES;i++){
        printf("%.2lf ",medias[i]);
    }
    printf("\n");
    return 0;

}
