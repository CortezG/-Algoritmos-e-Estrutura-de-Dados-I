#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarDeque(Deque* deque) {
    deque->cabeca = (Auxiliar*)malloc(sizeof(Auxiliar));
    deque->cauda = (Auxiliar*)malloc(sizeof(Auxiliar));

    deque->cabeca->proximo = deque->cauda;
    deque->cabeca->anterior = NULL;

    deque->cauda->proximo = NULL;
    deque->cauda->anterior = deque->cabeca;
}

int dequeVazio(Deque* deque) {
    return (deque->cabeca->proximo == deque->cauda);
}

void inserirFrente(Deque* deque, int valor) {
    Auxiliar* novoAuxiliar = (Auxiliar*)malloc(sizeof(Auxiliar));
    novoAuxiliar->dado.valor = valor;

    novoAuxiliar->proximo = deque->cabeca->proximo;
    novoAuxiliar->anterior = deque->cabeca;

    deque->cabeca->proximo->anterior = novoAuxiliar;
    deque->cabeca->proximo = novoAuxiliar;
}

void inserirTras(Deque* deque, int valor) {
    Auxiliar* novoAuxiliar = (Auxiliar*)malloc(sizeof(Auxiliar));
    novoAuxiliar->dado.valor = valor;

    novoAuxiliar->proximo = deque->cauda;
    novoAuxiliar->anterior = deque->cauda->anterior;

    deque->cauda->anterior->proximo = novoAuxiliar;
    deque->cauda->anterior = novoAuxiliar;
}

void exibirDequeDireta(Deque* deque) {
    if (dequeVazio(deque)) {
        printf("O deque está vazio.\n");
    } else {
        Auxiliar* auxiliarAtual = deque->cabeca->proximo;
        printf("Deque em ordem direta:\n");
        while (auxiliarAtual != deque->cauda) {
            printf("%d ", auxiliarAtual->dado.valor);
            auxiliarAtual = auxiliarAtual->proximo;
        }
        printf("\n");
    }
}

void exibirDequeInversa(Deque* deque) {
    if (dequeVazio(deque)) {
        printf("O deque está vazio.\n");
    } else {
        Auxiliar* auxiliarAtual = deque->cauda->anterior;
        printf("Deque em ordem inversa:\n");
        while (auxiliarAtual != deque->cabeca) {
            printf("%d ", auxiliarAtual->dado.valor);
            auxiliarAtual = auxiliarAtual->anterior;
        }
        printf("\n");
    }
}

void liberarDeque(Deque* deque) {
    while (!dequeVazio(deque)) {
        Auxiliar* auxiliarRemovido = deque->cabeca->proximo;
        deque->cabeca->proximo = auxiliarRemovido->proximo;
        auxiliarRemovido->proximo->anterior = deque->cabeca;
        free(auxiliarRemovido);
    }

    free(deque->cabeca);
    free(deque->cauda);
}
