# Pré-AED2

## Sumário

1. [Introdução](#introdução)

2. [Variáveis](#variáveis)

    2.1. [Int](#int)

    2.2. [Double](#double)

    2.3. [Ponteiro](#ponteiro)

    2.4. [Struct](#struct)

3. [Vetores](#vetores)

4. [Lista Encadeda](#lista-encadeada)

## Introdução

Este conteúdo foi feito como base no depoimento de alunos que pagaram a disciplina de algoritmo e estruturas de dados II e tiveram dificuldades.

As dificuldades relatadas foram compiladas neste matérial para facilitar para os futuros alunos da disciplina.

## Variáveis

Em programação, uma variável é um espaço de memória reservado para armazenar um valor que pode ser modificado durante a execução do programa.

### Int

Variáveis do tipo inteiro são usadas para armazenar números inteiros em programação. Entretanto, na linguagem C, o int possui algumas variações que diferem em tamanho e capacidade de armazenamento.

Existem diversas variações do int em C, cada uma com um tamanho e capacidade de armazenamento diferentes. Aqui estão algumas das variantes mais comuns do int:

Tipo | Total de bits | Quanto armazena
-----|---------------|----------------
short int | 2 | -32.768 a 32.767
unsigned short int | 2 | 0 a 65.535 
int  |    32         | -2.147.483.648 a 2.147.483.647
unsigned int | 32    | 0 a 4.294.967.295
long int | 64 | -9.223.372.036.854.775.808 a 9.223.372.036.854.775.807
using long int | 64 | 0 a 18.446.744.073.709.551.615


Mas porquê há tantas variantes diferentes? suponhamos que você quer fazer o cálculo de quanto os alunos da ufam ganham durante um ano. É claro que a soma não vai ser superir a 32.000 reais, então ao usar uma variável short, você vai usar apenas 2 Bytes ao invés de 4 Bytes, economizando assim mémoria.

### Double

Double é usado para armazenar números reais.

### Char

Char é capaz de armazenar valores de -128 a 127, e a unsigend char consegue armazenar valores de 0 a 255.

Comumente usamos o tipo char para armazenar caracteres.

### Ponteiro

As variáveis do tipo ponteiro em C são variáveis que armazenam o endereço de memória de outra variável. Em outras palavras, um ponteiro é uma variável que contém o endereço de memória de uma outra variável.

Em C, o operador & pode ser usado para obter o endereço de memória de uma variável, e o operador * pode ser usado para acessar o valor armazenado em um endereço de memória.

Para declarar um ponteiro em C, use o tipo de dados seguido de um asterisco (*), seguido pelo nome da variável. Por exemplo, para declarar um ponteiro para um inteiro, você pode escrever:

    int *ponteiro_para_int;

Isso declara uma variável chamada ponteiro_para_int do tipo "ponteiro para inteiro".

Para atribuir o endereço de memória de uma variável a um ponteiro, use o operador &. Por exemplo, para atribuir o endereço de memória de uma variável x a um ponteiro `ponteiro_para_x`, você pode escrever:

    int x = 42;
    int *ponteiro_para_x = &x;

Agora ponteiro_para_x contém o endereço de memória de x.

Para acessar o valor armazenado em um endereço de memória, use o operador *. Por exemplo, para imprimir o valor armazenado em x usando o ponteiro ponteiro_para_x, você pode escrever:

    printf("O valor de x é: %d\n", *ponteiro_para_x);

Isso imprime "O valor de x é: 42" na tela.

Os ponteiros são úteis em C para várias tarefas, incluindo alocação dinâmica de memória, passagem de argumentos para funções por referência e implementação de estruturas de dados avançadas, como listas encadeadas e árvores binárias. No entanto, o uso incorreto de ponteiros pode levar a erros de memória, como vazamentos de memória e acesso a áreas de memória não autorizadas. Por isso, é importante entender bem como os ponteiros funcionam e usá-los com cuidado em seus programas em C.

### Struct

Uma struct é um tipo de variável que permite agrupar múltiplas variáveis em uma única unidade. Em programação, é comum encontrarmos situações em que precisamos lidar com conjuntos de dados complexos que não podem ser representados por uma única variável. É aí que entra a struct!

Por exemplo, imagine que você precisa armazenar informações sobre uma palavra em um livro, como a própria palavra e o número de vezes que ela aparece. Nesse caso, você pode criar uma struct para representar essa informação:

    typedef struct recorrencia {
        char palavra[150];
        int numero_repeticoes;
    } recorrencia;

Essa struct contém duas variáveis: uma string de caracteres chamada "palavra" (que pode armazenar uma palavra com até 150 caracteres) e um número inteiro chamado "numero_repeticoes" (que armazena a quantidade de vezes que a palavra aparece).

Com essa estrutura, você pode criar uma variável para cada palavra que precisa ser contada:

    recorrencia palavra1 = {"Resiliência", 15};
    recorrencia palavra2 = {"Programação", 10};

E agora você pode lidar com cada palavra como um único objeto, acessando as suas propriedades através do ponto ".". 

Por exemplo:

    printf("%s apareceu %d vezes\n", palavra1.palavra, palavra1.numero_repeticoes);

Espero que isso ajude a esclarecer como as structs podem ser úteis para lidar com conjuntos de dados mais complexos em programação!

### Vetores

### Lista Encadeada

Lista