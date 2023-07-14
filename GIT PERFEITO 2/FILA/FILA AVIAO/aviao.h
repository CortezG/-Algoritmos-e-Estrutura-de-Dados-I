#ifndef FILA_H
#define FILA_H

typedef struct Aviao {
    int identificador;
    char nome[50];
    // Outras características do avião
} Aviao;

typedef struct No {
    Aviao aviao;
    struct No* proximo;
} No;

typedef struct FilaDecolagem {
    No* primeiro;
    No* ultimo;
    int tamanho;
} FilaDecolagem;

FilaDecolagem* criarFila();
int estaVazia(FilaDecolagem* fila);
void listarNumeroAvioes(FilaDecolagem* fila);
void autorizarDecolagem(FilaDecolagem* fila);
void adicionarAviao(FilaDecolagem* fila, int identificador, char nome[]);
void listarAvioes(FilaDecolagem* fila);
void listarPrimeiroAviao(FilaDecolagem* fila);

#endif
