#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

int pilhaVazia(Pilha* pilha) {
    return (pilha->topo == NULL);
}

void empilharLivro(Pilha* pilha, Livro livro) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->livro = livro;
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;
}

void desempilharLivro(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("A pilha de livros esta vazia.\n");
        return;
    }
    No* temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(temp);
}

void exibirTopo(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("A pilha de livros esta vazia.\n");
        return;
    }
    Livro topo = pilha->topo->livro;
    printf("Titulo: %s\n", topo.titulo);
    printf("Autor: %s\n", topo.autor);
    printf("Ano: %d\n", topo.ano);
}

void imprimirPilha(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("A pilha de livros esta vazia.\n");
        return;
    }

    No* atual = pilha->topo;
    printf("Pilha de livros:\n");
    while (atual != NULL) {
        Livro livro = atual->livro;
        printf("Titulo: %s\n", livro.titulo);
        printf("Autor: %s\n", livro.autor);
        printf("Ano: %d\n\n", livro.ano);
        atual = atual->prox;
    }
}

void liberarPilha(Pilha* pilha) {
    while (!pilhaVazia(pilha)) {
        desempilharLivro(pilha);
    }
    free(pilha);
}
