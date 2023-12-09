#include "stdio.h"
#include "stdlib.h"
#include "dicioestatico.h"

static int char_to_int(char* pal){
    int chave=0;
    int pesos[] = {10,20,5,700,2};
    for(int i=0;i<strlen(pal);i++){
        chave += pal[i]*pesos[i];
    }
    return chave;
}

int main(int argc, char const *argv[])
{
    char* lista_pal[] = {"agua", "amigo", "cama", "carro", "casa"};
    int tam=5;

    t_de *meude = criar_dicio_estatico();

    for (int i=0;i<tam;i++){
        int chave = char_to_int(lista_pal[i]);
        inserir_de(meude, chave, lista_pal[i]);
    }

    consultar_de(meude,  char_to_int(lista_pal[0]) );

    remover_de(meude, char_to_int("aluno"));
    
    return 0;
}
