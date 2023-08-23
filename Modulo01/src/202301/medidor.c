#include "stdio.h"
#include "stdlib.h"
#include "fila.h"

typedef struct medicao t_medicao;
struct medicao{
    int hora, min;
    double temp;
};

t_medicao* criar_medicao(int hora, int min, double temp){
    t_medicao* m = malloc(sizeof(t_medicao));
    m->temp = temp;
    m->hora = hora;
    m->min = min;

    return m;
}

void imprimir_medicao(void* m){
    t_medicao *mm = m; // casting
    printf("%02d:%02d %.2lf\n", mm->hora, mm->min, mm->temp);

}

int comparar_medicao(void* m1, void* m2){

    return 1;
}

t_medicao* ler_medicao(){
    int hora, min;
    double temp;

    scanf("%d", &hora);
    if (hora >= 0){
        scanf("%d", &min);
        scanf("%lf", &temp);
        return criar_medicao(hora, min, temp);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    short ainda_tem=1;    
    //t_lse* medicoes = criar_lse(imprimir_medicao, comparar_medicao);
    t_fila* medicoes = criar_fila(0);
    while(ainda_tem){
        t_medicao* nova = ler_medicao();
        if (nova){
            enfileirar(medicoes, nova);
        }else{
            ainda_tem = 0; // falso
        }
    }
    
    t_medicao* m = desenfileirar(medicoes);
    imprimir_medicao(m);

    return 0;
}



