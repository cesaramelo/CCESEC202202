# Atividades

## Uso de listas neutralizadas

Neste trabalho você precisará implementar uma lista que será capaz de armazenar um conjunto de dados gerado por diferentes sensores que detectam e registram os eventos em uma área monitorada.

Os sensores foram distribuídos para medir diferentes eventos, e.g., temperatura, movimento, luminosidade, umidade, velocidade do vento. Cada sensor portanto registra um tipo diferente de evento que tem seus atributos, que são representados de forma bastante particular.

Sua tarefa consiste em ler todas as medidas, armazenadas em um arquivo, e incluí-las na lista de eventos.

Cada medida tem os seguintes atributos:

```json
{'id_sensor':inteiro,
 'tipo':inteiro,
 'medida':{
    temperatura:double,
    umidade:inteiro,
    luminosidade: inteiro,
    velocidade_do_vento: double,
    movimento: inteiro
 },
 'data':{
    dia:inteiro,
    hora:inteiro,
    minuto:inteiro
 },
 'tempo':{
    hora:inteiro,
    minuto: inteiro,
    segundo: inteiro
 }
}
```

Após armazenar os eventos na lista, seu programa deve acessar os eventos gerado por sensores de um tipo específico, a ser informado, e agrupá-los em uma nova lista. 

Os eventos nessa nova lista deverão ser manipulados pelas operações posicionais definidas para a lista simplesmente encadeada.

As seguintes questões precisam ser observadas:
1) A lista de *todos* os eventos será criada sempre inserindo os novos eventos no __final__;
2) A lista com os eventos de um determinado sensor será construída sempre inserido os eventos no seu inicio.
3) As demais operações a serem realizadas na lista incluem:

    1. Imprimir um elemento k;
    2. Remover e imprimir do inicio;
    3. Remover e imprimir do final;
    4. Remover e imprimir eventos de uma data e tempo específico;

