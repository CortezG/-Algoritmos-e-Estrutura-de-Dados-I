#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct Node Node;

// Função para criar e inicializar a árvore
Node* criarArvore();

// Função para inserir um elemento na árvore
Node* inserir(Node* raiz, int chave);

// Função para imprimir a árvore em ordem crescente
void imprimirArvore(Node* raiz);

// Função para contar quantos elementos tem na árvore
int contarElementos(Node* raiz);

// Função para buscar um elemento na árvore
Node* buscar(Node* raiz, int chave);

// Função para percorrer e mostrar as chaves em pré-ordem
void percorrerPreOrdem(Node* raiz);

// Função para percorrer e mostrar as chaves em ordem
void percorrerEmOrdem(Node* raiz);

// Função para percorrer e mostrar as chaves em pós-ordem
void percorrerPosOrdem(Node* raiz);

// Função para liberar a memória ocupada pela árvore
void liberarArvore(Node* raiz);

#endif /* ARVORE_BINARIA_H */
