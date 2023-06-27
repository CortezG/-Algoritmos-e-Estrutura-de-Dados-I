#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#define MAX_AVIOES 10
#define MAX_NOME 50

typedef struct {
    int identificador;
    char nome[MAX_NOME];
} Aviao;

typedef struct {
    Aviao avioes[MAX_AVIOES];
    int topo;
} Hangar;

void inicializarHangar(Hangar *hangar);
int HangarVazio(Hangar *hangar);
int HangarCheio(Hangar *hangar);
void listarAvioesAguardando(Hangar *hangar);
void tirarAviao(Hangar *hangar);
void adicionarAviao(Hangar *hangar, Aviao aviao);
void listarAvioes(Hangar *hangar);
void listarPrimeiroAviao(Hangar *hangar);
void tirarAviaoPosicao(Hangar *hangar, int posicao);


#endif // PILHA_H_INCLUDED
