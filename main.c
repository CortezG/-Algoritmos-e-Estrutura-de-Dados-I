#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    Node* raiz = criarArvore();

    // Inserindo os elementos na árvore
    raiz = inserir(raiz, 24);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 32);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 29);
    raiz = inserir(raiz, 35);

    printf("Árvore em ordem crescente: ");
    imprimirArvore(raiz);
    printf("\n");

    printf("Quantidade de elementos na árvore: %d\n", contarElementos(raiz));

    int chaveBusca = 12;
    Node* resultado = buscar(raiz, chaveBusca);
    if (resultado != NULL)
        printf("Elemento %d encontrado na árvore.\n", chaveBusca);
    else
        printf("Elemento %d não encontrado na árvore.\n", chaveBusca);

    printf("Percorrendo a árvore em Pré-ordem: ");
    percorrerPreOrdem(raiz);
    printf("\n");

    printf("Percorrendo a árvore em Em-ordem: ");
    percorrerEmOrdem(raiz);
    printf("\n");

    printf("Percorrendo a árvore em Pós-ordem: ");
    percorrerPosOrdem
