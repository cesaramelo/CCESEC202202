typedef struct carro t_carro;

t_carro* criar_carro(char placa[], int hora, int min, int anoFab);
void destroy_carro(t_carro *c);
void imprimir_carro(t_carro* c);
int comparar_carro(t_carro* c1, t_carro* c2);
t_carro* ler_carro();
void* ler_chave_carro(char* placa);
