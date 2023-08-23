#include "stdio.h"


int main(int argc, char const *argv[])
{
    int tam_EC = 3;
    int tam_CC = 3;
    double notas_EC[] = {8.0,8.0,8.0};
    double notas_CC[] = {8.0,8.5,9.0};
    double medias[tam_CC+tam_EC];
    int j=0, k=0, l=0;
    while((j<tam_EC) && (k<tam_CC)){
        if (notas_EC[j] > notas_CC[k]){
            medias[l] = notas_CC[k];
            k++;
        }else{
            medias[l] = notas_EC[j];
            j++;        
        }
        l++;    
    }
    while(k<tam_CC){
        medias[l] = notas_CC[k];
        l++;k++;
    }
    while(j<tam_EC){
        medias[l] = notas_EC[j];
        l++;j++;
    }
    for(int i=0;i<tam_CC+tam_EC;i++){
        printf("%.2lf ",medias[i]);
    }
    printf("\n");
    return 0;

}
