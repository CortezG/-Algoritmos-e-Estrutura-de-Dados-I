#include "deque.h"
#include <stdio.h>

int main() {
    Deque deque;
    inicializarDeque(&deque);

    // Exemplo de inserção de alunos no deque
    Aluno aluno1 = {"João", 20, 1001};
    Aluno aluno2 = {"Maria", 19, 1002};
    Aluno aluno3 = {"Pedro", 21, 1003};

    inserirFrente(&deque, aluno1);
    inserirFrente(&deque, aluno2);
    inserirTras(&deque, aluno3);

    // Exibir alunos em ordem direta
    exibirDequeDireta(&deque);

    // Exibir alunos em ordem inversa
    exibirDequeInversa(&deque);

    // Liberar memória do deque
    liberarDeque(&deque);

    return 0;
}
