#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct {
    int codigo;
    char nome[50];
    char cpf[15];
    int idade;
} Paciente;

typedef struct {
    Paciente* pacientes[TABLE_SIZE];
} TabelaHash;

TabelaHash* inicializarTabelaHash();
void inserirPaciente(TabelaHash* tabela, Paciente* paciente);
Paciente* buscarPaciente(TabelaHash* tabela, int codigo);
void removerPaciente(TabelaHash* tabela, int codigo);

#endif  // PACIENTE_H
