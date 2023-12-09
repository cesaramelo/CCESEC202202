typedef int(*t_comparar_ab)(void* i1, void* i2 );
typedef struct ab t_ab;

t_ab* criar_ab(t_comparar_ab comparar);
int altura_ab(t_ab *ab);
int tamanho_ab(t_ab *ab);
void* buscar_ab(t_ab *ab, void* chave);
void inserir_ab(t_ab *ab, void* info);
void podar_ab(t_ab *ab, void* podavel);