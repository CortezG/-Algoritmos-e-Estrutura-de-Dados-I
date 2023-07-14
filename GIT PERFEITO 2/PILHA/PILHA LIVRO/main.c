#include <stdio.h>
#include "pilha.h"

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
