#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

int gerarNumeroAleatorio() {
    return rand() % 100; // Gera um n�mero aleat�rio entre 0 e 99
}

int main() {
    srand(time(NULL)); // Inicializa a semente do gerador de n�meros aleat�rios

    Lista lista = criarLista(10);

    for (int i = 0; i < 10; i++) {
        int numero = gerarNumeroAleatorio();
        inserirElemento(&lista, numero);
    }

    imprimirListaIterativa(lista);

    int elemento = 42;

    int indiceSequencial = buscarElementoSequencial(lista, elemento);
    if (indiceSequencial != -1) {
        printf("Elemento %d encontrado na posi��o %d (busca sequencial).\n", elemento, indiceSequencial);
    }
    else {
        printf("Elemento %d n�o encontrado (busca sequencial).\n", elemento);
    }

    int indiceOrdenadoSequencial = buscarElementoOrdenadoSequencial(lista, elemento);
    if (indiceOrdenadoSequencial != -1) {
        printf("Elemento %d encontrado na posi��o %d (busca sequencial com lista ordenada).\n", elemento, indiceOrdenadoSequencial);
    }
    else {
        printf("Elemento %d n�o encontrado (busca sequencial com lista ordenada).\n", elemento);
    }

    int indiceBinarioIterativo = buscarElementoBinarioIterativo(lista, elemento);
    if (indiceBinarioIterativo != -1) {
        printf("Elemento %d encontrado na posi��o %d (busca bin�ria iterativa).\n", elemento, indiceBinarioIterativo);
    }
    else {
        printf("Elemento %d n�o encontrado (busca bin�ria iterativa).\n", elemento);
    }

    int indiceBinarioRecursivo = buscarElementoBinarioRecursivo(lista, elemento, 0, lista.quantidade - 1);
    if (indiceBinarioRecursivo != -1) {
        printf("Elemento %d encontrado na posi��o %d (busca bin�ria recursiva).\n", elemento, indiceBinarioRecursivo);
    }
    else {
        printf("Elemento %d n�o encontrado (busca bin�ria recursiva).\n", elemento);
    }

    printf("Elementos da lista (recursivo): ");
    imprimirListaRecursiva(lista, 0);

    int maiorIterativo = buscarMaiorElementoIterativo(lista);
    printf("Maior elemento (iterativo): %d\n", maiorIterativo);

    int maiorRecursivo = buscarMaiorElementoRecursivo(lista, 0);
    printf("Maior elemento (recursivo): %d\n", maiorRecursivo);

    int menorIterativo = buscarMenorElementoIterativo(lista);
    printf("Menor elemento (iterativo): %d\n", menorIterativo);

    int menorRecursivo = buscarMenorElementoRecursivo(lista, 0);
    printf("Menor elemento (recursivo): %d\n", menorRecursivo);

    int somaIterativa = somarElementosIterativo(lista);
    printf("Soma dos elementos (iterativo): %d\n", somaIterativa);

    int somaRecursiva = somarElementosRecursivo(lista, 0);
    printf("Soma dos elementos (recursivo): %d\n", somaRecursiva);

    int produtoIterativo = multiplicarElementosIterativo(lista);
    printf("Produto dos elementos (iterativo): %d\n", produtoIterativo);

    int produtoRecursivo = multiplicarElementosRecursivo(lista, 0);
    printf("Produto dos elementos (recursivo): %d\n", produtoRecursivo);

    liberarLista(&lista);

    return 0;
}
