#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct {
    No* raiz;
} Arvore;

void inicializarArvore(Arvore* arvore);
void adicionarArvore(Arvore* arvore, int valor);
void imprimirArvore(Arvore* arvore);
No* buscar(Arvore* arvore, int valor);
int contarNos(No* raiz);
void preOrdem(No* raiz);
void inOrdem(No* raiz);
void posOrdem(No* raiz);

#endif
