---
marp: true
title: Atividade com Vetor
author: César Melo
theme: gaia
---
# Variáveis

def. __Uma variável representa um conceito presente no contexto em que a rotina computacional está sendo implementada.__

Ex. __idade, nota, matricula__

- Uma variável possui 
    - tipo;
    - nome;
    - escopo (local, global)
---
# Declaração das variáveis
Sintaxe geral: 
```C
<tipo> <nome_variável>
```
Exemplo:
```C
int idade;
double nota;
char nome[60];
```

---
# Mais sobre variável

- Pelo nome acessamos o valor associado

```C 
printf("%d", idade);
printf("%s", nome);
printf("%.2lf", nota);
```

- Pelo nome acessamos o endereço de memória associado (operador unário __&__ )

```C
printf("%p", &idade);
printf("%p", &nome);
printf("%p", &nota);
```
---
# Escopos de variáveis
arquivo.c
```C
double media;

void calcular_media(double nota_1, double nota_2){
    media = (nota_1+nota_2)/2.0
    if ((media > 7.8) && (media < 8.0)){
        media = 8.0
    }
}
int main(){
    double nota_1, nota_2, media=10.0;
    calcular_media(8.0,8.5);
    printf("%.2lf %lf %lf", media, nota_1, nota_2);
}
```
---
# Declarações de variáveis
```C
double nota; // reserva memória e associa o nome.

double* p_nota; // reserva memória e associa nome.

nota = 9.0; // atribui valor
p_nota = &nota; // atribui valor (endereço da variável)

printf("%lf\n", nota); // qual é o valor?
printf("%p\n", p_nota);
printf("%lf\n", *p_nota);

```
---
# Alocação dinâmica de memória
- Variável anônima
    - criada em tempo de execução;
    - apenas o seu endereço é conhecido
- Declaração  
    - malloc();
    - manipulação via ponteiros;
- Ponteiros são variáveis ``especiais'''
    - int* p_idade;
    - double* p_nota;
---
Exemplos:
```C
#include "stdlib.h""

int* criar_variavel(){
    return malloc(sizeof(int));
}

int main(){
    int* p = criar_variavel();

    p = 10;
    *p = 10;
    printf("%d", p);
    printf("%p", *p);
    printf("%d", *p);
}
``````

___
# Vetores

__Definição__. Variável composta Homogênea que agrupa valores de um __mesmo tipo__ sob a referência de um único __nome__.

1. Considere que:
    * Valores são acessados individualmente
    * O acesso é feito por meio de índice
    * Os índices variam entre [0,N-1], *N* é o tamanho do vetor

2. Sintaxe
    *<tipo_do_vetor> Nome_do_vetor [<tamanho>];*
---
# Vetores (II)

1. Exemplos de definição
```C
int faltas[62];
double notas[62];
char nome_aluno[62][100];
```

2. Exemplos de acesso
```C
printf("%d", faltas[0]);
printf("%s", nome_aluno[5]);
```

---
# Atividade: O maior

Escreva um algoritmos que encontre o Maior valor em um vetor não ordenado, que representa o número de faltas dos alunos da disciplina.

Seu programa deve imprimir o maior valor encontrado, seguido pelo índices dos elementos do vetor que tem valor igual ao valor indicado.

Considere o seguinte vetor V={10,3,5,6,7,10}, com 6 elementos. O seu programa deve produzir como saida o seguinte resultado: 
* maior: 10
* indice(s): 0 5

---
# Atividade: O Endereço
Defina um vetor com 10 elementos dos tipos __double__, __int__, e __char__.

Em seguida realize a seguintes operações:
```C
printf("%p\n", nome_do_vetor_de_int);
printf("%p\n", nome_do_vetor_de_double);
printf("%p\n", nome_do_vetor_de_char);

printf("%p\n", nome_do_vetor_de_double);
printf("%p\n", nome_do_vetor_de_double+9);
printf("%lf\n", *nome_do_vetor_de_double);
```

Aponte ao colega as saídas. Se ele discordar, qual é a visão dele?

---
# Atividade: Intercalação
Um vetor __V__ de inteiros foi divido em duas partes indexadas pelas variávies __k, l e m__. A primeira parte do vetor é indexada no intervalo [k,l] e a segunda parte do vetor é indexada no intervalo [l+1,m]. Escreva um programa que intercale essas duas partes armazenando o resultado da intercalação no vetor __V__.

---
# Atividade: Intercalação (Instância)
| Instância                              |      | Resultado |
|--------------------                    |----- |---        |
![width:500px](imgs/vetor-intercalar.svg)|      |![width:500px](imgs/vetor-intercalar-res.svg)



