#ifndef DEQUE_H
#define DEQUE_H

typedef struct {
    char nome[50];
    int idade;
    int codigo;
    // Outros campos relacionados ao aluno
} Aluno;

typedef struct Auxiliar {
    Aluno aluno;
    struct Auxiliar* proximo;
    struct Auxiliar* anterior;
} Auxiliar;

typedef struct {
    Auxiliar* cabeca;
    Auxiliar* cauda;
} Deque;

void inicializarDeque(Deque* deque);
int dequeVazio(Deque* deque);
void inserirFrente(Deque* deque, Aluno aluno);
void inserirTras(Deque* deque, Aluno aluno);
void exibirDequeDireta(Deque* deque);
void exibirDequeInversa(Deque* deque);
void liberarDeque(Deque* deque);

#endif  // DEQUE_H
