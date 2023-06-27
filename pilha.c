#include <stdio.h>
#include "pilha.h"

#include <stdio.h>
#include "pilha.h"

void inicializarHangar(Hangar *hangar) {
    hangar->topo = -1;
}

int HangarVazio(Hangar *hangar) {
    return (hangar->topo == -1);
}

int HangarCheio(Hangar *hangar) {
    return (hangar->topo == MAX_AVIOES - 1);
}

void listarAvioesAguardando(Hangar *hangar) {
    printf("Existem %d avioes \n", hangar->topo + 1);
}

void tirarAviao(Hangar *hangar) {
    if (!HangarVazio(hangar)) {
        Aviao aviao = hangar->avioes[hangar->topo];
        hangar->topo--;
        printf("Aviao %d (%s) removido \n", aviao.identificador, aviao.nome);
    } else {
        printf("Nao ha avioes no hangar\n");
    }
}

void adicionarAviao(Hangar *hangar, Aviao aviao) {
    if (!HangarCheio(hangar)) {
        hangar->topo++;
        hangar->avioes[hangar->topo] = aviao;
        printf("Aviao %d (%s) adicionado\n", aviao.identificador, aviao.nome);
    } else {
        printf("O hangar esta chei \n");
    }
}

void listarAvioes(Hangar *hangar) {
    printf("Avioes no hangar:\n");
    for (int i = hangar->topo; i >= 0; i--) {
        Aviao aviao = hangar->avioes[i];
        printf("Aviao %d (%s)\n", aviao.identificador, aviao.nome);
    }
}

void listarPrimeiroAviao(Hangar *hangar) {
    if (!HangarVazio(hangar)) {
        Aviao aviao = hangar->avioes[hangar->topo];
        printf("Primeiro aviao no hangar: %d (%s)\n", aviao.identificador, aviao.nome);
    } else {
        printf("Nao ha avioes \n");
    }
}

void tirarAviaoPosicao(Hangar *hangar, int posicao) {
    if (posicao >= 1 && posicao <= hangar->topo + 1) {
        Aviao avioes_removidos[MAX_AVIOES];
        int num_avioes_removidos = 0;
        int i;

        for (i = hangar->topo; i >= hangar->topo - posicao + 1; i--) {
            avioes_removidos[num_avioes_removidos] = hangar->avioes[i];
            num_avioes_removidos++;
        }

        hangar->topo -= posicao;

        printf("Aviao %d (%s) removido do hangar.\n", avioes_removidos[num_avioes_removidos - 1].identificador, avioes_removidos[num_avioes_removidos - 1].nome);

        for (i = num_avioes_removidos - 2; i >= 0; i--) {
            hangar->topo++;
            hangar->avioes[hangar->topo] = avioes_removidos[i];
        }

        printf("Avioes de %d a %d adicionados novamente \n", posicao + 1, num_avioes_removidos);
    } else {
        printf("Posicao invalida.\n");
    }
}
