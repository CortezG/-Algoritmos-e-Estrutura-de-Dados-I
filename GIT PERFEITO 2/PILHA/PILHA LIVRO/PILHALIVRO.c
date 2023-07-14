#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do livro
typedef struct {
    char titulo[100];
    char autor[100];
    int ano;
} Livro;

// Definição da estrutura da pilha
typedef struct no {
    Livro livro;
    struct no* prox;
} No;

typedef struct {
    No* topo;
} Pilha;

// Função para criar uma nova pilha vazia
Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha* pilha) {
    return (pilha->topo == NULL);
}

// Função para empilhar um livro
void empilharLivro(Pilha* pilha, Livro livro) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->livro = livro;
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;
}

// Função para desempilhar um livro
void desempilharLivro(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("A pilha de livros esta vazia.\n");
        return;
    }
    No* temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(temp);
}

// Função para exibir o livro no topo da pilha
void exibirTopo(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("A pilha de livros esta vazia.\n");
        return;
    }
    Livro topo = pilha->topo->livro;
    printf("Titulo: %s\n", topo.titulo);
    printf("Autor: %s\n", topo.autor);
    printf("Ano: %d\n", topo.ano);
}

// Função para imprimir todos os livros da pilha
void imprimirPilha(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("A pilha de livros esta vazia.\n");
        return;
    }

    No* atual = pilha->topo;
    printf("Pilha de livros:\n");
    while (atual != NULL) {
        Livro livro = atual->livro;
        printf("Titulo: %s\n", livro.titulo);
        printf("Autor: %s\n", livro.autor);
        printf("Ano: %d\n\n", livro.ano);
        atual = atual->prox;
    }
}

// Função para liberar a memória alocada pela pilha
void liberarPilha(Pilha* pilha) {
    while (!pilhaVazia(pilha)) {
        desempilharLivro(pilha);
    }
    free(pilha);
}

int main() {
    // Criando uma nova pilha
    Pilha* pilhaLivros = criarPilha();
    
    // Criando alguns livros
    Livro livro1 = {"Livro 1", "Autor 1", 2000};
    Livro livro2 = {"Livro 2", "Autor 2", 2010};
    Livro livro3 = {"Livro 3", "Autor 3", 2020};
    
    // Empilhando os livros
    empilharLivro(pilhaLivros, livro1);
    empilharLivro(pilhaLivros, livro2);
    empilharLivro(pilhaLivros, livro3);
    
    // Exibindo o livro no topo da pilha
    printf("Livro no topo da pilha:\n");
    exibirTopo(pilhaLivros);
    
    // Imprimindo a pilha de livros
    imprimirPilha(pilhaLivros);
    
    // Desempilhando um livro
    printf("\nDesempilhando o livro no topo...\n");
    desempilharLivro(pilhaLivros);
    
    // Exibindo o novo livro no topo da pilha
    printf("Novo livro no topo da pilha:\n");
    exibirTopo(pilhaLivros);
    
    // Imprimindo a pilha de livros novamente
    imprimirPilha(pilhaLivros);
    
    // Liberando a memória alocada pela pilha
    liberarPilha(pilhaLivros);
    
    return 0;
}
