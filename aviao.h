#ifndef FILA_DECOLAGEM_H
#define FILA_DECOLAGEM_H

typedef struct {
    int identificador;
    char nome[50];
    // Adicione outras características do avião aqui, se necessário
} Aviao;

typedef struct Elemento {
    Aviao aviao;
    struct Elemento* proximo;
} Elemento;

typedef struct {
    Elemento* inicio;
    Elemento* fim;
} Fila;

void inicializarFila(Fila* fila);
void adicionarAviao(Fila* fila, Aviao aviao);
void listarNumeroAvioes(Fila fila);
void autorizarDecolagem(Fila* fila);
void listarAvioesEspera(Fila fila);
void listarPrimeiroAviao(Fila fila);

#endif

