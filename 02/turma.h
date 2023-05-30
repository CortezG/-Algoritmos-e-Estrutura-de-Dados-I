#ifndef TURMA_H
#define TURMA_H

#include "aluno.h"

typedef struct {
    Aluno* alunos;
    int quantidade;
} Turma;

Turma criarTurma(int quantidade);
void inserirAluno(Turma* turma, Aluno aluno);
void liberarTurma(Turma* turma);
void buscarAlunoSequencial(Turma turma, int codigo);
void buscarAlunoBinariaRecursiva(Turma turma, int codigo, int inicio, int fim);
void imprimirAlunos(Turma turma);

#endif
