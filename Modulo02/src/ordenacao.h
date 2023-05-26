typedef int(*TCompararHeapsort)(void*, void*);
typedef int(*TCompararQS)(void*, void*);
typedef int(*TLerIdRadixSort)(void*);
typedef int(*TLerIdContagem)(void*);

void heapsort(void* vetor[], int tam, TCompararHeapsort comparar);
void quicksort(void* vetor[], int lim_i, int lim_f, TCompararQS comparar);
void radixsort(void* vetor[], int tam, int digs, TLerIdRadixSort ler_id);
void contagem(void* vetor[], int tam, TLerIdContagem ler_id);