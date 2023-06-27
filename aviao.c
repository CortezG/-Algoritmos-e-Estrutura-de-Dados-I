
#include <stdio.h>
#include <stdlib.h>
#include "aviao.h"

void inicializarFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

void adicionarAviao(Fila* fila, Aviao aviao) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->aviao = aviao;
    novoElemento->proximo = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novoElemento;
        fila->fim = novoElemento;
    } else {
        fila->fim->proximo = novoElemento;
        fila->fim = novoElemento;
    }

    printf("Aviao adicionado a fila de espera\n");
}

void listarNumeroAvioes(Fila fila) {
    int count = 0;
    Elemento* atual = fila.inicio;

    while (atual != NULL) {
        count++;
        atual = atual->proximo;
    }

    printf("N de aviões na fila: %d\n", count);
}

void autorizarDecolagem(Fila* fila) {
    if (fila->inicio == NULL) {
        printf("Nenhum aviao na fila \n");
        return;
    }

    Elemento* primeiroElemento = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    printf("Aviao %s decolando\n", primeiroElemento->aviao.nome);
    free(primeiroElemento);
}

void listarAvioesEspera(Fila fila) {
    if (fila.inicio == NULL) {
        printf("Nenhum aviao na fila \n");
        return;
    }

    printf("Avioes na fila de espera:\n");

    Elemento* atual = fila.inicio;

    while (atual != NULL) {
        printf("Id: %d, Nome: %s\n", atual->aviao.identificador, atual->aviao.nome);
        atual = atual->proximo;
    }
}

void listarPrimeiroAviao(Fila fila) {
    if (fila.inicio == NULL) {
        printf("Nenhum aviao na fila\n");
        return;
    }

    printf("Primeiro aviao da fila:\n");
    printf("Id: %d, Nome: %s\n", fila.inicio->aviao.identificador, fila.inicio->aviao.nome);
}
