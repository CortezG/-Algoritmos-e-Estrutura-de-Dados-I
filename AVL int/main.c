#include "arvore.h"
#include <stdio.h>

int main() {
    ARVORE a;
    inicializarArvore(&a);
    adicionaAVL(&a, 5);
    adicionaAVL(&a, 10);
    adicionaAVL(&a, 20);
    adicionaAVL(&a, 30);
    adicionaAVL(&a, 40);
    adicionaAVL(&a, 50);
    adicionaAVL(&a, 60);
    printf("\naltura = %d\n", altura(a.raiz));
    int cont = 0;
    printf("\nprofundidade = %d\n", profundidade(a.raiz, 50, cont));
    printf("\nPercurso em largura:\n");
    percorrerLargura(&a);
    printf("\nTentando adicionar repetido:\n");
    adicionaAVL(&a, 60);
    percorrerLargura(&a);
    printf("\nExcluindo 30 = \n");
    remover(&a, 30);
    percorrerLargura(&a);
    destruirArvore(a.raiz);
    return 0;
}
