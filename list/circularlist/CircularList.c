#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa {
    char nome[50];
    char CPF[15]; // 'xxx.xxx.xxx-xx'
    char RG[10]; // 'x.xxx.xxx'
    char data_nasc[11]; // 'xx/xx/xxxx'
    char telefone[15]; // '(xx)xxxxx-xxxx'
} Pessoa;

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
        novoNo->next = novoNo; // Ajuste para apontar para si mesmo
    }
    else {
        No* last = list->head;
        while (last->next != list->head) {
            last = last->next;
        }

        novoNo->next = list->head;
        list->head = novoNo;
        last->next = novoNo; // Ajuste para apontar para o novo nó
    }
}

void insertLast(List* list, Pessoa p) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->pessoa = p;
    novoNo->next = NULL;

    if (list->head == NULL) {
        list->head = novoNo;
        novoNo->next = novoNo; // Ajuste para apontar para si mesmo
    }
    else {
        No* last = list->head;
        while (last->next != list->head) {
            last = last->next;
        }

        last->next = novoNo; // Ajuste para apontar para o novo nó
        novoNo->next = list->head; // Ajuste para apontar para o início da lista
    }
}

void removeFirst(List* list) {
    if (list->head == NULL) {
        printf("Erro: lista vazia.\n");
        return;
    }
    else {
        No* last = list->head;
        while (last->next != list->head) {
            last = last->next;
        }

        if (list->head->next == list->head) {
            free(list->head);
            list->head = NULL;
        }
        else {
            No* temp = list->head;

            list->head = list->head->next;
            last->next = list->head;

            free(temp);
        }
    }
}

void removeLast(List* list) {
    if (list->head == NULL) {
        printf("Erro: lista vazia.\n");
        return;
    }
    else {
        No* aux = list->head;
        No* aux_ant = NULL;
        while (aux->next != list->head) {
            aux_ant = aux;
            aux = aux->next;
        }

        if (aux_ant == NULL) {
            free(list->head);
            list->head = NULL;
        }
        else {
            aux_ant->next = list->head;

            free(aux);
        }
    }
}

void printList(List* list) {
    if (list->head == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No* aux = list->head;
    int aux_num = 1;
    printf("Elementos da lista:\n");
    do {
        printf("%d, { ", aux_num);
        printf("\n    Nome: %s, ", aux->pessoa.nome);
        printf("\n    CPF: %s, ", aux->pessoa.CPF);
        printf("\n    RG: %s, ", aux->pessoa.RG);
        printf("\n    Data de nascimento: %s, ", aux->pessoa.data_nasc);
        printf("\n    Telefone: %s \n}\n\n", aux->pessoa.telefone);

        aux = aux->next;
        aux_num++;
    } while (aux != list->head);
}

int menu(){
    printf("1 - Adicionar no inicio\n");
    printf("2 - Adicionar no final\n");
    printf("3 - Remover no inicio\n");
    printf("4 - Remover no final\n");
    printf("5 - Visualizar a lista\n");
    printf("0 - Sair do programa\n");

    int num;
    scanf("%d", &num);

    printf("\n");
    while (getchar() != '\n');

    return num;
}

void testManual(){
    List* list = constList();
    Pessoa p;

    char nome[50];
    char CPF[15];
    char RG[10];
    char data_nasc[11];
    char telefone[15];

    int op = 1;

    while(op != 0){
        op = menu();
        if(op == 1){
            printf("Nome: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0'; // Remove o '\n' da string lida
            printf("CPF: ");
            fgets(CPF, sizeof(CPF), stdin);
            CPF[strcspn(CPF, "\n")] = '\0';
            printf("RG: ");
            fgets(RG, sizeof(RG), stdin);
            RG[strcspn(RG, "\n")] = '\0';
            printf("Data de Nascimento: ");
            fgets(data_nasc, sizeof(data_nasc), stdin);
            data_nasc[strcspn(data_nasc, "\n")] = '\0';
            printf("Telefone: ");
            fgets(telefone, sizeof(telefone), stdin);
            telefone[strcspn(telefone, "\n")] = '\0';
            strcpy(p.nome, nome);
            strcpy(p.CPF, CPF);
            strcpy(p.RG, RG);
            strcpy(p.data_nasc, data_nasc);
            strcpy(p.telefone, telefone);
            insertFirst(list, p);
            //p = {"", "", "", "", ""};
        }
        else if(op == 2){
            printf("Nome: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0'; // Remove o '\n' da string lida
            printf("CPF: ");
            fgets(CPF, sizeof(CPF), stdin);
            CPF[strcspn(CPF, "\n")] = '\0';
            printf("RG: ");
            fgets(RG, sizeof(RG), stdin);
            RG[strcspn(RG, "\n")] = '\0';
            printf("Data de Nascimento: ");
            fgets(data_nasc, sizeof(data_nasc), stdin);
            data_nasc[strcspn(data_nasc, "\n")] = '\0';
            printf("Telefone: ");
            fgets(telefone, sizeof(telefone), stdin);
            telefone[strcspn(telefone, "\n")] = '\0';
            strcpy(p.nome, nome);
            strcpy(p.CPF, CPF);
            strcpy(p.RG, RG);
            strcpy(p.data_nasc, data_nasc);
            strcpy(p.telefone, telefone);
            insertLast(list, p);
            //p = {"", "", "", "", ""};
        }
        else if(op == 3){
            removeFirst(list);
        }
        else if(op == 4){
            removeLast(list);
        }
        else if(op == 5){
            printList(list);
        }
        else if(op == 0){
            printf("Ate mais");
        }
        else{
            printf("Opcao invalida, tente novamente");
        }
    }

    free(list);
}

void testAuto(){

        List* list = constList();

        Pessoa p1 = { "Joao", "111.111.111-11", "1.111.111", "01/01/2001", "(11)11111-1111" };
        Pessoa p2 = { "Maria", "222.222.222-22", "2.222.222", "02/02/2002", "(22)22222-2222" };
        Pessoa p3 = { "Gustavo", "333.333.333-33", "3.333.333", "03/03/2003", "(33)33333-3333" };
        Pessoa p4 = { "Aline", "444.444.444-44", "4.444.444", "04/04/2004", "(44)44444-4444" };

        insertFirst(list, p1);
        insertFirst(list, p2);
        insertFirst(list, p3);
        insertLast(list, p4);

        printList(list);

        removeFirst(list);
        removeLast(list);

        printList(list);

        free(list);
}

int main() {
    printf("1 - teste automatico\n");
    printf("2 - teste manual\n\n");
    int x;
    scanf("%d", &x);
    if(x == 1){
        testAuto();
    }
    else if(x == 2){
        testManual();
    }
    else{
        printf("Erro: recomece o programa");
    }
    return 0;
}
