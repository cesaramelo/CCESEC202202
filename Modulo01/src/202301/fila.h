
typedef struct fila t_fila;

t_fila* criar_fila(int tamanho);
void enfileirar(t_fila* f, void* elem);
void* desenfileirar(t_fila* f);
int tamanho_fila(t_fila* f);

