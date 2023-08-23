typedef int(*TCompararHeap)(void*, void*);

typedef struct heap t_heap;

t_heap* criar_heap(int tam, TCompararHeap comparar);
int inserir_heap(t_heap* h, void* elem);
void* remover_heap(t_heap* h);
void* raiz_heap(t_heap* h);
int popular_heap(t_heap* h, void* elem);
int ocupacao_heap(t_heap* h);
int tamanho_heap(t_heap* h);