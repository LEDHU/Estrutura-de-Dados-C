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
