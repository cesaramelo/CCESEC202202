# Atividades
Aqui você vai encontrar os enunciados de todos os trabalhos apresentados neste semestre.

# Uso de listas neutralizadas

Neste trabalho você precisará implementar listas que serão capazes de armazenar um conjunto de dados gerado por diferentes sensores que detectam e registram os eventos em uma área monitorada.

Os sensores foram distribuídos para medir condições ambientais, e.g., temperatura e das massas de ar. Cada sensor portanto registra medições distintas que tem seus atributos.

Sua tarefa consiste em ler todas as medidas, armazenadas em um arquivo, e incluí-las na lista de eventos.

As medidas relacionadas a __temperatura__ têm os seguintes atributos:

```json
{  seq :inteiro,
   dia:inteiro,
   hora:inteiro,
   minuto:inteiro,
   hora:inteiro,
   minuto:inteiro,
   radiacao_solar:inteiro,
   temperatura:double,
   umidade_relativa: double
}
```

As medidas relacionadas as massas de ar têm os seguintes atributos:

```json
{  seq:inteiro,
   dia:inteiro,
   hora:inteiro,
   minuto:inteiro,
   hora:inteiro,
   minuto:inteiro,
   velocidade_media:double,
   velocidade_instantanea:double,
   direcao: inteiro
}
```
### O que fazer?

Após armazenar os eventos nas suas respectivas listas, seu programa deve manipular os eventos armazenados nas listas, conforme os seguintes comandos:  

1) R dia/mes/ano hora:min - Remover o evento que ocorreu na data especificada.
2) I x y - Imprimir os elementos no intervalo $[x,y]$
3) A x - Acessar o elemento $x$ 
4) B dia/mes/ano hora:min - Buscar um evento que ocorreu na data especificada
5) P x y - Podar(remover) todos os elementos no intervalo $[x, y]$     
5) F - Fim dos comandos

### Considerações:

1) Os valores de $x$ e $y$ podem ser negativos, o que deve levar o acesso a acontecer do último para o primeiro elemento;
2) A lista de *todos* os eventos será criada sempre inserindo os novos eventos no __final__;
3) Existem dois momentos de entrada do programa:
   * informe do tipo de sensor (1 - temperatura; 2 - massas de ar) e nome do arquivo onde estão as informações;
   * Informe dos Comandos que precisam ser executados; 

Veja abaixo os exemplos de como o seu programa será executado:
```csh
> sensor 1 nome_arquivo_temperatura.txt
```
```csh
> sensor 2 nome_arquivo_massas_de_ar.txt
```


### Nomeclaturas

1) O arquivo com o seu programa (solução) deve ter o seguinte nome: sensor.c

### Como submeter o seu programa

1) Deve ser submetido via colab.
2) Somente o arquivo __sensor.c__ precisa ser enviado.

### Comandos extras.

A seguir você vai ver algumas dicas de como a linguagem C dá suporte a leitura de dados via arquivo e como você pode ler informações passadas via linha de comando.

```C
#include "stdio.h"
int main(char *argv[], int argc){
   int tipo = (int)(argv[1]);
   char nome_arquivo = argv[2];

   FILE *arq = fopen(nome_arquivo, "r");

   fscanf(arq,<mascara>,<lista de variáveis>); 
}
```

### Resumo da tarefa
1. Instanciar a lista para o tipo de medição informado
2. Ler e armazenar todas as informações do arquivo na lista
3. Processar todos os comandos Conforme indicado na seção "O que fazer?"