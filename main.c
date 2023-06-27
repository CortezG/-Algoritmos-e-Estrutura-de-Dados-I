#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#include <stdio.h>
#include "pilha.h"

int main() {
    Hangar hangar;
    inicializarHangar(&hangar);

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1. Numero de avioes no hangar\n");
        printf("2. Remover um aviao\n");
        printf("3. Adicionar um aviao\n");
        printf("4. Listar todos os avioes\n");
        printf("5. Caracteristicas do primeiro aviao\n");
        printf("6. Remover aviao pela posicao\n");
        printf("0. Sair\n");
        printf("Opcao: ");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarAvioesAguardando(&hangar);
                break;
            case 2:
                tirarAviao(&hangar);
                break;
            case 3:
                if (!HangarCheio(&hangar)) {
                    Aviao aviao;
                    printf("Id do aviao: ");
                    scanf("%d", &aviao.identificador);
                    printf("Nome do aviao: ");
                    scanf("%s", aviao.nome);
                    adicionarAviao(&hangar, aviao);
                } else {
                    printf("Hangar cheio\n");
                }
                break;
            case 4:
                listarAvioes(&hangar);
                break;
            case 5:
                listarPrimeiroAviao(&hangar);
                break;
            case 6:
                if (!HangarVazio(&hangar)) {
                    int posicao;
                    printf("Posicao do aviao a ser removido: ");
                    scanf("%d", &posicao);
                    tirarAviaoPosicao(&hangar, posicao);
                } else {
                    printf("Nao ha avioes no hangar\n");
                }
                break;
            case 0:
                return 0;
            default:
                printf("Opcao invalida\n");
        }
    }

    return 0;
}
