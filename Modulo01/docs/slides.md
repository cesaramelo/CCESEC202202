---
marp: true
title: Sobre listas
style: |
    section{
      justify-content: flex-start;
    }
    img[alt~="center"] {
      display: block;
      margin: 0 auto;
    }
---
# Sobre Lista

---
# Mas antes, Conceitos abstratos

| Conceito      | Descrição     | Atributos      |
| -----------   | -----------   | ---            |
| Carro         | automóvel, meio de transporte terrestre              |  nro rodas, cor, chasi, nro portas              |
| Celular       |  aparelho de comunicação| cor, modelo, marca,  sistema operacional, cameras, memória,  operadora, tamanho da tela |
| Lista         | agrupador de elementos |  Tamanho, estabelecer estado, estabelecer ordem



---

# Definição
__Lista lineares são estruturas de dados permitem o armazenamento de dados em memória de forma não contínua.__

----
# Propriedades
Uma lista $L$ com $n$ elementos tem as seguintes propriedades:

* Seja $l_i$ um elemento de L, então $l_{i-1}$ precede $l_i$ e $l_{i+1}$ sucede $l_i$;
    * Último elemento de $L$, $l_n$ não tem sucessor;
    * Primeiro elemento de $l$, $l_1$ não tem predecessor.
* Para acessar o elemento $l_i$ é preciso acessar todos os elementos $l_j$, $j=1,...,i-1$.


----
# Lista Simplemente Encadeada (LSE)

<table>
<tr>
<td>Representação gráfica</td> <td> Codificação</td> 
</tr>
<tr>
<td><img height=200pt src='imgs/representa.svg'></td>
<td>

```C
typedef struct elem_lse t_elemento_lse;
typedef struct {
    // end. do primeiro elemento
    t_elemento_lse* primeiro;

    // end. do último elemento
    t_elemento_lse* ultimo;
    
    // tamanho da lista
    int tamanho;
}t_lse;
```
</td>
</tr>
</table>

---
# Elemento da Lista
<table>
<tr>
<td>Representação gráfica</td> <td> Codificação</td> 
</tr>
<tr>
<!--td>![width:350px](imgs/elemento_lse.svg)</td-->
<td><img height=210pt src="imgs/elemento_lse.svg" alt> </td>
<td> 

```C                                                        
 typedef struct elem_lse{
    // carga útil
    int cargautil; 

    // endereço próximo elemento
    struct elem_lse* prox; 
 } t_elemento_lse;
 ```                                       

</td>
</tr>
</table>

----
# Caso de uso: Playlist de música 

1. As últimas músicas tocadas
    * Como a lista será organizada?
    * Onde deve ocorrer as inserções?
2. As músicas mais tocadas
    * Tem um limite?
    * Quem deve sair em uma lista com as 10+ tocadas?

---

# Operação Posicional: Inserir no **inicio**
__Permite que um novo elemento seja inserido no -inicio- da Lista $L$ de elementos__
1. Instanciar um novo elemento da lista
    * O elemento tem __carga util__ e __endereço do sucessor__
2. Redefinir o status de __primeiro__ elemento da lista
    * __Novo elemento__ deve ser conectado à lista
    * o campo __inicio__ da lista deve ser atualizado  
3. Atualizar a quantidade de elementos

---
# Operação Posicional: Inserir no **final**
__Permite que um novo elemento seja inserido no -final- da Lista $L$ de elementos__
1. Instanciar um novo elemento da lista
    * O elemento tem __carga util__ e __endereço do sucessor__
2. Redefinir o status de __último__ elemento da lista
    * __Novo elemento__ deve ser conectado à lista;
    * Identificar o elemento que possui o status de __último__ da lista;
    * Atualizar seu campo __prox__ com o endereço do novo elemento. 
3. Atualizar a quantidade de elementos

---
# Operação Posicional: Acessar
__Permite acessar um elemento da Lista $L$ em um determinada posição $i \in \{1,...N\}$.__

1. Garante o acesso em ordem natural $[1,N]$
    * $i = i \% N$, se $i != N$;
    * $i = N$, se $i = k*N, k \in [1,...,m]$;
    * $i = 0$ é considerado um valor inválido. 
2. Garante o acesso em ordem reversa $[-1,-N]$
    * $i = (i \% N) + (N+1)$, se $i != -N$
    * $i = 1$, se $i = k*N, k \in [-1,...,-m]$. 

---
# Operação Posicional: Remover do __inicio__

__Permite que o elemento com status de -primeiro- da Lista $L$ seja removido__

1. Identificar o elemento e armazenar o seu endereço
    * Use informação do campo __inicio__ da lista instanciada;
2. Atualizar o campo __inicio__ da lista
    * Use a informação no campo __prox__ do elemento identificado no passo 1;
3. Remover o elemento fisicamente da memória
    * Copie a informação no campo __cargautil__ do elemento identificado no passo 1;
    * Use o comando __free()__;
4. Retornar a informação copiada no passo anterior.


---
# Operação Posicional: Remover do __final__

__Permite que o elemento com status de -último- da Lista $L$ seja removido__

1. Identificar o elemento e armazenar o seu endereço
    * É preciso caminhar pela lista $L$ até o último elemento e idenficar o penúltimo elemento, conjuntamente;
2. Atualizar o status de -último- elemento da lista
    * Atualize a informação no campo __prox__ do penúltimo elemento identificado no passo 1;
3. Remover o elemento fisicamente da memória
    * Copie a informação no campo __cargautil__ do elemento com status -último- identificado no passo 1;
    * Use o comando __free()__;
4. Retornar a informação copiada no passo anterior.

----

# Outros tipos de Lista encadeada
![center](imgs/outraslistas.svg)

---
# Acomplamento entre a ED e Tipos

    A lista criada até agora aceita apenas cargautil de valor inteiro
```C
typedef struct elem_lse{                          
    int cargautil;      
    struct elem_lse* prox;// endereco prox 
 } t_elemento_lse;           

int acessar_lse(t_lse* lse, int pos){
void inserir_inicio_lse(t_lse* lse, int carga);
void inserir_final_lse(t_lse* lse, int carga);
int remover_inicio_lse(t_lse* lse);
int remover_final_lse(t_lse* lse);
```
---
# Neutralização da ED: Por que? 
    Armazenamento de mais informações na lista tem implicações na programação 
1. Alterar assinaturas das operações;
    * lista de novos itens que definem a __cargautil__
2. Alterar a lógica das operações
    * qual valor retornar entre os muito armazenados?
    * É possível que seja preciso retornar todos.

----
# Neutralização de ED: o Tipo ponteiro void*

| Definição | Representação | 
| --------- | -------------- |
| __Permite que a variável declarada <br> armazene endereços de memória <br> de qualquer tipo de dado.__          | ![width:15cm](imgs/void.svg) |

---
# Neutralização da LSE: Implementação

1. Trocar todos as referências do __int__ para __void*__;
2. Criar as cargas __no código__ de quem está usando a Lista;
    * Especialização fica na solução (__minhasolucao.c__);
3. Qualquer solução deve passar a referência (__endereço memória__) da carga que vai na lista;
    * Implemente uma função (__criar*__)para instanciar a carga;
4. Qualquer solução deve saber tratar a referência (__endereço de memória__)
    * Implemente uma função (__imprimir*__) para imprimir a carga; 

---
# Neutralização da ED LSE: Casos de Uso.

Considere a criação das seguintes Listas:
1. Lista de alunos da disciplina: __matricula__(int), __notafinal__(double), __nro_faltas__(int).
2. Lista de medidas de temperatura: __coordenadaX__(double), __coordenadaY__(double), __temperatura__(double).
3. Lista de eventos: __hora__(int), __minuto__(int), __segundo__(int), __nro_evento__(int) $\in [1,5]$ 

---
# Operações baseadas em conteúdo
A lista precisa ser manipulada a partir dos valores armazenados.
1. __Inserir__ mantendo a ordem estabelecida pelo valor dos elementos;
    * A ordem alfabética de nome de alunos;
    * A ordem temporal (datas) de uma coleta de eventos;
2. __Remover__ um elemento considerando alguma informação associada;
    * Matricula do aluno;
    * ID sensor;
3. __Buscar__ um elemento considerando alguma informação associada;
    * Nome da música;
    * Matricula do aluno;

---
# Neutralizando a lógica
<!--footnote Precisamos de uma lógica não especialista envolvendo as operações.-->

1. Considere a lógica da operação __buscar__
    * Percorrer a lista;
    * Comparar a informação na __cargautil__ com aquele procurada;
    * Retornar a __cargautil__ sempre que ela tiver a informação buscada;
2. Como realizar as comparações?
    * o tipo void* não permite operações de acesso especializada;
    * Veja o que acontece sempre que você programa usando o __void*__;

---
# Ponteiro para função: O que é.
<!--Uma função tem a sua assinatura associada a uma lógica.-->

1) Defina uma função a seguinte função:
```C
void __trocar(int *nro1, int* nro2){
    int aux;
    aux = *nro1;
    *nro1 = *nro2;
    *nro2 = aux;
    printf("trocar 1\n");
}
```
2) Agora defina uma função __main()__ com o seguinte código:
```C
int main(){
    int maior=10, menor=20;
    printf("%p",__trocar);
    __trocar(&maior,&menor);
}
```
3) Compile e execute o código 5x e veja o que acontece.

---
# Ponteiro para função: Como definir.

1) Escreva o seguinte código no arquivo **.c**, logo após os **#include**
```C
typedef void(*da_funcao_trocar)(int*, int*);
```
2) Na função principal escreva o seguinte código:
```C
// declarando uma variável 
da_funcao_trocar trocador;

// atribuindo um endereço para a variável
trocador = __trocar;

printf("%p\n", __trocar);
printf("%p\n", trocador);
```

---
# Ponteiro para função: como usar.

1) Escreva o seguinte código na função __main()__, compile, execute e anote o resultado
```C
int maior=10;
int menor=20;
__trocar(&maior, &menor);
printf("%d %d\n", maior, menor);
```
2) Altere o código, incluindo
```C
trocador = __trocar;

// chamada indireta da função
trocador(&maior, &menor);

printf("%d %d\n", maior, menor);
``` 

---
# Ponteiro para função: como usar na parametrização.
1) Inclua o seguinte código no arquivo **.c**
```C
void chamadora(da_funcao_trocar trocador, int nro_1, int nro_2){
    printf("%d %d\n", nro_1, nro_2);
    // chamada indireta da função
    trocador(&nro_1, &nro_2);
    //printf("%d %d\n", nro_1, nro_2);
}
```
2) Inclua o seguinte código na função __main()__
```C
chamadora(__trocar, maior, menor);
chamadora(__trocar2, maior, menor);
```
---
# e na LSE? Visão geral
![bg right w:600px](imgs/refactor-lse.svg)

---
# E na LSE? vamos refatorar.
![width:25cm](imgs/refatorar.svg)

---
# Refatorar LSE
1) Crie o novo arquivo **listase.h**
    * inclua a assinatura das funções;
    * remova os itens anteriores do arquivo **listase.c**
2) ainda no arquivo **listase.h**, inclua o seguinte código, logo após os **#include**;
```C
typedef void(*t_imprimir_lse)(void*);
typedef struct lse t_lse; 
```
---
# Vamos refatorar **listase.c**
1) no arquivo **listalse.c**, redefina a LSE incluindo
```C 
struct lse{
    t_elemento_lse* inicio;
    int tamanho;
    t_imprimir_lse impressora;
};
```
2) redefina a assinatura da função **criar_lse()**
```C
    t_lse* criar_lse(t_imprimir_lse imprimir){
        t_lse* nova  = malloc(sizeof(t_lse));
        nova->inicio = NULL;
        nova->impressora = imprimir;
        nova->tamanho=0;

        return nova;
    }
```
---
# Último ajuste, no listase.c
1) Inclua o código que percorre a lista imprimindo os elementos.
```C
void imprimir_lse(t_lse *lse){
    t_elemento_lse* cam = lse->inicio;
    while(cam!=NULL){
        lse->impressora(cam->cargautil);
        cam = cam->prox;
    }
}
```
---
# A sequência de chamadas na impressão
![w:600px center](imgs/imprimir_lse.svg)

---
# Inserir, Remover e Buscar baseado em conteúdo
1) Reconhecer o acomplamento da lógica ao tipo de dados;
2) Criar novas funções neutralizando as lógicas;
3) Criar um novo tipo Ponteiro para função;
4) Reimplementar a função que cria a lista;
---
# Alteração nas declarações (listase.h)
```C
typedef int (*t_comparar_lse)(void* carga_na_lista, void* nova_carga);

t_lse* criar_lse(t_imprimir_lse imprimir, t_comparar_lse comparar);
```

---
# Alteração no tipo LSE (listase.c)
```C
struct lse{
    t_elemento_lse* inicio; // Primeiro elemento
    int tamanho;
    t_imprimir_lse impressora; 
    t_comparar_lse comparar;
};
```
```C
t_lse* criar_lse(t_imprimir_lse impressora, t_comparar_lse comparar){
    t_lse* nova  = malloc(sizeof(t_lse));
    nova->inicio = NULL;
    nova->tamanho=0;
    nova->impressora = impressora;
    nova->comparar = comparar;

    return nova;
}
```
---
# Inserir um novo elemento
1) Encontrar a posição da inserção 
2) Caracterizar a posição
    * inicio
    * fim
    * meio
3) Conectar o novo elemento
4) Atualizar a lista se for o caso
![bg w:650px right](imgs/inserir_lse.svg)
---
# Buscar um novo elemento
1) Percorrer a lista;
2) Dois resultados são possíveis
    * Pertence à lista
    * Não pertence à lista
![bg w:650px right](imgs/buscar_lse.svg)    

---
# Remover um elemento
![bg w:650px right](imgs/remover_lse.svg)
1) Buscar um elemento
2) Caracterizar a sua posição
    * inicio da lista
    * demais elementos
3) Exceções
    - Remover o único elemento da lista;
    - Remover em uma lista vazia


---
# Atividade: criando e manipulando playlists
1) Apresente e implemente o conceito de um música;
    * use o __typedef__ para criar o tipo que representará o conceito;
2) Crie um arquivo chamado "playlist.c"
    * Defina o conceito de um playlist +10;
    * Defina o conceito de uma playlist aleatória;
    * Defina o conceito de uma playlist as últimas **k* tocadas;

---
# Fechamento

![w:22cm center](imgs/visao-geral.svg)

---
# Tipo Abstrato de Dado

1. Definição
2. Como são implementados
3. Exemplos de uso

---
# Contato

- Ana Machado
- apoiopedagogico@icomp.ufam.edu.br

---
# TAD, Definição

 __Representação de um conceito do mundo real a partir de suas características e comportamentos__;

## Como?
- Um conjunto bem definido de operações (interface)
- Ocultação da forma como essas características são representadas (encapsulamento);

---

# TAD, Representação Gráfica
![bg w:28cm center](imgs/representaTAD.png)

---
# Exemplos de TAD
1. Filas
2. Pilhas
3. Agenda
4. Plano de ação
5. Mapa geneológico

---
# TAD: Fila
![bg w:17cm right](imgs/fila.png)

## Definição

__É um tipo de coleção linear onde os elementos são organizados segundo uma ordem.__

## Políticas de gerenciamento

- FIFO
- Prioridade 
- WFQ

---
# Fila FIFO
- Inserções são feitas no final da fila;
- Remoções são feitas no início da fila.
- Primeiro retorna o elemento no início da fila. 

---
# Implementação de TADs

1. Definir o conjunto de operações (interface) do TAD
2. Escolher a Estrutura de Dados mais adequada

3. Estabelecer pré-condições e pós-condições de cada interação com o TIPO

## Exemplo: Inserir na Fila
- Nome: enfileirar()
- Pré-condição: Fila precisa existir
- Pós-condição: Elemento inserido

---
# Vamos implementar TAD Fila;

1. Interface?
    1. enfileirar()
    2. desenfileirar()
    3. tamanho_fila()
    4. primeiro_fila()
    5. vazia_fila()
    6. criar_fila(tamanho=0) 
2.  ED?
    1. ListaSE
    2. Vetor(Cenas dos próximos Cap.)