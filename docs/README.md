# Pré-AED2

## Sumário

1. [Introdução](#introdução)

2. [Variáveis](#variáveis)

    2.1. [Int](#int)

    2.2. [Double](#double)

    2.3. [Ponteiro](#ponteiro)

    2.4. [Struct](#struct)

3. [Vetores](#vetores)

4. [String](#string)

5. [Lista Encadeda](#lista-encadeada)

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

Em programação, um vetor é uma estrutura de dados que armazena um conjunto de valores do mesmo tipo em uma única variável. Cada valor é identificado por um índice numérico que começa em zero e vai até o tamanho do vetor menos um.

Por exemplo, imagine que precisamos armazenar as notas de uma turma de 10 alunos em uma variável. Uma forma de fazer isso seria declarar 10 variáveis separadas, mas isso seria muito trabalhoso e pouco prático. É aí que os vetores entram em cena! Podemos declarar um vetor de 10 elementos do tipo double (números decimais), como:

    double notas[10];

Este vetor armazena 10 valores do tipo double. Para acessar um elemento específico do vetor, usamos um índice entre colchetes após o nome do vetor. Por exemplo, para atribuir a nota 7.5 ao primeiro aluno, fazemos:

    notas[0] = 7.5;

É importante lembrar que o índice começa em zero, então o primeiro elemento do vetor é o de índice zero. Para acessar o segundo elemento do vetor, usamos o índice 1:

    notas[1] = 8.0;

E assim por diante. Para acessar o último elemento do vetor, usamos o índice igual ao tamanho do vetor menos um:

    notas[9] = 9.0;

Podemos inicializar o vetor com valores conhecidos utilizando a sintaxe de inicialização de vetor. Por exemplo, para inicializar o vetor com as notas de um aluno, fazemos:

    double notas[4] = {7.5, 8.0, 9.0, 7.0};

Neste caso, estamos inicializando o vetor com 4 valores. O compilador C sabe que o tamanho do vetor é 4 porque contou o número de valores na inicialização.

Podemos percorrer todos os elementos do vetor utilizando um laço de repetição. Por exemplo, para imprimir todas as notas do vetor, podemos fazer:

```
for (int i = 0; i < 4; i++) {
    printf("Nota %d: %.1lf\n", i+1, notas[i]);
}
```

Neste caso, estamos utilizando um laço for que vai de 0 até 3 (o tamanho do vetor menos um) e imprime o índice do elemento e o valor da nota correspondente. O formato "%.1lf" é utilizado para imprimir o valor da nota com uma casa decimal.

Os vetores são uma estrutura de dados muito importante em programação, e são amplamente utilizados para armazenar grandes quantidades de dados em uma única variável. Eles são muito úteis em algoritmos de busca, ordenação, processamento de imagens, entre outras aplicações.

### String

Uma string é uma sequência de caracteres que representa um texto ou uma mensagem. Em C, uma string é representada como um vetor de caracteres (array), onde cada elemento do vetor é um caractere da string. O último caractere do vetor é sempre o caractere nulo ('\0'), que indica o fim da string.

Por exemplo, para declarar uma string que contém o texto "Olá, mundo!", podemos fazer:

    char mensagem[13] = "Olá, mundo!";

Neste caso, estamos declarando um vetor de caracteres chamado "mensagem" que tem tamanho 13 (12 caracteres mais o caractere nulo). É importante lembrar que a string sempre ocupa um caractere a mais do que o tamanho do texto, para armazenar o caractere nulo.

Podemos acessar os caracteres da string utilizando um índice entre colchetes. Por exemplo, para imprimir o primeiro caractere da string, fazemos:

    printf("Primeiro caractere: %c\n", mensagem[0]);

Neste caso, estamos utilizando o formato "%c" para imprimir o caractere correspondente ao índice 0 do vetor.

Podemos percorrer todos os caracteres da string utilizando um laço de repetição. Por exemplo, para imprimir todos os caracteres da string, podemos fazer:

```
for (int i = 0; i < 13; i++) {
    printf("%c", mensagem[i]);
}
```

Neste caso, estamos utilizando um laço for que vai de 0 até 12 (o tamanho do vetor menos um) e imprime cada caractere da string. O formato "%c" é utilizado para imprimir cada caractere individualmente.

Outra forma possível e mais usada é com o formatodor "%s":

    printf("%s", mensagem);

Podemos modificar os caracteres da string atribuindo um valor a um elemento do vetor. Por exemplo, para alterar o último caractere da string para o caractere '?', fazemos:

    mensagem[12] = '!';

Neste caso, estamos atribuindo o caractere '?' ao último elemento do vetor.

Existem várias funções úteis para manipulação de strings em C, como strlen() para obter o comprimento da string, strcpy() para copiar uma string para outra, strcat() para concatenar duas strings, entre outras.

É importante lembrar que as strings em C são arrays de caracteres, e por isso é fácil cometer erros de buffer overflow (quando se escreve além do espaço reservado para o vetor), especialmente ao manipular strings de tamanho desconhecido. Para evitar esse tipo de erro, é importante sempre verificar o tamanho da string antes de realizar operações com ela, e utilizar funções que garantem a segurança da operação, como strncpy() em vez de strcpy().
### Lista Encadeada

Lista