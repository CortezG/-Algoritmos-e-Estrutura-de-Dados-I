#include <stdio.h>
#include <stdlib.h>
#include "turma.h"

Turma criarTurma(int quantidade) {
    Turma turma;
    turma.alunos = (Aluno*)malloc(quantidade * sizeof(Aluno));
    turma.quantidade = 0;
    return turma;
}

void inserirAluno(Turma* turma, Aluno aluno) {
    if (turma->quantidade >= sizeof(turma->alunos) / sizeof(turma->alunos[0])) {
        printf("A turma está cheia. Não é possível adicionar mais alunos.\n");
        return;
    }

    turma->alunos[turma->quantidade++] = aluno;
}

void liberarTurma(Turma* turma) {
    free(turma->alunos);
    turma->quantidade = 0;
}

void buscarAlunoSequencial(Turma turma, int codigo) {
    for (int i = 0; i < turma.quantidade; i++) {
        if (turma.alunos[i].codigo == codigo) {
            printf("Aluno encontrado:\n");
            printf("Código: %d\n", turma.alunos[i].codigo);
            printf("Nome: %s\n", turma.alunos[i].nome);
            printf("Idade: %d\n", turma.alunos[i].idade);
            printf("Coeficiente: %.2f\n", turma.alunos[i].coeficiente);
            return;
        }
    }

    printf("Aluno com o código %d não encontrado.\n", codigo);
}

void buscarAlunoBinariaRecursiva(Turma turma, int codigo, int inicio, int fim) {
    if (inicio > fim) {
        printf("Aluno com o código %d não encontrado.\n", codigo);
        return;
    }

    int meio = (inicio + fim) / 2;

    if (turma.alunos[meio].codigo == codigo) {
        printf("Aluno encontrado:\n");
        printf("Código: %d\n", turma.alunos[meio].codigo);
        printf("Nome: %s\n", turma.alunos[meio].nome);
        printf("Idade: %d\n", turma.alunos[meio].idade);
        printf("Coeficiente: %.2f\n", turma.alunos[meio].coeficiente);
        return;
    }
    else if (turma.alunos[meio].codigo < codigo) {
        buscarAlunoBinariaRecursiva(turma, codigo, meio + 1, fim);
    }
    else {
        buscarAlunoBinariaRecursiva(turma, codigo, inicio, meio - 1);
    }
}

void imprimirAlunos(Turma turma) {
    printf("Alunos na turma:\n");
    for (int i = 0; i < turma.quantidade; i++) {
        printf("Código: %d, Nome: %s\n", turma.alunos[i].codigo, turma.alunos[i].nome);
    }
}
