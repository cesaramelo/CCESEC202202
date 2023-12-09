typedef struct avl t_avl;
typedef int(*t_comparar_avl)(void* e1, void* e2);
typedef void(*t_destruir_avl)(void* info);
typedef void(*t_imprimir_avl)(void* info);

t_avl* criar_avl(t_comparar_avl comparar, t_destruir_avl destruir, t_imprimir_avl imprimir);
int altura_avl(t_avl *avl);
int tamanho_avl(t_avl *avl);
void* buscar_avl(t_avl *avl, void* chave);
void inserir_avl(t_avl *avl, void* info);
void podar_avl(t_avl *avl, void* podavel);
void imprimir_avl(t_avl *avl);
void remover_avl(t_avl *avl, void* chave);