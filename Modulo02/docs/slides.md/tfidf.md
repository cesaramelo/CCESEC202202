---
marp: true
theme: gaia
title: Como calcular TF-IDF
---
<!-- _class: lead -->
# **Calculando TF-IDF** 
implementação do Índice Remissivo 

---
# Suposições para esse exemplo

1. Considere um livro com três páginas;
2. Todo o texto será considerado;
3. Cada página terá os seguintes textos
    - Página 1: Maria vai para praia tomar sol.
    - Página 2: Na praia havia uma barraca e uma cadeira .
    - Página 3: Praia e Sol combina com domingo.   
---
# Os passos

1. Limpeza dos dados 
2. Calcule a frequência das palavras, nas páginas e na obra;
3. Encontre o TF das palavras;
4. Encontre o IDF das palavras;
5. Encontre o TF-IDF das palavras;
---
# Passo 1: Limpeza

Palavra|
------ |
maria |
vai |   
para | 
praia| 
tomar | 
sol | 
na | 
havia |  
uma | 
barraca |
e | 
cadeira | 
combina |  
com | 
domingo | 

---

# Passo 2: frequência 

Palavra| Frequência |
------ | ---------- |
maria | 1 |
vai |  1 | 
para | 1 |
praia| 3 |
tomar | 1 |
sol | 2 |
na | 1 |
havia | 1 | 
uma | 2 |
barraca | 1 |
e | 2 |
cadeira | 1 |
combina | 1 | 
com | 1 |
domingo | 1 |

---
# Passo 3: Encontrar o TF das palavras nas páginas

\# de ocorrências da palavra na página dividido pelo # de palavras na página

Página 1: Maria vai para praia tomar sol

Palavra| TF   |
-------| --   |
maria  | 0.16 |
vai    | 0.16 |
para   | 0.16 |
praia  | 0.16 |
tomar  | 0.16 |
sol    | 0.16 |

---
# Passo 3: TF em todo o texto

Palavra| Frequência | Página 1| Página 2 | Página 3|
------ | ---------- | --------| ------| ------ |
maria | 1 | 0.16 | 0.0 | 0.0 |
vai |  1 |  0.16 | 0.0 | 0.0 |
para | 1 | 0.16 | 0.0 | 0.0 |
praia| 3 | 0.16 | 0.12 | 0.16 |
tomar | 1 | 0.16 | 0.0 | 0.0 |
sol | 2 | 0.16 | 0.0 | 0.16 |
na | 1 |  0.0 |  0.12 | 0.0 |
havia | 1 | 0.0 | 0.12 | 0.0 | 
uma | 2 | 0.0 | 0.25 | 0.0 |
barraca | 1 | 0.0 | 0.12 | 0.0 |
e | 2 | 0.0 |0.12 | 0.16 | 
cadeira | 1 | 0.0 | 0.12 | 0.0 | 
combina | 1 | 0.0 | 0.0| 0.16 |
com | 1 | 0.0 | 0.0 | 0.16 |
domingo | 1 | 0.0 | 0.00| 0.16 |

--- 

# Passo 4: Encontrar IDF das palavras

IDF = $ln(\#\_de\_páginas/\#\_de\_páginas\_que\_contém\_palavra) $

Palavra| IDF        |
------ | ---------- |
maria | $ln(3/1) = 1.09$ |
vai |  1.09 | 
para | 1.09 |
praia| $ln(3/3) = 0$ |
tomar | 1.09 |
sol | $ln(3/2) = 0.41$ |
na | 1.09 |
havia | 1.09 | 
uma | 1.09 |
barraca | 1.09 |
e | 0.41 |
cadeira | 1.09 |
combina | 1.09 | 
com | 1.09 |
domingo | 1.09 |

---
# Passo 5: Encontrar TF-IDF das palavras em cada página

IDF = $ln(\#\_de\_páginas/\#\_de\_páginas\_que\_contém\_palavra) $

Palavra| Página 1 | Página 2 | Página 3 |
------ | -------- | -------- | -------- | 
maria | $0.16\times1.09 = 0.1744$ | 
vai |  $0.1744$  | 
para | $0.1744$ |
praia| $0.16\times0.0 = 0.0$ | $0.12\times0.0 = 0.0$ | $0.16\times0.0 = 0.0$ | 
tomar | $0.16\times1.09 = 0.1744$ |
sol | $0.16\times0.41 = 0.0656$ |
na | | $0.12\times1.09 = 0.1308$ | 
havia | | $0.1308$ | | 
uma | | $0.1308$ |
barraca | | $0.12\times1.09=0.1208$ |
e | | $0.12\times0.41 = 0.0492$ | $0.16\times0.41=0,0656$| 
cadeira | | $0.12\times1.09=0.1208$ | |
combina | | | $0.16\times1.09= 0.1744$ |
com | | | $0.1744$ |
domingo| | | $0.1744$ |

----

# Analise do TF-IDF Calculado

Palavra\pagina | maria|vai|para|praia|tomar|sol|na|havia|uma|barraca|e|cadeira|combina|com|domingo|
------- | -----|---|----|-----|-----|---|--|-----|---|-------|-|-------|-------|---|-------|
\# 1|0.1744|0.1744|0.1744|0|0.1744|0.0656|0|0|0|0|0|0|0|0|0
\# 2|0|0|0|0|0|0|0.1308|0.1308|0.1308|0.1208|0.0492|0.1208|0|0|0
\# 3|0|0|0|0|0||0|0|0|0|0.0656|0|0.1744|0.1744|0.1744

---

# Critério de seleção por agrupamento 

Palavra|Pagina 1|Pagina 2|Pagina 3 | Limite superior | Limite inferior (75\%)|
-------|--------|--------|--------| ------ | ------ |
B | ||| 0.1208 | 0.0906 
barraca|0|$0.1208$|0| ||
C ||| | 0.1744 | 0.1308
cadeira|0|0.1208|0 ||
com|0|0|$0.1744$ | | | 
combina|0|0|0.1744| |
D|0|0|| 0.1744 | 0.1308
domingo|0|0|||
E|0||| 0.0656 | 0.0492 
e|0|0.0492||| 
H|||| 0.1308 | 0.0981
havia|0|$0.1308$|0||
M|||| 0.1744 | 0.1308
maria|0.1744|0|0||
N|||| 0.1308 | 0.0981
na|0|$0.1308$|0||
P|||| 0.1744 | 0.1308
para|$0.1744$|0|0| 0.1744 | 0.1308
praia|0|0|0| |
S|||| 0.0656 | 0.0492
sol|$0.0656$|0|0| |
T|||| 0.1744 | 0.1308
tomar|$0.1744$|0|0| 0.1744 | 0.1308
U|||| 0.1308 | 0.0981
uma|0|$0.1308$|0||
V|||| 0.1744 | 0.1308
vai|0.1744|0|0||

---
# Critério de seleção global 

Palavra|Pagina 1|Pagina 2|Pagina 3 | Limite superior | Limite inferior (85\%)|
-------|--------|--------|--------| ------ | ------ |
| ||| | 0.1744 | 0.1482 
B | ||| |  
barraca|0|$0.1208$|0| ||
C ||| | | 
cadeira|0|0.1208|0 ||
com|0|0|$0.1744$ | | | 
combina|0|0|0.1744| |
D|0|0|| |
domingo|0|0|||
E|0||| | 
e|0|0.0492||| 
H|||| |
havia|0|$0.1308$|0||
M|||| |
maria|0.1744|0|0||
N|||| |
na|0|$0.1308$|0||
P|||| |
para|$0.1744$|0|0| 0.1744 | 0.1308
praia|0|0|0| |
S|||| 0.0656 | 0.0492
sol|$0.0656$|0|0| |
T|||| |
tomar|$0.1744$|0|0| 0.1744 | 0.1308
U|||| |
uma|0|$0.1308$|0||
V|||| |
vai|0.1744|0|0||
---
<!-- _class: lead -->

# Obrigado!
boa sorte