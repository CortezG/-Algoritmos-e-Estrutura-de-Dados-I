#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aviao {
    int identificador;
    char nome[50];
    // Outras características do avião
} Aviao;

typedef struct No {
    Aviao aviao;
    struct No* proximo;
} No;

typedef struct FilaDecolagem {
    No* primeiro;
    No* ultimo;
    int tamanho;
} FilaDecolagem;

FilaDecolagem* criarFila();
int estaVazia(FilaDecolagem* fila);
void listarNumeroAvioes(FilaDecolagem* fila);
void autorizarDecolagem(FilaDecolagem* fila);
void adicionarAviao(FilaDecolagem* fila, int identificador, char nome[]);
void listarAvioes(FilaDecolagem* fila);
void listarPrimeiroAviao(FilaDecolagem* fila);

FilaDecolagem* criarFila() {
    FilaDecolagem* fila = (FilaDecolagem*)malloc(sizeof(FilaDecolagem));
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
    return fila;
}

int estaVazia(FilaDecolagem* fila) {
    return fila->tamanho == 0;
}

void listarNumeroAvioes(FilaDecolagem* fila) {
    printf("Existem %d aviao(s) aguardando na fila de decolagem.\n", fila->tamanho);
}

void autorizarDecolagem(FilaDecolagem* fila) {
    if (estaVazia(fila)) {
        printf("Nao ha avioes na fila de decolagem.\n");
    } else {
        No* aviaoDecolagem = fila->primeiro;
        fila->primeiro = aviaoDecolagem->proximo;
        free(aviaoDecolagem);
        fila->tamanho--;
        printf("Autorizando a decolagem do aviao.\n");
    }
}

void adicionarAviao(FilaDecolagem* fila, int identificador, char nome[]) {
    No* novoAviao = (No*)malloc(sizeof(No));
    novoAviao->aviao.identificador = identificador;
    strcpy(novoAviao->aviao.nome, nome);
    novoAviao->proximo = NULL;

    if (estaVazia(fila)) {
        fila->primeiro = novoAviao;
    } else {
        fila->ultimo->proximo = novoAviao;
    }
    fila->ultimo = novoAviao;
    fila->tamanho++;
    printf("Aviao adicionado a fila de decolagem.\n");
}

void listarAvioes(FilaDecolagem* fila) {
    if (estaVazia(fila)) {
        printf("Nao ha avioes na fila de decolagem.\n");
    } else {
        No* atual = fila->primeiro;
        printf("Avioes na fila de decolagem:\n");
        while (atual != NULL) {
            printf("Identificador: %d, Nome: %s\n", atual->aviao.identificador, atual->aviao.nome);
            atual = atual->proximo;
        }
    }
}

void listarPrimeiroAviao(FilaDecolagem* fila) {
    if (estaVazia(fila)) {
        printf("Nao ha avioes na fila de decolagem.\n");
    } else {
        printf("Primeiro aviao na fila de decolagem:\n");
        printf("Identificador: %d, Nome: %s\n", fila->primeiro->aviao.identificador, fila->primeiro->aviao.nome);
    }
}

int main() {
    FilaDecolagem* fila = criarFila();

    adicionarAviao(fila, 1, "Aviao 1");
    adicionarAviao(fila, 2, "Aviao 2");
    adicionarAviao(fila, 3, "Aviao 3");

    listarNumeroAvioes(fila);
    listarAvioes(fila);
    listarPrimeiroAviao(fila);

    autorizarDecolagem(fila);

    listarNumeroAvioes(fila);
    listarAvioes(fila);
    listarPrimeiroAviao(fila);

    return 0;
}
