#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa{
    char nome[50];
    char CPF[14]; // 'xxx.xxx.xxx-xx'
    char RG[9]; // 'x.xxx.xxx'
    char data_nasc[10]; // 'xx/xx/xxxx'
    char telefone[14]; // '(xx)xxxxx-xxxx'
}Pessoa;


typedef struct No {
    Pessoa pessoa;
    struct No* next;
} No;

typedef struct List {
    No* head;
} List;

int isEmpty(List* list) {
    return list->head == NULL;
}

List* constList() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void insertFirst(List* list, Pessoa p) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->pessoa = p;
    novoNo->next = NULL;

    if (list->head == NULL) {
        list->head = novoNo;
        newNode->next = list->head;
    }
    else {
        No* last = list->head;
        while (last->next != list->head){
            last = last->next;
        }

        novoNo->next = list->head;
        list->head = novoNo;
        last->next = list->head;
    }
}

void insertLast(List* list, Pessoa p) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->pessoa = p;
    novoNo->next = NULL;

    if (list->head == NULL) {
        list->head = novoNo;
        newNode->next = list->head;
    }
    else{
        No* last = list->head;
        while (last->next != list->head){
            last = last->next;
        }
        last-> = novoNo;
        novoNo->next = list->head;
    }
}

void removeFirst (List* list){
    if(list->head == NULL){
        printf("Erro: lista vazia.\n");
        return;
    }
    else{
        No* last = list->head;
        while (last->next != list->head){
            last = last->next;
        }

        if(list->head.next == NULL){
            list->head = NULL;
        }
        else{
            No* temp = list->head;

            while (last->next != list->head){
                last = last->next;
            }

            list->head = list->head.next;
            last->next = list->head;

            free(temp);
        }
    }
}

void removeLast (List* list){
    if(list->head == NULL){
        printf("Erro: lista vazia.\n");
        return;
    }
    else{
        No* aux = list->head;
        No* aux_ant = NULL;
        while(aux->next != list->head){
            aux_ant = aux;
            aux = aux.next;
        }

        if(aux_ant == NULL){
            list->head = NULL;
        }
        else{
            aux_ant->next = list->head;
        }

        free(aux_ant);
    }
}

void printList (List* list){
    No* aux = list->head;

    int aux_num = 1;
    printf("Elementos da list:\n");
    while(aux->next != list->head){
        printf("%d, { ", aux_num);
        printf("\n    Nome: %s, ", aux->pessoa.nome);
        printf("\n    CPF:: %s, ", aux->pessoa.CPF);
        printf("\n    RG: %s, ", aux->pessoa.RG);
        printf("\n    Data de nascimento: %s, ", aux->pessoa.data_nasc);
        printf("\n    Telefone: %s \n}\n\n", aux->pessoa.telefone);

        aux = aux->next;
        aux_num++;
    }
}

int main(){

}
