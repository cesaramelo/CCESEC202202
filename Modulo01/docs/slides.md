---
marp: true
title: Sobre listas
---
# Sobre Lista

---
# Mas antes, Conceitos abstratos

| Conceito      | Descrição     | Atributos      |
| -----------   | -----------   | ---            |
| Carro         | automóvel, meio de transporte terrestre              |  nro rodas, cor, chasi, nro portas              |
| Celular       |  aparelho de comunicação| cor, modelo, marca,  sistema operacao, cameras, memória,  operadora, tamanho da tela |
| Lista         | agrupador de elementos |  Tamanho, Tipo de Informação, Tem ordenação, 



---

# Definição
__Lista lineares são estruturas de dados permitem o armazenamento de dados em memória de forma não contínua.__

----
# Propriedades
Uma lista $L$ com $n$ elementos tem as seguintes propriedades:

* Seja $l_i$ um elemento de L, então $l_{i-1}$ prescede $l_i$ e $l_{i+1}$ sucede $l_i$;
    * Último elemento de $L$, $l_n$ não tem sucessor;
    * Primeiro elemento de $l$, $l_1$ não tem predecessor.
* Para acessar o elemento $l_i$ é preciso acessar todos os elementos $l_j$, $j=1,...,i$.


----
# Representação Gráfica

![Representa](imgs/representa.svg "Representação")

---
# Playlist de música 

1. As últimas músicas tocadas
    * Como a lista será organizada?
    * Onde deve ocorrer as inserções?
2. As músicas mais tocadas
    * Na sua conta?
    * Tem um limite?
    * Quem deve sair em uma lista com as 10+ tocadas?

