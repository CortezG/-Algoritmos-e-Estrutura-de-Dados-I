#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do paciente
typedef struct {
    int codigo;
    char nome[50];
    char cpf[12];
    int idade;
} Paciente;

// Definição da estrutura do nó da lista ligada
typedef struct No {
    Paciente paciente;
    struct No* prox;
} No;

// Definição da estrutura da tabela hash
typedef struct {
    No* tabela[100];
} TabelaHash;

// Função para criar um novo nó da lista ligada
No* criarNo(Paciente paciente) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->paciente = paciente;
        novoNo->prox = NULL;
    }
    return novoNo;
}

// Função para calcular o índice da tabela hash para um código de paciente
int calcularIndice(int codigo) {
    return codigo % 100;
}

// Função para inserir um paciente na tabela hash
void inserirPaciente(TabelaHash* tabela, Paciente paciente) {
    int indice = calcularIndice(paciente.codigo);
    No* novoNo = criarNo(paciente);

    if (novoNo != NULL) {
        if (tabela->tabela[indice] == NULL) {
            tabela->tabela[indice] = novoNo;
        } else {
            No* atual = tabela->tabela[indice];
            while (atual->prox != NULL) {
                atual = atual->prox;
            }
            atual->prox = novoNo;
        }
    }
}

// Função para buscar um paciente na tabela hash pelo código
Paciente* buscarPaciente(TabelaHash tabela, int codigo) {
    int indice = calcularIndice(codigo);
    No* atual = tabela.tabela[indice];

    while (atual != NULL) {
        if (atual->paciente.codigo == codigo) {
            return &atual->paciente;
        }
        atual = atual->prox;
    }

    return NULL;  // Paciente não encontrado
}

// Função para remover um paciente da tabela hash pelo código
void removerPaciente(TabelaHash* tabela, int codigo) {
    int indice = calcularIndice(codigo);
    No* atual = tabela->tabela[indice];
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->paciente.codigo == codigo) {
            if (anterior == NULL) {
                tabela->tabela[indice] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

// Função principal para demonstração
int main() {
    TabelaHash tabela;
    memset(tabela.tabela, 0, sizeof(tabela.tabela));  // Inicializa a tabela hash com NULL

    // Exemplo de uso
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
