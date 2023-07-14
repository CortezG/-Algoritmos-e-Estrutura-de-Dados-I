#ifndef TABELA_HASH_H
#define TABELA_HASH_H

typedef struct {
    int codigo;
    char nome[50];
    char cpf[12];
    int idade;
} Paciente;

typedef struct No {
    Paciente paciente;
    struct No* prox;
} No;

typedef struct {
    No* tabela[100];
} TabelaHash;

No* criarNo(Paciente paciente);
int calcularIndice(int codigo);
void inserirPaciente(TabelaHash* tabela, Paciente paciente);
Paciente* buscarPaciente(TabelaHash tabela, int codigo);
void removerPaciente(TabelaHash* tabela, int codigo);

#endif  // TABELA_HASH_H
