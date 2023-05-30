#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista criarLista(int quantidade) {
    Lista lista;
    lista.elementos = (int*)malloc(quantidade * sizeof(int));
    lista.quantidade = 0;
    return lista;
}

void liberarLista(Lista* lista) {
    free(lista->elementos);
    lista->quantidade = 0;
}

void inserirElemento(Lista* lista, int elemento) {
    lista->elementos[lista->quantidade++] = elemento;
}

void inserirElementoOrdenado(Lista* lista, int elemento) {
    int i = lista->quantidade - 1;

    while (i >= 0 && lista->elementos[i] > elemento) {
        lista->elementos[i + 1] = lista->elementos[i];
        i--;
    }

    lista->elementos[i + 1] = elemento;
    lista->quantidade++;
}

void imprimirListaIterativa(Lista lista) {
    printf("Elementos da lista (iterativo):\n");
    for (int i = 0; i < lista.quantidade; i++) {
        printf("%d ", lista.elementos[i]);
    }
    printf("\n");
}

int buscarElementoSequencial(Lista lista, int elemento) {
    for (int i = 0; i < lista.quantidade; i++) {
        if (lista.elementos[i] == elemento) {
            return i;
        }
    }

    return -1;
}

int buscarElementoOrdenadoSequencial(Lista lista, int elemento) {
    for (int i = 0; i < lista.quantidade && lista.elementos[i] <= elemento; i++) {
        if (lista.elementos[i] == elemento) {
            return i;
        }
    }

    return -1;
}

int buscarElementoBinarioIterativo(Lista lista, int elemento) {
    int inicio = 0;
    int fim = lista.quantidade - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (lista.elementos[meio] == elemento) {
            return meio;
        }
        else if (lista.elementos[meio] < elemento) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    return -1;
}

int buscarElementoBinarioRecursivo(Lista lista, int elemento, int inicio, int fim) {
    if (inicio > fim) {
        return -1;
    }

    int meio = (inicio + fim) / 2;

    if (lista.elementos[meio] == elemento) {
        return meio;
    }
    else if (lista.elementos[meio] < elemento) {
        return buscarElementoBinarioRecursivo(lista, elemento, meio + 1, fim);
    }
    else {
        return buscarElementoBinarioRecursivo(lista, elemento, inicio, meio - 1);
    }
}

void imprimirListaRecursiva(Lista lista, int indice) {
    if (indice >= lista.quantidade) {
        printf("\n");
        return;
    }

    printf("%d ", lista.elementos[indice]);
    imprimirListaRecursiva(lista, indice + 1);
}

int buscarMaiorElementoIterativo(Lista lista) {
    int maior = lista.elementos[0];

    for (int i = 1; i < lista.quantidade; i++) {
        if (lista.elementos[i] > maior) {
            maior = lista.elementos[i];
        }
    }

    return maior;
}

int buscarMaiorElementoRecursivo(Lista lista, int indice) {
    if (indice == lista.quantidade - 1) {
        return lista.elementos[indice];
    }

    int maiorRestante = buscarMaiorElementoRecursivo(lista, indice + 1);

    return lista.elementos[indice] > maiorRestante ? lista.elementos[indice] : maiorRestante;
}

int buscarMenorElementoIterativo(Lista lista) {
    int menor = lista.elementos[0];

    for (int i = 1; i < lista.quantidade; i++) {
        if (lista.elementos[i] < menor) {
            menor = lista.elementos[i];
        }
    }

    return menor;
}

int buscarMenorElementoRecursivo(Lista lista, int indice) {
    if (indice == lista.quantidade - 1) {
        return lista.elementos[indice];
    }

    int menorRestante = buscarMenorElementoRecursivo(lista, indice + 1);

    return lista.elementos[indice] < menorRestante ? lista.elementos[indice] : menorRestante;
}

int somarElementosIterativo(Lista lista) {
    int soma = 0;

    for (int i = 0; i < lista.quantidade; i++) {
        soma += lista.elementos[i];
    }

    return soma;
}

int somarElementosRecursivo(Lista lista, int indice) {
    if (indice == lista.quantidade) {
        return 0;
    }

    return lista.elementos[indice] + somarElementosRecursivo(lista, indice + 1);
}

int multiplicarElementosIterativo(Lista lista) {
    int produto = 1;

    for (int i = 0; i < lista.quantidade; i++) {
        produto *= lista.elementos[i];
    }

    return produto;
}

int multiplicarElementosRecursivo(Lista lista, int indice) {
    if (indice == lista.quantidade) {
        return 1;
    }

    return lista.elementos[indice] * multiplicarElementosRecursivo(lista, indice + 1);
}
