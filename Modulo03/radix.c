#include "stdio.h"
#include "math.h"

#define pega_digito(n,d) (int)floor((n*pow(10,-d) - floor(n*pow(10,-d)))*10)

void counting_sort(int array[], int size, int d) {

  int count[]={0,0,0,0,0,0,0,0,0,0,0};

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[ pega_digito(array[i],d) ]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= 9; i++) {
    count[i] += count[i - 1];
  }

    int output[size];
  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    output[count[ pega_digito(array[i],d) ] - 1] = array[i];
    count[ pega_digito(array[i],d) ]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}


void radix(int vetor[], int tam, int nro_dig){
    
    //
    for(int d=1;d<=nro_dig;d++){
        counting_sort(vetor,tam, d);
    }
}

int main(int argc, char const *argv[])
{
    int tam=5;
    int vetor[] = {10,3,100,15,24};
    
    radix(vetor,tam,3);

    for(int i=0;i<tam;i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}
