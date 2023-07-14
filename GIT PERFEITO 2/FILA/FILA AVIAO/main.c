#include <stdio.h>
#include "fila.h"

int main() {
    FilaDecolagem* fila = criarFila();

    adicionarAviao(fila, 1, "Aviao 1");
    adicionarAviao(fila, 2, "Aviao 2");
    adicionarAviao(fila, 3, "Aviao 3");

    listarNumeroAvioes(fila);
    listarAvioes(fila);
    listarPrimeiroAviao(fila);

    autorizarDecolagem(fila);

    listarNumeroAvioes(fila);
    listarAvioes(fila);
    listarPrimeiroAviao(fila);

    return 0;
}
