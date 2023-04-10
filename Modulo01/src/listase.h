typedef struct lse t_lse;
typedef void(*t_imprimir_lse)(void*);

t_lse* criar_lse(t_imprimir_lse impressora);

// operacoes baseadas em posicao
void inserir_inicio_lse(t_lse* lse, void* carga);
void* remover_inicio_lse(t_lse* lse);
void* acessar_lse(t_lse* lse, int pos);
void inserir_final_lse(t_lse* lse, void* carga);
void* remover_final_lse(t_lse* lse);
void imprimir_lse(t_lse *lse);
