#include "arvore.h"
#include <stdio.h>

int main() {
    ARVORE minhaArvore;
    inicializarArvore(&minhaArvore);

    adicionarArvore(&minhaArvore, 9);
    adicionarArvore(&minhaArvore, 5);
    adicionarArvore(&minhaArvore, 3);
    adicionarArvore(&minhaArvore, 6);
    // ... more operations

    return 0;
}
