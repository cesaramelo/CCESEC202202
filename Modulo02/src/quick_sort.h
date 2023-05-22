typedef int(*TCompararQS)(void*, void*);
void quicksort(void* vetor[], int lim_i, int lim_f, TCompararQS comparar);