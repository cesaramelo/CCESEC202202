

static void trocar(void* elem[], int i, int j){
    void* aux = elem[i];
    elem[i] = elem[j];
    elem[j] = aux;
}

int particionamento(int vetor[], int lim_i, int lim_f){
    int ipivo = (lim_f+lim_i)/2;
    
    int pivo = vetor[ipivo];
    trocar(vetor, ipivo, lim_f);
    
    int i=lim_i;
    int j=lim_f-1;

    do{
        while(vetor[i]<pivo){
            i++;
        }
        while( (j>=0) && (vetor[j]>pivo)){ // detalhe
            j--;
        }

        if (i<j){
            trocar(vetor,i,j);
        }
    }while(i<j);
    trocar(vetor,i,lim_f);

    return i;
}

void quicksort(int vetor[], int lim_i, int lim_f){
    
    //detalhes
    if ((lim_f-lim_i) > 0){
        int meio = particionamento(vetor, lim_i, lim_f);
        quicksort(vetor, lim_i, meio-1);
        quicksort(vetor, meio+1, lim_f);
    }
}