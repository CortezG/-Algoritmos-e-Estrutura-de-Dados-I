#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do paciente
typedef struct paciente {
    char nome[50];
    int idade;
    int codigo;
    char cpf[15];
} Paciente;

// Definição da estrutura do nó auxiliar
typedef struct no {
    Paciente info;
    struct no* proximo;
} No;

// Definição da estrutura da fila
typedef struct {
    No* inicio;
    No* fim;
} Fila;

// Função para inicializar a fila
void inicializarFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila* fila) {
    return (fila->inicio == NULL);
}

// Função para criar um novo nó
No* criarNo(Paciente paciente) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    novoNo->info = paciente;
    novoNo->proximo = NULL;
    return novoNo;
}

// Função para inserir um paciente na fila
void inserirPaciente(Fila* fila, Paciente paciente) {
    No* novoNo = criarNo(paciente);
    if (filaVazia(fila)) {
        fila->inicio = novoNo;
    } else {
        fila->fim->proximo = novoNo;
    }
    fila->fim = novoNo;
    printf("Paciente %s inserido na fila.\n", paciente.nome);
}

// Função para remover o próximo paciente da fila
void removerPaciente(Fila* fila) {
    if (filaVazia(fila)) {
        printf("A fila está vazia!\n");
        return;
    }

    No* noRemovido = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    printf("Paciente %s removido da fila.\n", noRemovido->info.nome);
    free(noRemovido);
}

// Função para exibir os pacientes na fila
void exibirFila(Fila* fila) {
    if (filaVazia(fila)) {
        printf("A fila está vazia!\n");
        return;
    }

    printf("Pacientes na fila:\n");
    No* noAtual = fila->inicio;
    while (noAtual != NULL) {
        printf("Nome: %s, Idade: %d, Código: %d, CPF: %s\n",
               noAtual->info.nome, noAtual->info.idade,
               noAtual->info.codigo, noAtual->info.cpf);
        noAtual = noAtual->proximo;
    }
}

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
