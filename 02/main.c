#include <stdio.h>
#include "aluno.h"
#include "turma.h"

int main() {
    Turma turma = criarTurma(10);

    Aluno aluno1 = { 1, "João", 20, 8.5 };
    Aluno aluno2 = { 2, "Maria", 19, 7.8 };
    Aluno aluno3 = { 3, "Pedro", 21, 9.2 };

    inserirAluno(&turma, aluno1);
    inserirAluno(&turma, aluno2);
    inserirAluno(&turma, aluno3);

    buscarAlunoSequencial(turma, 2);
    buscarAlunoBinariaRecursiva(turma, 3, 0, turma.quantidade - 1);

    imprimirAlunos(turma);

    liberarTurma(&turma);

    return 0;
}
