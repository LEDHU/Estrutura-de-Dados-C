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

}

void printStack(Stack* stack) {

}
