#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"

int main() {
    TabelaHash* tabela = inicializarTabelaHash();

    // Criando pacientes
    Paciente* paciente1 = (Paciente*) malloc(sizeof(Paciente));
    paciente1->codigo = 1;
    strcpy(paciente1->nome, "João");
    strcpy(paciente1->cpf, "123456789");
    paciente1->idade = 30;

    Paciente* paciente2 = (Paciente*) malloc(sizeof(Paciente));
    paciente2->codigo = 2;
    strcpy(paciente2->nome, "Maria");
    strcpy(paciente2->cpf, "987654321");
    paciente2->idade = 25;

    // Inserindo pacientes na tabela hash
    inserirPaciente(tabela, paciente1);
    inserirPaciente(tabela, paciente2);

    // Buscando paciente pelo código
    int codigo = 2;
    Paciente* paciente = buscarPaciente(tabela, codigo);
    if (paciente != NULL) {
        printf("Paciente encontrado:\n");
        printf("Código: %d\n", paciente->codigo);
        printf("Nome: %s\n", paciente->nome);
        printf("CPF: %s\n", paciente->cpf);
        printf("Idade: %d\n", paciente->idade);
    } else {
        printf("Paciente com código %d não encontrado.\n", codigo);
    }

    // Removendo paciente pelo código
    codigo = 1;
    removerPaciente(tabela, codigo);

    // Buscando paciente removido
    paciente = buscarPaciente(tabela, codigo);
    if (paciente != NULL) {
        printf("Paciente encontrado:\n");
        printf("Código: %d\n", paciente->codigo);
        printf("Nome: %s\n", paciente->nome);
        printf("CPF: %s\n", paciente->cpf);
        printf("Idade: %d\n", paciente->idade);
    } else {
        printf("Paciente com código %d não encontrado.\n", codigo);
    }

    // Liberando memória
    free(paciente1);
    free(paciente2);
    free(tabela);

    return 0;
}
