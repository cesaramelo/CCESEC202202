typedef int(*t_heap_comparar)(void*, void*);
typedef struct heap t_heap;
t_heap* criar_heap(int tamanho, t_heap_comparar comparar);
void* primeiro_heap(t_heap* heap);
void* remover_heap(t_heap* heap);
void sobe_heap(void* elems[], int i, t_heap_comparar comparar);
void inserir_heap(t_heap* heap, void* elem);
void alterar_heap(t_heap* heap, void* chave, void* elem);
