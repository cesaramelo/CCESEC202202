
typedef struct pilha t_pilha;
t_pilha* criar_pilha(int max_altura);
short empilhar(t_pilha* p, void* elem);
void* desempilhar(t_pilha* p);
void* topo_pilha(t_pilha *p);
int altura_pilha(t_pilha* p);
