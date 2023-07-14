#ifndef HANGAR_H
#define HANGAR_H

// Estrutura do avião
typedef struct Aviao {
    int id;
    char nome[50];
    // Outras características do avião
} Aviao;

// Estrutura do hangar
typedef struct Hangar Hangar;

// Funções
void inicializarHangar(Hangar* hangar);
int hangarVazio(Hangar* hangar);
void empilharAviao(Hangar* hangar, Aviao aviao);
void desempilharAviao(Hangar* hangar);
void listarNumeroDeAvioes(Hangar* hangar);
void listarAvioes(Hangar* hangar);
void listarPrimeiroAviao(Hangar* hangar);
void removerAviaoPorPosicao(Hangar* hangar, int posicao);
void liberarMemoria(Hangar* hangar);

#endif
