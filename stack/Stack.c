#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
    char nome[50];
    char matricula[12];
    int faltas;
    float media;
} Aluno;

typedef struct No {
    Aluno aluno;
    struct No* next;
} No;

typedef struct Stack {
    No* topo;
} Stack;

Stack* constStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->topo = NULL;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->topo == NULL;
}

void push(Stack* stack, Aluno aluno) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->aluno = aluno;
    novoNo->next = NULL;

    if (stack->topo == NULL) {
        stack->topo = novoNo;
    } else {
        novoNo->next = stack->topo;
        stack->topo = novoNo;
    }
}

Aluno pop(Stack* stack) {
    Aluno alunoParaRemover;

    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia\n");
        return alunoParaRemover;
    }

    alunoParaRemover = stack->topo->aluno;

    No* temp = stack->topo;
    stack->topo = stack->topo->next;
    free(temp);

    return alunoParaRemover;
}

void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Pilha vazia\n");
        return;
    }

    printf("Elementos da stack:\n");

    No* aux = stack->topo;
    int aux_num = 1;
    while (aux != NULL) {
        printf("%d, {\n", aux_num);
        printf("    Nome: %s,\n", aux->aluno.nome);
        printf("    Matricula: %s,\n", aux->aluno.matricula);
        printf("    Falta: %d,\n", aux->aluno.faltas);
        printf("    Media: %.2f\n}\n\n", aux->aluno.media);
        aux = aux->next;
        aux_num++;
    }
}

int main(void) {
    Stack* stack = constStack();

    Aluno a1 = {"Eduardo", "RA00008400000", 12, 9.8};
    Aluno a2 = {"Luis", "RA0000888888", 10, 9.0};
    Aluno a3 = {"Joao", "RA00008415000", 8, 8.0};
    Aluno a4 = {"Felipe", "RA0040888888", 6, 7.0};

    push(stack, a1);
    push(stack, a2);
    push(stack, a3);
    push(stack, a4);

    printStack(stack);

    pop(stack);
    pop(stack);

    printStack(stack);

    free(stack);

    return 0;
}
