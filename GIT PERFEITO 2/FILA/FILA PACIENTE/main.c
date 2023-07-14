#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main() {
    Fila fila;
    inicializarFila(&fila);

    Paciente paciente1;
    strcpy(paciente1.nome, "João");
    paciente1.idade = 25;
    paciente1.codigo = 1;
    strcpy(paciente1.cpf, "123.456.789-00");

    Paciente paciente2;
    strcpy(paciente2.nome, "Maria");
    paciente2.idade = 32;
    paciente2.codigo = 2;
    strcpy(paciente2.cpf, "987.654.321-00");

    Paciente paciente3;
    strcpy(paciente3.nome, "Pedro");
    paciente3.idade = 18;
    paciente3.codigo = 3;
    strcpy(paciente3.cpf, "456.789.123-00");

    inserirPaciente(&fila, paciente1);
    inserirPaciente(&fila, paciente2);
    inserirPaciente(&fila, paciente3);

    exibirFila(&fila);

    removerPaciente(&fila);
    removerPaciente(&fila);

    exibirFila(&fila);

    return 0;
}
