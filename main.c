
#include <stdio.h>
#include "aviao.h"

int main() {
    Fila fila;
    inicializarFila(&fila);

    int opcao;
    Aviao novoAviao;

    do {
        printf("\nPista de Decolagem\n");
        printf("1. Listar numerode de avioes \n");
        printf("2. Autorizar decolagem do primeiro aviao\n");
        printf("3. Adicionar aviao \n");
        printf("4. Listar todos os avioes na fila \n");
        printf("5. Listar caracteristicas do primeiro aviao \n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarNumeroAvioes(fila);
                break;
            case 2:
                autorizarDecolagem(&fila);
                break;
            case 3:
                printf("Digite o id do aviao: ");
                scanf("%d", &novoAviao.identificador);
                printf("Digite o nome do aviao: ");
                scanf("%s", novoAviao.nome);
                adicionarAviao(&fila, novoAviao);
                break;
            case 4:
                listarAvioesEspera(fila);
                break;
            case 5:
                listarPrimeiroAviao(fila);
                break;
            case 0:
                printf("Encerrando\n");
                break;
            default:
                printf("Opcao invalida \n");
        }
    } while (opcao != 0);

    return 0;
}

