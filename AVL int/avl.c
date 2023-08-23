#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarArvore(ARVORE* a) {
    a->raiz = NULL;
}

void destruirArvore(No* a) {
    if (a != NULL) {
        destruirArvore(a->direita);
        destruirArvore(a->esquerda);
        free(a);
    }
}

// Other function implementations...

No* pre_ordem(No* raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    printf("%d\n", raiz->valor);
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
}

No* in_ordem(No* raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    in_ordem(raiz->esquerda);
    printf("%d\n", raiz->valor);
    in_ordem(raiz->direita);
}

No* pos_ordem(No* raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    pos_ordem(raiz->esquerda);
    pos_ordem(raiz->direita);
    printf("%d\n", raiz->valor);
}
