#ifndef ARVORE_H
#define ARVORE_H

typedef struct No {
    int valor;
    int h;
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct {
    No* raiz;
} ARVORE;

void inicializarArvore(ARVORE* a);
void destruirArvore(No* a);
int quantidadeNos(No* raiz);
int maximo(int v1, int v2);
int altura(No* raiz);
No* rot_direita(No* no_desb);
No* rot_esquerda(No* no_desb);
No* rot_esq_direita(No* no_desb);
No* rot_dir_esquerda(No* no_desb);
No* inserirAVL(No* raiz, No* no);
void adicionaAVL(ARVORE* a, int valor);
No* buscarNo(No* raiz, int valor);
No* buscar(ARVORE* a, int valor);
No* encontrarMinimo(No* raiz);
No* removerAVL(No* raiz, int valor);
void remover(ARVORE* a, int valor);
void percorrerLargura(ARVORE* a);
int maior(int a, int b);
int profundidade(No* raiz, int valor, int cont);
void listarNos(No* raiz);
void imprimirArvore(ARVORE *a);
No* pre_ordem(No* raiz);
No* in_ordem(No* raiz);
No* pos_ordem(No* raiz);

#endif // ARVORE_H
