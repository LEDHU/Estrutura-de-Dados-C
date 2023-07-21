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

}

void removeFirst (List* list){

}

void removeLast (List* list){

}

void printList (List* list){

}

int main(){

}
