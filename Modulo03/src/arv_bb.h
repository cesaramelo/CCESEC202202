typedef void(*TImprimirABB)(void* info);
typedef int(*TCompararABB)(void* s1, void* s2);
typedef struct abb t_abb;

t_abb* criarABB(TImprimirABB imprimir, TCompararABB comparar);
void estatisticaABB(t_abb *abb);
void inserirABB(t_abb *abb, void* info);
void* buscarABB(t_abb *abb, void* buscado);
void removerABB(t_abb *abb, void* removivel);
void podarABB(t_abb* abb, void* info);
int alturaABB(t_abb *abb);
int tamanhoABB(t_abb *abb);
void imprimirABB(t_abb* abb);
