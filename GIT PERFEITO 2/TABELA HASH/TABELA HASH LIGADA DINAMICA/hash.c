#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

No* criarNo(Paciente paciente) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->paciente = paciente;
        novoNo->prox = NULL;
    }
    return novoNo;
}

int calcularIndice(int codigo) {
    return codigo % 100;
}

void inserirPaciente(TabelaHash* tabela, Paciente paciente) {
    int indice = calcularIndice(paciente.codigo);
    No* novoNo = criarNo(paciente);

    if (novoNo != NULL) {
        if (tabela->tabela[indice] == NULL) {
            tabela->tabela[indice] = novoNo;
        } else {
            No* atual = tabela->tabela[indice];
            while (atual->prox != NULL) {
                atual = atual->prox;
            }
            atual->prox = novoNo;
        }
    }
}

Paciente* buscarPaciente(TabelaHash tabela, int codigo) {
    int indice = calcularIndice(codigo);
    No* atual = tabela.tabela[indice];

    while (atual != NULL) {
        if (atual->paciente.codigo == codigo) {
            return &atual->paciente;
        }
        atual = atual->prox;
    }

    return NULL;
}

void removerPaciente(TabelaHash* tabela, int codigo) {
    int indice = calcularIndice(codigo);
    No* atual = tabela->tabela[indice];
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->paciente.codigo == codigo) {
            if (anterior == NULL) {
                tabela->tabela[indice] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}
