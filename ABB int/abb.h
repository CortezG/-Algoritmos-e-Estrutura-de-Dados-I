#ifndef ARVORE_H
#define ARVORE_H

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct {
    No* raiz;
} ARVORE;

void inicializarArvore(ARVORE* a);
void destruirArvore(No* a);
int quantidadeNos(No* raiz);
No* inserirNo(No* raiz, No* no);
void adiciona(ARVORE* a, No* no);
void adicionarArvore(ARVORE* a, int valor);
No* buscarNo(No* raiz, int valor);
No* buscar(ARVORE* a, int valor);
void excluirNo(ARVORE* a, int valor);
void percorrerLargura(ARVORE* a);
int maior(int a, int b);
int altura(No* raiz);
int profundidade(No* raiz, int valor, int cont);
void listarNos(No* raiz);
void imprimirArvore(ARVORE *a);
No* pre_ordem(No* raiz);
No* in_ordem(No* raiz);
No* pos_ordem(No* raiz);

#endif // ARVORE_H
