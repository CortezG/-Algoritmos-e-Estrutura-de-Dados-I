#include <stdio.h>
#include "hangar.h"

int main() {
    Hangar hangar;
    inicializarHangar(&hangar);

    // Exemplo de uso
    Aviao aviao1 = {1, "Aviao 1"};
    empilharAviao(&hangar, aviao1);

    Aviao aviao2 = {2, "Aviao 2"};
    empilharAviao(&hangar, aviao2);

    Aviao aviao3 = {3, "Aviao 3"};
    empilharAviao(&hangar, aviao3);

    listarAvioes(&hangar); // Deve exibir os três aviões no hangar

    desempilharAviao(&hangar);
    listarAvioes(&hangar); // Deve exibir os dois aviões restantes no hangar

    removerAviaoPorPosicao(&hangar, 1);
    listarAvioes(&hangar); // Deve exibir apenas um avião no hangar

    liberarMemoria(&hangar); // Liberar a memória alocada pela pilha

    return 0;
}
