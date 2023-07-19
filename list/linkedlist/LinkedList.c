#include <stdio.h>
#include <stdlib.h>

typedef struct Funcionario {//objeto
    char nome[50];
    char matricula[12];
    float salario;
} Funcionario;

typedef struct No {//no
    Funcionario func;
    struct No* next;
} No;

typedef struct List {//variaveis de uma lita unicamente encadeada
    No* head;
} List;

List* constList() {//construtor
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

int isEmpty(List* list) {
    return list->head == NULL;
}
