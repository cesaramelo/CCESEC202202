#include <stdio.h>

#include <stdlib.h>



// Definição da estrutura para os nós da lista encadeada

typedef struct Node {

    int value;

    struct Node* next;

} Node;



// Função auxiliar para criar um novo nó da lista

Node* createNode(int value) {

    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->value = value;

    newNode->next = NULL;

    return newNode;

}



// Função para inserir um nó no final da lista encadeada

void insertNode(Node** head, int value) {

    Node* newNode = createNode(value);

    if (*head == NULL) {

        *head = newNode;

    } else {

        Node* current = *head;

        while (current->next != NULL) {

            current = current->next;

        }

        current->next = newNode;

    }

}



// Função para concatenar duas listas encadeadas

Node* concatenateLists(Node* head1, Node* head2) {

    if (head1 == NULL) {

        return head2;

    }

    Node* current = head1;

    while (current->next != NULL) {

        current = current->next;

    }

    current->next = head2;

    return head1;

}



// Função para imprimir os valores de uma lista encadeada

void printList(Node* head) {

    Node* current = head;

    while (current != NULL) {

        printf("%d ", current->value);

        current = current->next;

    }

    printf("\n");

}



// Função para liberar a memória alocada para a lista encadeada

void freeList(Node* head) {

    Node* current = head;

    while (current != NULL) {

        Node* temp = current;

        current = current->next;

        free(temp);

    }

}



// Função para realizar o radix-sort

void radixSort(int arr[], int n) {

    // Encontra o maior valor absoluto no vetor

    int max = abs(arr[0]);

    for (int i = 1; i < n; i++) {

        if (abs(arr[i]) > max) {

            max = abs(arr[i]);

        }

    }



    // Executa o radix-sort para cada dígito

    for (int exp = 1; max / exp > 0; exp *= 10) {

        // Cria listas encadeadas vazias para cada dígito

        Node* buckets[20] = {NULL};



        // Distribui os valores para as listas encadeadas

        for (int i = 0; i < n; i++) {

            int digit = (arr[i] / exp) % 10;

            int index = digit + 9;  // Mapeia o intervalo [-9, 9] para [0, 18]

            insertNode(&buckets[index], arr[i]);

        }



        // Reconstrói o vetor original observando os agrupamentos nas listas encadeadas

        int index = 0;

        for (int i = 0; i < 20; i++) {

            Node* currentBucket = buckets[i];

            while (currentBucket != NULL) {

                arr[index++] = currentBucket->value;

                Node* temp = currentBucket;

                currentBucket = currentBucket->next;

                free(temp);

            }

        }

    }

}



int main() {

    int n;



    printf("Digite o tamanho do vetor: ");

    scanf("%d", &n);



    int arr[n];

    printf("Digite os elementos do vetor:\n");

    for (int i = 0; i < n; i++) {

        scanf("%d", &arr[i]);

    }



    printf("Array antes da ordenacao: ");

    for (int i = 0; i < n; i++) {

        printf("%d ", arr[i]);

    }

    printf("\n");



    radixSort(arr, n);



    printf("Array apos a ordenacao: ");

    for (int i = 0; i < n; i++) {

        printf("%d ", arr[i]);

    }

    printf("\n");



    return 0;

}