#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int* elementos;
    int quantidade;
} Lista;

Lista criarLista(int quantidade);
void liberarLista(Lista* lista);
void inserirElemento(Lista* lista, int elemento);
void inserirElementoOrdenado(Lista* lista, int elemento);
void imprimirListaIterativa(Lista lista);
int buscarElementoSequencial(Lista lista, int elemento);
int buscarElementoOrdenadoSequencial(Lista lista, int elemento);
int buscarElementoBinarioIterativo(Lista lista, int elemento);
int buscarElementoBinarioRecursivo(Lista lista, int elemento, int inicio, int fim);
void imprimirListaRecursiva(Lista lista, int indice);
int buscarMaiorElementoIterativo(Lista lista);
int buscarMaiorElementoRecursivo(Lista lista, int indice);
int buscarMenorElementoIterativo(Lista lista);
int buscarMenorElementoRecursivo(Lista lista, int indice);
int somarElementosIterativo(Lista lista);
int somarElementosRecursivo(Lista lista, int indice);
int multiplicarElementosIterativo(Lista lista);
int multiplicarElementosRecursivo(Lista lista, int indice);

#endif
