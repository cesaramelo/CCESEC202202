typedef int(*t_comparar_dd)(void* carga1, void* carga2);
typedef struct dicio_dinamico t_dd;

t_dd* criar_dd(int fator_carga, int tam);
int inserir_dd(t_dd *dd, int chave, void*carga);
void* consultar_dd(t_dd *dd, int chave);
void* remover_dd(t_dd *dd, int chave);
