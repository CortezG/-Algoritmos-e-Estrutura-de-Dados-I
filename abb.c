#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarArvore(Arvore* arvore) {
    arvore->raiz = NULL;
}

No* inserirNo(No* raiz, No* novoNo) {
    if (raiz == NULL) {
        return novoNo;
    }

    if (novoNo->valor < raiz->valor) {
        raiz->esquerda = inserirNo(raiz->esquerda, novoNo);
    } else {
        raiz->direita = inserirNo(raiz->direita, novoNo);
    }
    return raiz;
}

void adicionarArvore(Arvore* arvore, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    arvore->raiz = inserirNo(arvore->raiz, novoNo);
}

void listarNos(No* raiz) {
    if (raiz != NULL) {
        printf("Endereco: %p\n", raiz);
        printf("Esquerda: %p  Direita:%p\n", raiz->esquerda, raiz->direita);
        printf("Valor: %d\n", raiz->valor);
        listarNos(raiz->esquerda);
        listarNos(raiz->direita);
    }
}

void imprimirArvore(Arvore* arvore) {
    listarNos(arvore->raiz);
}

No* buscarNo(No* raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }

    if (raiz->valor == valor) {
        return raiz;
    }

    if (valor < raiz->valor) {
        return buscarNo(raiz->esquerda, valor);
    } else {
        return buscarNo(raiz->direita, valor);
    }
}

No* buscar(Arvore* arvore, int valor) {
    return buscarNo(arvore->raiz, valor);
}

int contarNos(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return (contarNos(raiz->esquerda) + 1 + contarNos(raiz->direita));
}

void preOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    printf("%d\n", raiz->valor);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

void inOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    inOrdem(raiz->esquerda);
    printf("%d\n", raiz->valor);
    inOrdem(raiz->direita);
}

void posOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf("%d\n", raiz->valor);
}
