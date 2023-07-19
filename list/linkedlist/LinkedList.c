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

void removeFirst (List* list){
    if(list->head == NULL){
        printf("Erro: lista vazia\n");
        return;
    }

    No* temp = list->head;
    list->head = list->head->next;
    free(temp);

}

void removeLast (List* list){
    if(list->head == NULL){
        printf("Erro: lista vazia\n");
        return;
    }

    if(list->head->next == NULL){
        free(list->head);
        list->head = NULL;
        return;
    }

    No* no = list->head;
    No* no_ant = NULL;
    while(no->next != NULL){
        no_ant = no;
        no = no->next;
    }

    free(no);
    no_ant->next = NULL;
}

void printList (List* list){
    if (list->head == NULL) {
        printf("Erro: lista vazia\n");
        return;
    }

    No* aux = list->head;
    int aux_num = 1;
    printf("Elementos da list:\n");
    while (aux != NULL) {
        printf("%d, { ", aux_num);
        printf("\n    Nome: %s, ", aux->func.nome);
        printf("\n    Matricula: %s, ", aux->func.matricula);
        printf("\n    Salario: %.2f \n}\n\n", aux->func.salario);
        aux = aux->next;
        aux_num++;
    }
}
