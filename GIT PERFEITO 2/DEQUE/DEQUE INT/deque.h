#ifndef DEQUE_H
#define DEQUE_H

typedef struct {
    int valor;
} DequeInt;

typedef struct Auxiliar {
    DequeInt dado;
    struct Auxiliar* proximo;
    struct Auxiliar* anterior;
} Auxiliar;

typedef struct {
    Auxiliar* cabeca;
    Auxiliar* cauda;
} Deque;

void inicializarDeque(Deque* deque);
int dequeVazio(Deque* deque);
void inserirFrente(Deque* deque, int valor);
void inserirTras(Deque* deque, int valor);
void exibirDequeDireta(Deque* deque);
void exibirDequeInversa(Deque* deque);
void liberarDeque(Deque* deque);

#endif  // DEQUE_H
