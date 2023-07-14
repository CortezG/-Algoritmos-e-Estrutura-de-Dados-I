#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do avião
typedef struct Aviao {
    int id;
    char nome[50];
    // Outras características do avião
} Aviao;

// Estrutura do nó da pilha
typedef struct No {
    Aviao aviao;
    struct No* prox;
} No;

// Estrutura do hangar
typedef struct Hangar {
    No* topo;
    int tamanho;
} Hangar;

// Função para inicializar o hangar
void inicializarHangar(Hangar* hangar) {
    hangar->topo = NULL;
    hangar->tamanho = 0;
}

// Função para verificar se o hangar está vazio
int hangarVazio(Hangar* hangar) {
    return hangar->topo == NULL;
}

// Função para empilhar um avião no hangar
void empilharAviao(Hangar* hangar, Aviao aviao) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->aviao = aviao;
    novoNo->prox = hangar->topo;
    hangar->topo = novoNo;
    hangar->tamanho++;
}

// Função para desempilhar um avião do hangar
void desempilharAviao(Hangar* hangar) {
    if (hangarVazio(hangar)) {
        printf("O hangar está vazio.\n");
        return;
    }

    No* noRemovido = hangar->topo;
    hangar->topo = noRemovido->prox;
    free(noRemovido);
    hangar->tamanho--;
}

// Função para listar o número de aviões aguardando no hangar
void listarNumeroDeAvioes(Hangar* hangar) {
    printf("Número de aviões aguardando no hangar: %d\n", hangar->tamanho);
}

// Função para listar todos os aviões no hangar
void listarAvioes(Hangar* hangar) {
    if (hangarVazio(hangar)) {
        printf("O hangar está vazio.\n");
        return;
    }

    printf("Aviões no hangar:\n");
    No* atual = hangar->topo;
    while (atual != NULL) {
        printf("ID: %d, Nome: %s\n", atual->aviao.id, atual->aviao.nome);
        atual = atual->prox;
    }
}

// Função para listar as características do primeiro avião no hangar
void listarPrimeiroAviao(Hangar* hangar) {
    if (hangarVazio(hangar)) {
        printf("O hangar está vazio.\n");
        return;
    }

    No* primeiroAviao = hangar->topo;
    printf("ID do primeiro avião: %d\n", primeiroAviao->aviao.id);
    printf("Nome do primeiro avião: %s\n", primeiroAviao->aviao.nome);
}

// Função para remover um avião do hangar pela posição
void removerAviaoPorPosicao(Hangar* hangar, int posicao) {
    if (hangarVazio(hangar)) {
        printf("O hangar está vazio.\n");
        return;
    }

    if (posicao < 1 || posicao > hangar->tamanho) {
        printf("Posição inválida.\n");
        return;
    }

    No* anterior = NULL;
    No* atual = hangar->topo;
    int contador = 1;

    // Percorrer até a posição desejada
    while (contador < posicao) {
        anterior = atual;
        atual = atual->prox;
        contador++;
    }

    // Remover o avião na posição desejada
    if (anterior == NULL) {
        // Se a posição for a primeira
        hangar->topo = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    hangar->tamanho--;
}

// Função para liberar a memória alocada pela pilha
void liberarMemoria(Hangar* hangar) {
    No* atual = hangar->topo;
    while (atual != NULL) {
        No* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    hangar->topo = NULL;
    hangar->tamanho = 0;
}

int main() {
    Hangar hangar;
    inicializarHangar(&hangar);

    // Exemplo de uso
    Aviao aviao1 = {1, "Aviao 1"};
    empilharAviao(&hangar, aviao1);

    Aviao aviao2 = {2, "Aviao 2"};
    empilharAviao(&hangar, aviao2);

    Aviao aviao3 = {3, "Aviao 3"};
    empilharAviao(&hangar, aviao3);

    listarAvioes(&hangar); // Deve exibir os três aviões no hangar

    desempilharAviao(&hangar);
    listarAvioes(&hangar); // Deve exibir os dois aviões restantes no hangar

    removerAviaoPorPosicao(&hangar, 1);
    listarAvioes(&hangar); // Deve exibir apenas um avião no hangar

    liberarMemoria(&hangar); // Liberar a memória alocada pela pilha

    return 0;
}
