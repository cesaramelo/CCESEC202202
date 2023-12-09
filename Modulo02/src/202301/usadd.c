#include "diciodinamico.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef struct{
    int mat;
    char nome[100];
    char cod_curso[10];
} t_aluno;

t_aluno* criar_aluno(int mat, char nome[], char cod_curso[]){
    t_aluno* novo = malloc(sizeof(t_aluno));

    novo->mat = mat;
    strcpy(novo->nome, nome);
    strcpy(novo->cod_curso, cod_curso); 

    return novo;
}

void mostrar_aluno(t_aluno* aluno){
    if (aluno){
        printf("mat: %d\n", aluno->mat);
        printf("nome: %s\n", aluno->nome);
        printf("cod_curso: %s\n", aluno->cod_curso);
    }else{
        printf("Nada a ser mostrado\n");
    }
}

void destroy_aluno(t_aluno *aluno){
    if (aluno){
        free(aluno);
    }else{
        printf("Nada a ser destruído\n");
    }
}

t_aluno* ler_aluno(){
    t_aluno* aluno=NULL;
    int mat;
    scanf("%d", &mat);
    if (mat !=0){
        char nome[100];
        char cod_curso[10];
        scanf("%s", nome);
        scanf("%s", cod_curso);
        aluno = criar_aluno(mat,nome,cod_curso);
    }
    return aluno;
}

int main(int argc, char const *argv[])
{
    t_aluno* matriculado=NULL;
    t_dd *alunos = criar_dd(6,3);
    do{
        matriculado =ler_aluno();
        if (matriculado){
            inserir_dd(alunos, matriculado->mat, matriculado);
        }
    }while(matriculado);

    // consultar
    int mat;
    printf("consultando....\n");
    scanf("%d", &mat);
    t_aluno* consultado = consultar_dd(alunos, mat);

    mostrar_aluno(consultado);

    // remover
    printf("removendo.....\n");
    scanf("%d", &mat);
    t_aluno* removido = remover_dd(alunos, mat);

    mostrar_aluno(removido);
    destroy_aluno(removido);

    return 0;
}

