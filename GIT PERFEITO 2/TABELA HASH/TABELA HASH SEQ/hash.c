#include "paciente.h"
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

int hash(int codigo) {
    return codigo % TABLE_SIZE;
}

TabelaHash* inicializarTabelaHash() {
    TabelaHash* tabela = (TabelaHash*) malloc(sizeof(TabelaHash));
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabela->pacientes[i] = NULL;
    }
    return tabela;
}

void inserirPaciente(TabelaHash* tabela, Paciente* paciente) {
    int indice = hash(paciente->codigo);
    tabela->pacientes[indice] = paciente;
}

Paciente* buscarPaciente(TabelaHash* tabela, int codigo) {
    int indice = hash(codigo);
    return tabela->pacientes[indice];
}

void removerPaciente(TabelaHash* tabela, int codigo) {
    int indice = hash(codigo);
    tabela->pacientes[indice] = NULL;
}
