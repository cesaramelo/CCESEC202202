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
# Algoritmos e Estruturas de Dados II

<!-- 2022/1 - Ano 2022 -->


----
# Ementa

Noções de complexidade de algoritmos. Algoritmos de ordenação

quadráticos, lineares e de custo ótimo. Algoritmos de busca sequencial

e binária. Tabela Hash. Processamento de cadeias de caracteres.

Árvores (Árvores Binárias de Busca e Árvore Balanceadas).

Representação de grafos e Algoritmos de Caminhamento, Aplicações:

Ordenação topológica e menor caminho.


---
# Objetivo

Avaliar a eficiência de rotinas computacionais construídas com estruturas

de dados básicas e avançadas. Experimentar formas diferentes de

implementação de algoritmos, em especial o emprego do conceito de

encapsulamento de dados. Comparar os diversos algoritmos de busca e

ordenação. Contribuir para o desenvolvimento da criatividade e do

pensamento lógico do aluno, peças chaves para a construção de rotinas

computacionais eficientes.


---
# Procedimentos de avaliação

Trabalho Prático: TP Avaliação Teóricas: AT

Nota Parcial: NP = $(0.75 * TP + 0.25 * AT)$
Média Parcial: MP = $(NP1 + NP2 + NP3 + NP4)/4$
Media Final = $(2*MP + Prova final)/3$

1. Prova de segunda chamada serão realizadas somente com
apresentação de devida justificativa, em data única.
2.  Será considerado aprovado o aluno que obtiver média final maior
igual a 5(cinco).


---
# Procedimento de Ensino e de Aprendizagem

* Aulas serão realizadas me modalidade híbrida;
* Locais:
    * Às segunda-feiras no laboratório 1, prédio do ICOMP
    * Às quarta-feiras e às sexta-feiras no auditório 2, prédio do ICOMP-TEC.

* Conteúdo teórico ficará disponível em vídeo no colabweb
https://colabweb.ufam.edu.br/course/view.php?id=781.

* As atividades práticas serão desenvolvidas em equipes e submetidas via
colab.

* O código implementado deve seguir padrões de documentação e construção apresentado na primeira semana de aula do curso.



---
# Referências

* CELES, Waldemar; CERQUEIRA, Renato; RANGEL, José Lucas. Introdução a Estrutura de Dados: com Técnicas de Programação em C. Editora Campus, 2008.

* Zivianni, N. Projeto de Algoritmos com Implementação em Pascal e C. Cengage Learning, 2010.

* Thomas H. Cormen; Charles E. Leiserson; Ronald L. Rivest.

* Algoritmos - Teoria e Prática -, Campus Editora, 2008.


---
# Conteúdo Programático

* Quatro módulos
* Todos os módulos têm o mesmo peso na nota obtida;
* Complexidade de cada módulo é inerente ao assunto
* 03 módulos 10 aulas e 01 módulo com 15 aulas;



---
# Conteúdo Programático: TAD

* Tipo Abstrato de Dados; Encapsulamento (dados privados + interface públicas)

* Array Dinâmico, revisão de vetor;

* Fila, Fila de Prioridade, revisão lista + novidade heap
* Pilha, pilha neutra (void \*)


---
# Conteúdo Programático: Dicionários

* Dicionários Estáticos (Busca Sequencial, Binária)
* Dicionários Semi-Estáticos (Espalhamento Perfeito, e com Endereçamento Aberto)
* Dicionário Dinâmico: Tabelas de Dispersão com Encadeamento.
* Dicionários Dinâmico: Árvores Binárias, Árvores Balanceadas (AVL, Trie)

---
# Conteúdo Programático: Ordenação

* Bolha, Inserção, Seleção O(n2)
* HeapSort, QuickSort, MergeSort O(nlog(n)) Divisão e Conquista, Estruturas de Dados ótimas
* CountingSort, Radix, BucketSort O(n)

---
# Conteúdo Programático: Grafo

* Grafos: Representação em Matriz e Lista de Adjacência;

* Caminhamento em Profundidade e em largura

* Aplicação: Menor Caminho

---
# Sobre Eficiência

Contexto

* O maior salário da empresa?
* Melhor rota entre dois locais de uma cidade?
* Qual é o melhor algoritmo?
* Uma lista de alunos ordenada por nota de prova?
* Quais são as lojas com os melhores preços de computadores? 
* É aquele que consigo implementar no menor tempo?
* É aquele que o livro me indicou?


---
# Eficácia versus Eficiência

 s. f. Qualidade daquilo que alcança os  resultados planejados; característica  do que produz os efeitos esperados, do  que é eficaz.Capacidade de  desenvolver tarefas ou objetivos de  modo competente;  produtividade.Etimologia (origem da  palavra eficácia). Do latim efficacia.ae. 
 
 s. f. Capacidade de realizar tarefas ou  trabalhos de modo eficaz e com o mínimo  de desperdício; produtividade.Tendência ou  aptidão para ser efetivo; capacidade de  realizar ou desenvolver alguma coisa  demonstrando eficácia;  efetividade. Particularidade demonstrada por  pessoas que conseguem produzir um ótimo  rendimento, quando realizam alguma coisa;  característica do que é eficaz. 
 
Etimologia (origem da palavra eficiência). Do latim efficientia.ae.

---
# Eficiência 

Como medir a eficiência de um algoritmo?

1. Quais são os recursos?
    * Processador
    * Memória

2. Que operações demandam esses recursos?  
    * Ler e escrever na memória
    * Comparar valores 
    * Manter valores armazenados em memória

É impossível ou muito  difícil considerar __Todos__ as  operações


---
# O algoritmo que calcula a média de notas de uma turma

```C
int main() {
    int n; 
    scanf("%d", &n);  
    for (int i=0;i<n;i++){  
        scanf("%lf%lf",&nota1,&nota2);  
        double media = (nota1+nota2)/2.0;  
        printf("%.2lf\n",media); 
    }
}
```
1. O custo depende do tamanho __n__ da instância (a turma)!  
2. Operações são  independentes dos valores  usados;  
3. A quantidade de memória  usada é sempre a mesma;

---
# Outra forma de resolver
```C
int main() { // A quantidade de memória  usada é MAIOR; 

    int n; scanf("%d", &n); 
    double notas[2*n];

    for (int i=0;i<n;i++){

        scanf("%lf%lf",&notas[2*i],&notas[2*i+1]);
        double media = (notas[2*i]+notas[2*i+1])/2.0;
        printf("%lf\n", media);
    }
}
```

---
# Random Access Machine (RAM)

* Precisamos de um modelo que seja genérico e independente da máquina/linguagem usada.
* Vamos considerar uma Random Access Machine (RAM)
* Cada operação simples (ex: +, −, ←, Se) demora 1 passo
* Ciclos e procedimentos, por exemplo, não são instruções simples!
* Cada acesso à memória custa também 1 passo
* Medir tempo de execução... contando o número de passos de acordo com o
tamanho da entrada: T(n)

---
# Random Access Machine (RAM)
```C
int conta = 0;

for (int i=0; i<n; i++)
    if (v[i] == 0) conta++;

```
* Declaração variável : 2
* Atribuições: 2
* Comparação "menor que": $n+1$
* Comparação "igual a": $n$
* Acesso a um vetor: $n$
* Incremento Entre $n$ e $2n$ (depende dos zeros)


---
# Random Access Machine (RAM)

## Um programa simples

```C 
int conta = 0;

for (int i=0; i<n; i++)
    if (v[i] == 0) conta++;
```

* Custo do pior cenário

    T(n) = 2 + 2 + (n+1) + n + n + 2n = 5 + 5n

* Custo do melhor cenário

    T(n) = 2 + 2 + (n+1) + n + n + n = 5 + 4n


---
# Tipos de Análise de Algoritmo

## Análise do Pior Caso: (o mais usual)

    * T(n) = máximo tempo do algoritmo para qualquer entrada de tamanho n

## Análise Caso Médio: (por vezes)

    * T(n) = tempo médio do algoritmo para todas as entradas de tamanho n
    * Implica conhecer a distribuição estatística das entradas
## Análise do Melhor Caso: ("enganador”)
    * Um algoritmo que é rápido para algumas entradas


---
# Tipos de Análise de Algoritmo

| Nro de  Passos ||Pior|
 | :- |
Médio

Melhor

||1 2 3 4 5 6 N| Tamanho da  instância |
 | :- |


---
# Análise Assintótica

É um método de descrição de comportamento feito a partir da definição de limites.

Uso em computação:

* Algoritmo tem uma função f(.) de custo

* f(.) tem um comportamento que pode ser descrito por limites;

* Usa-se uma notação específica: O, Ω, Θ (e também o, ω)

* Permite "simplificar" expressões como a anteriormente mostrada focando apenas nas ordens de grandeza

---
# Análise Assintótica: Ozão O(.)

$f(n) ∈ O(g(n))$ (limiar superior)

Significa que g(n) é um limite superior de f(n), sob as seguintes Condições:

* Tamanho da instância n precisa ser maior que um Certo tamanho No

* Existe uma constante $c > 0$, tal que $f(n) < c*g(n)$ para $n >= N_o$

---
# Notação Assintótica: Ozão O(.)

Descreve o limite superior de um comportamento.

A função de custo $f(.)$ será limitada superiormente a partir de um certo tamanho de problema.

* entre 1 e $N_o$;

* entre $N_o$ e $N$;


---
# Retomando o exemplo: Análise de pior caso

Um programa simples

```C
int conta = 0;

for (int i=0; i<n; i++)

    if (v[i] == 0) conta++;
```

$T(n) = O(n)$


---
# Cuidado com limites superiores largos.

Um programa simples E porque Não

```C
int conta = 0;

for (int i=0; i<n; i++)

    if (v[i] == 0) conta++;

```
---
# Exemplos Classes Assintóticas

| Classes | Representação |  Como fala?   | status |
| ------  | -----------   | ---           | ----  |
| constante| $O(1)$ |       O de 1 | melhor |
| logaritmica | $O(log(n))$ | O de $log(n)$| |
| linear | O(n) |O de n| |
| nlog(n) | $O(nlog(n))$| O nlogn||
| Quadrática| $O(n^2)$| O de n ao quadrado| |
| exponencial| $O(2^n)$| O de 2 elevado a N| Pior|

---
# Ordenação

* Três classes de algoritmos

1. Ordenação em tempo quadrático
2. Ordenação em tempo $nlog(n)$
3. Ordenação em tempo linear

---
# Odenação em tempo quadrático

1. Bolha
2. Inserção
3. Seleção

---
# Algoritmo geral  
1. divide o conjunto em dois (ordenados (__O__) e não ordenados (__NO__))
2. Retira um elemento do conjunto NO;
3. Insere o elemento identificado no passo 2 em __O__
4. Repete passo 2 e passo 3, até que NO seja vazio 

---
# Ordenação por seleção
```C
for(i=0;i< N-1; i++){
    imenor = i; // Limite do NO
    for (j=i+1;j<N;j++){
        if (vetor[j] < vetor[imenor])
            imenor = j;
    }
    trocar(vetor, i, imenor);
}
```
----
# Ordenação por inserção
```C
 for(i=1;i<N;i++){   
    aux=vetor[i];
    int j=i-1; // i é a o limite do conjunto NO
    while( (j>=0) && (vetor[j] > aux) ){    
        vetor[j+1]=vetor[j];
        j--;
    }
    vetor[j+1] = aux;
 }
```

 ---
 # Ordenação Bolha
 ```C
for (i=0;i<N-1;i++){
    for(j=N-1;j>i;j--){ // i limita o conjunto NO
        if (vetor[j]>vetor[j-1]){
            trocar(vetor,j,j-1);
        }
    }
}
 ```
---

