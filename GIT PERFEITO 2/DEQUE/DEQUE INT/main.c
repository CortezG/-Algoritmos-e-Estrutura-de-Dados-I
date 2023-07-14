#include "deque.h"
#include <stdio.h>

int main() {
    Deque deque;
    inicializarDeque(&deque);

    // Exemplo de inserção de valores no deque
    inserirFrente(&deque, 3);
    inserirFrente(&deque, 7);
    inserirTras(&deque, 1);
    inserirTras(&deque, 5);

    // Exibir deque em ordem direta
    exibirDequeDireta(&deque);

    // Exibir deque em ordem inversa
    exibirDequeInversa(&deque);

    // Liberar memória do deque
    liberarDeque(&deque);

    return 0;
}
