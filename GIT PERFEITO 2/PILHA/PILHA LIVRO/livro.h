#ifndef PILHA_H
#define PILHA_H

typedef struct {
    char titulo[100];
    char autor[100];
    int ano;
} Livro;

typedef struct no {
    Livro livro;
    struct no* prox;
} No;

typedef struct {
    No* topo;
} Pilha;

Pilha* criarPilha();
int pilhaVazia(Pilha* pilha);
void empilharLivro(Pilha* pilha, Livro livro);
void desempilharLivro(Pilha* pilha);
void exibirTopo(Pilha* pilha);
void imprimirPilha(Pilha* pilha);
void liberarPilha(Pilha* pilha);

#endif  // PILHA_H
