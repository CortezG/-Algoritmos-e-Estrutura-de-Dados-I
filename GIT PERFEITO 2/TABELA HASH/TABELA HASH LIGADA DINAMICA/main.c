#include <stdio.h>
#include "tabela_hash.h"

int main() {
    TabelaHash tabela;
    for (int i = 0; i < 100; i++) {
        tabela.tabela[i] = NULL;
    }

    Paciente paciente1 = {1, "João", "12345678901", 30};
    Paciente paciente2 = {2, "Maria", "98765432109", 25};

    inserirPaciente(&tabela, paciente1);
    inserirPaciente(&tabela, paciente2);

    Paciente* busca = buscarPaciente(tabela, 2);
    if (busca != NULL) {
        printf("Paciente encontrado:\n");
        printf("Código: %d\n", busca->codigo);
        printf("Nome: %s\n", busca->nome);
        printf("CPF: %s\n", busca->cpf);
        printf("Idade: %d\n", busca->idade);
    } else {
        printf("Paciente não encontrado.\n");
    }

    removerPaciente(&tabela, 1);

    busca = buscarPaciente(tabela, 1);
    if (busca != NULL) {
        printf("Paciente encontrado:\n");
        printf("Código: %d\n", busca->codigo);
        printf("Nome: %s\n", busca->nome);
        printf("CPF: %s\n", busca->cpf);
        printf("Idade: %d\n", busca->idade);
    } else {
        printf("Paciente não encontrado.\n");
    }

    return 0;
}
