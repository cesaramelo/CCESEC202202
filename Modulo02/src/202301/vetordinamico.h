typedef struct vd t_vd;

t_vd* criar_vd();
void* acessar_vd(t_vd* vd, int pos);
void inserir_vd(t_vd* vd, void* elem);
int ocupacao_vd(t_vd* vd);