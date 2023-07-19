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

void insertFirst (List* list, Funcionario func){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->func = func;
    novoNo->next = NULL;

    if(list->head == NULL){
        list->head = novoNo;
    } else {
        novoNo->next = list->head;
        list->head = novoNo;
    }
}

void insertLast (List* list, Funcionario func){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->func = func;
    novoNo->next = NULL;

    if(list->head == NULL){
        list->head = novoNo;
    } else {
        No* aux = list->head;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = novoNo;
    }
}

