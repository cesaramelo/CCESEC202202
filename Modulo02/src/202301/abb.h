typedef struct abb t_abb;
typedef int(*t_comparar_abb)(void* e1, void* e2);
typedef void(*t_destruir_abb)(void* info);
typedef void(*t_imprimir_abb)(void* info);

t_abb* criar_abb(t_comparar_abb comparar, t_destruir_abb destruir, t_imprimir_abb imprimir);
int altura_abb(t_abb *abb);
int tamanho_abb(t_abb *abb);
void* buscar_abb(t_abb *abb, void* chave);
void inserir_abb(t_abb *abb, void* info);
void podar_abb(t_abb *abb, void* podavel);
void imprimir_abb(t_abb *abb);
void remover_abb(t_abb *abb, void* chave);