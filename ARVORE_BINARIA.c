#include "arvore_binaria.h"
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
struct Node {
    int chave;
    Node* esquerda;
    Node* direita;
};

// Função para criar e inicializar a árvore
Node* criarArvore() {
    return NULL;
}

// Função para inserir um elemento na árvore
Node* inserir(Node* raiz, int chave) {
    if (raiz == NULL) {
        Node* novoNo = (Node*)malloc(sizeof(Node));
        novoNo->chave = chave;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        return novoNo;
    }

    if (chave < raiz->chave)
        raiz->esquerda = inserir(raiz->esquerda, chave);
    else if (chave > raiz->chave)
        raiz->direita = inserir(raiz->direita, chave);

    return raiz;
}

// Função para imprimir a árvore em ordem crescente
void imprimirArvore(Node* raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esquerda);
        printf("%d ", raiz->chave);
        imprimirArvore(raiz->direita);
    }
}

// Função para contar quantos elementos tem na árvore
int contarElementos(Node* raiz) {
    if (raiz == NULL)
        return 0;
    else
        return 1 + contarElementos(raiz->esquerda) + contarElementos(raiz->direita);
}

// Função para buscar um elemento na árvore
Node* buscar(Node* raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave)
        return raiz;

    if (chave < raiz->chave)
        return buscar(raiz->esquerda, chave);
    else
        return buscar(raiz->direita, chave);
}

// Função para percorrer e mostrar as chaves em pré-ordem
void percorrerPreOrdem(Node* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        percorrerPreOrdem(raiz->esquerda);
        percorrerPreOrdem(raiz->direita);
    }
}

// Função para percorrer e mostrar as chaves em ordem
void percorrerEmOrdem(Node* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        percorrerEmOrdem(raiz->direita);
    }
}

// Função para percorrer e mostrar as chaves em pós-ordem
void percorrerPosOrdem(Node* raiz) {
    if (raiz != NULL) {
        percorrerPosOrdem(raiz->esquerda);
        percorrerPosOrdem(raiz->direita);
        printf("%d ", raiz->chave);
    }
}

// Função para liberar a memória ocupada pela árvore
void liberarArvore(Node* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}
