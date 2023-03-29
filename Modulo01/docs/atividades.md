---
marp: true
title: Atividade com Vetor
author: César Melo
theme: gaia
---
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
    *int faltas[62];*
    *double notas[62];*
    *char nome_aluno[62][100];*

2. Exemplos de acesso
    *printf("%d", faltas[0]);*
    *printf("%s", nome_aluno[5]);*

---
# Atividade: O maior

Escreva um algoritmos que encontre o Maior valor em um vetor não ordenado. Os valores nesse vetor representam o número de faltas dos alunos de uma disciplina.

Seu programa deve imprimir o maior valor encontrado, seguido pelo índices dos elementos do vetor que tem valor igual ao valor indicado.

Considere o seguinte vetor V={10,3,5,6,7,10}, com 6 elementos. O seu programa deve produzir como saida o seguinte resultado: 
* maior: 10
* indice(s): 0 5

---
# Atividade: O Endereço
Defina um vetor dos seguintes tipos de dados __double__, __int__, e __char__. Cada vetor deve ter um tamanho igual a 10.

Em seguida realize a seguintes operações:

    *printf("%p\n",nome_do_vetor_de_int)*
    *printf("%p\n", nome_do_vetor_de_double)*
    *printf("%p\n", nome_do_vetor_de_char)*

    printf("%p\n", nome_do_vetor_de_double);
    printf("%p\n", nome_do_vetor_de_double+9);
    printf("%lf\n", *nome_do_vetor_de_double);


Comente com o seu colega o que você acha que está sendo impresso. Veja se ele concorda com você. Se ele não concordar, peça para ele uma explicação.

---
# Atividade: Intercalação

Um vetor __V__ de inteiros foi divido em duas partes indexadas pelas variávies __k, l e m__. A primeira parte do vetor é indexada no intervalo [k,l] e a segunda parte do vetor é indexada no intervalo [l+1,m]. Escreva um programa que intercale essas duas partes armazenando o resultado da intercalação no vetor __V__.

Considere o vetor __V__ = {10,17,21,7,11,28}, k=0, l=2, e m = 5. Então as parte de __V__ serão __V[k,l]__={10,17,21} e __V[l+1,m]__ = {7,11,28}. Então o programa deve gerar um __V__ = {7,10,11,17,21,28}.

---

```


```