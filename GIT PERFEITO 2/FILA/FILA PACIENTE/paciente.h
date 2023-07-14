#ifndef FILA_H
#define FILA_H

typedef struct paciente {
    char nome[50];
    int idade;
    int codigo;
    char cpf[15];
} Paciente;

typedef struct no {
    Paciente info;
    struct no* proximo;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void inicializarFila(Fila* fila);
int filaVazia(Fila* fila);
No* criarNo(Paciente paciente);
void inserirPaciente(Fila* fila, Paciente paciente);
void removerPaciente(Fila* fila);
void exibirFila(Fila* fila);

#endif  // FILA_H
