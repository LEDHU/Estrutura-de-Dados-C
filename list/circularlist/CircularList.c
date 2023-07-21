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
        novoNo->next = list->head;
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
        novoNo->next = list->head;
    }
    else{
        No* last = list->head;
        while (last->next != list->head){
            last = last->next;
        }
        last->next = novoNo;
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

        if(list->head->next == NULL){
            list->head = NULL;
        }
        else{
            No* temp = list->head;

            while (last->next != list->head){
                last = last->next;
            }

            list->head = list->head->next;
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
            aux = aux->next;
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
    List* list = constList();

    Pessoa p1 = {"Joao", "111.111.111-11", "1.111.111", "01/01/2001", "(11)11111-1111");
    Pessoa p2 = {"Maria", "222.222.222-22", "2.222.222", "02/02/2002", "(22)22222-2222");
    Pessoa p3 = {"Gustavo", "333.333.333-33", "3.333.333", "03/03/2003", "(33)33333-3333");
    Pessoa p4 = {"Aline", "444.444.444-44", "4.444.444", "04/04/2004", "(44)44444-4444");


    insertFirst(list, p1);
    insertFirst(list, p2);
    insertFirst(list, p3);
    insertLast(list, p4);


    printList(list);

    removeFirst(list);
    removeLast(list);

    printList(list);

    free(list);

    return 0;
}
