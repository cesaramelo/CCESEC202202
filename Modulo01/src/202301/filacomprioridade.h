typedef int(*TCompararFilaCP)(void*,void*);

typedef struct fila_cp t_fila_cp;
t_fila_cp* criar_fila_cp(int tam, TCompararFilaCP comparar);
int enfileirarCP(t_fila_cp *f, void* elem);
void* desenfileirarCP(t_fila_cp *f);
void* primeiro_FCP(t_fila_cp *f);
int ocupacao_FCP(t_fila_cp *f);
int tamanho_FCP(t_fila_cp *f);
