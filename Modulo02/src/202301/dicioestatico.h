typedef struct dicio_estatico t_de;

t_de* criar_dicio_estatico();
void inserir_de(t_de* de, int chave, void* carga);
void* buscar_de(t_de *de, int chave);