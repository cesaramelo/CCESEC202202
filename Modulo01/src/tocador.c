//----------
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "listase.h"

// Contexto especialista
typedef struct musica{
    char nome[60];
    int duracao_seg;
    char genero[30];
}t_musica;

t_musica* criar_musica(char nome[], int duracao, char genero[]){
    t_musica* musica = malloc(sizeof(t_musica));

    musica->duracao_seg = duracao;
    strcpy(musica->genero, genero);
    strcpy(musica->nome, nome);

    return musica;
}   

void imprimir_musica(void* m){
    t_musica* mm = m;
    printf("%s %d\n", mm->nome, mm->duracao_seg);
}

int main(){
    t_lse* musicas = criar_lse(imprimir_musica);
    char nome[60], genero[30];
    int duracao;

    for(int i=1;i<10;i++ ){
        scanf("%s", nome);
        scanf("%s", genero);
        scanf("%d", &duracao);
        t_musica* m = criar_musica(nome, duracao, genero);
//        inserir_inicio_lse(musicas, i);
        inserir_final_lse(musicas, m);
    }

    t_musica*  musica_inicio = remover_inicio_lse(musicas);
    //printf("removeu: %d\n", musica);
    free(musica_inicio);
    
    t_musica* musica_ult = remover_final_lse(musicas);
    //printf("removeu: %d\n", musica_ult);
    free(musica_ult);

    t_musica* segunda = acessar_lse(musicas, -2);
    //printf("acessou: %d\n", segunda);
    free(segunda);

    t_musica* outra_musica = acessar_lse(musicas, 15);
    //printf("acessou: %d\n", outra_musica);
    free(outra_musica);

    imprimir_lse(musicas);

    return 0;

}