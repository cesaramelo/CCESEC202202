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

![width:1000px](imgs/representa.svg)

---
# Elemento da Lista
1. __Representação__ 
![width:350px](imgs/elemento_lse.svg)
2. __Definição__                           
```C                                                        
 typedef struct elem_lse{                          
    int cargautil;// carga util            
    struct elem_lse* prox;// endereco prox 
 } t_elemento_lse;                                        
 ```                                       

----
# Playlist de música 

1. As últimas músicas tocadas
    * Como a lista será organizada?
    * Onde deve ocorrer as inserções?
2. As músicas mais tocadas
    * Na sua conta?
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
# Neutralização de ED

1. Acoplamento de tipo de dados e estrutura de armazenamento
    * A lista criada até agora aceita apenas cargautil de valor inteiro
2. Armazenamento de mais informações na lista implica em:
    - Alterar assinaturas das operações;
        - lista de novos itens que definem a __cargautil__
    - Alterar a lógica das operações
        - qual valor retornar entre os muito armazenados?
        - É possível que precise retornar todos.

----
# Neutralização de ED: o Tipo ponteiro void*

    uma representação sem tipo associado que permite armazenar endereços de memória de qualquer tipo de dado.


![width:25cm](imgs/void.svg)

---
# Neutralização da ED: Implementação

1. Trocar todos as referências do __int__ para __void*__;
2. Criar as cargas que serão armazenadas no código de quem está usando a Lista;
3. Qualquer solução deve passar a referência (endereço memória) da carga que vai na lista;

---
# Casos de uso

1. Lista com as informações __matricula__, __notafinal__, __nro_faltas__.
2. Lista com as informações __coordenadaX__, __coordenadaY__, __temperatura__.
3. Lista com as informações __hora__, __minuto__, __segundo__, __nro_evento__ $\in [1,5]$ 