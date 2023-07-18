#include <stdio.h>
#include <stdlib.h>
//fila de produto

typedef struct Produto {//objeto
    char nome[50];
    char codigo[12];
    int estoque;
    float preco;
} Produto;

typedef struct No {//no
    Produto produto;
    No* next;
} No;

typedef struct Queue {//variaveis de uma fila
    No* head;
    No* tail;
} Queue;

int isEmpty(Queue* queue) {
    return queue->head == NULL;
}

Queue* constQueue() {//construtor
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(Queue* queue, Produto p) {//enfilera
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->produto = p;
    novoNo->next = NULL;

    if (queue->head == NULL) {
        queue->head = novoNo;
        queue->tail = novoNo;
    } else {
        queue->tail->next = novoNo;
        queue->tail = novoNo;
    }
}

Produto dequeue(Queue* queue) {//desenfilera
    Produto p;
    if (queue->head == NULL) {
        printf("Erro: fila vazia\n");
        return p;
    }

    p = queue->head->produto;

    No* temp = queue->head;
    queue->head = queue->head->next;
    free(temp);

    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    return p;
}

void printQueue(Queue* queue) {
    if (queue->head == NULL) {
        printf("Erro: fila vazia\n");
        return;
    }

    No* aux = queue->head;
    int aux_num = 1;
    printf("Elementos da queue:\n");
    while (aux != NULL) {
        printf("%d, { ", aux_num);
        printf("\n    Nome: %s, ", aux->produto.nome);
        printf("\n    Codigo: %s, ", aux->produto.codigo);
        printf("\n    Estoque: %d, ", aux->produto.estoque);
        printf("\n    Preco: %.2f \n}\n\n", aux->produto.preco);
        aux = aux->next;
        aux_num++;
    }
}
