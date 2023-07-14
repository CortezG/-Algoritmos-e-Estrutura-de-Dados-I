#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void inicializarFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaVazia(Fila* fila) {
    return (fila->inicio == NULL);
}

No* criarNo(Paciente paciente) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    novoNo->info = paciente;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirPaciente(Fila* fila, Paciente paciente) {
    No* novoNo = criarNo(paciente);
    if (filaVazia(fila)) {
        fila->inicio = novoNo;
    } else {
        fila->fim->proximo = novoNo;
    }
    fila->fim = novoNo;
    printf("Paciente %s inserido na fila.\n", paciente.nome);
}

void removerPaciente(Fila* fila) {
    if (filaVazia(fila)) {
        printf("A fila está vazia!\n");
        return;
    }

    No* noRemovido = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    printf("Paciente %s removido da fila.\n", noRemovido->info.nome);
    free(noRemovido);
}

void exibirFila(Fila* fila) {
    if (filaVazia(fila)) {
        printf("A fila está vazia!\n");
        return;
    }

    printf("Pacientes na fila:\n");
    No* noAtual = fila->inicio;
    while (noAtual != NULL) {
        printf("Nome: %s, Idade: %d, Código: %d, CPF: %s\n",
               noAtual->info.nome, noAtual->info.idade,
               noAtual->info.codigo, noAtual->info.cpf);
        noAtual = noAtual->proximo;
    }
}
