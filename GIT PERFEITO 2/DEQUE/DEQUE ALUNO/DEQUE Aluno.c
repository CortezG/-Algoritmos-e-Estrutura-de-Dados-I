#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    int codigo;
    // Outros campos relacionados ao aluno
} Aluno;

typedef struct Auxiliar {
    Aluno aluno;
    struct Auxiliar* proximo;
    struct Auxiliar* anterior;
} Auxiliar;

typedef struct {
    Auxiliar* cabeca;
    Auxiliar* cauda;
} Deque;

void inicializarDeque(Deque* deque) {
    deque->cabeca = (Auxiliar*)malloc(sizeof(Auxiliar));
    deque->cauda = (Auxiliar*)malloc(sizeof(Auxiliar));

    deque->cabeca->proximo = deque->cauda;
    deque->cabeca->anterior = NULL;

    deque->cauda->proximo = NULL;
    deque->cauda->anterior = deque->cabeca;
}

int dequeVazio(Deque* deque) {
    return (deque->cabeca->proximo == deque->cauda);
}

void inserirFrente(Deque* deque, Aluno aluno) {
    Auxiliar* novoAuxiliar = (Auxiliar*)malloc(sizeof(Auxiliar));
    novoAuxiliar->aluno = aluno;

    novoAuxiliar->proximo = deque->cabeca->proximo;
    novoAuxiliar->anterior = deque->cabeca;

    deque->cabeca->proximo->anterior = novoAuxiliar;
    deque->cabeca->proximo = novoAuxiliar;
}

void inserirTras(Deque* deque, Aluno aluno) {
    Auxiliar* novoAuxiliar = (Auxiliar*)malloc(sizeof(Auxiliar));
    novoAuxiliar->aluno = aluno;

    novoAuxiliar->proximo = deque->cauda;
    novoAuxiliar->anterior = deque->cauda->anterior;

    deque->cauda->anterior->proximo = novoAuxiliar;
    deque->cauda->anterior = novoAuxiliar;
}

void exibirDequeDireta(Deque* deque) {
    if (dequeVazio(deque)) {
        printf("O deque está vazio.\n");
    } else {
        Auxiliar* auxiliarAtual = deque->cabeca->proximo;
        printf("Alunos em ordem direta:\n");
        while (auxiliarAtual != deque->cauda) {
            printf("Nome: %s\n", auxiliarAtual->aluno.nome);
            printf("Idade: %d\n", auxiliarAtual->aluno.idade);
            printf("Código: %d\n", auxiliarAtual->aluno.codigo);
            printf("\n");
            auxiliarAtual = auxiliarAtual->proximo;
        }
    }
}

void exibirDequeInversa(Deque* deque) {
    if (dequeVazio(deque)) {
        printf("O deque está vazio.\n");
    } else {
        Auxiliar* auxiliarAtual = deque->cauda->anterior;
        printf("Alunos em ordem inversa:\n");
        while (auxiliarAtual != deque->cabeca) {
            printf("Nome: %s\n", auxiliarAtual->aluno.nome);
            printf("Idade: %d\n", auxiliarAtual->aluno.idade);
            printf("Código: %d\n", auxiliarAtual->aluno.codigo);
            printf("\n");
            auxiliarAtual = auxiliarAtual->anterior;
        }
    }
}

void liberarDeque(Deque* deque) {
    while (!dequeVazio(deque)) {
        Auxiliar* auxiliarRemovido = deque->cabeca->proximo;
        deque->cabeca->proximo = auxiliarRemovido->proximo;
        auxiliarRemovido->proximo->anterior = deque->cabeca;
        free(auxiliarRemovido);
    }

    free(deque->cabeca);
    free(deque->cauda);
}

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
