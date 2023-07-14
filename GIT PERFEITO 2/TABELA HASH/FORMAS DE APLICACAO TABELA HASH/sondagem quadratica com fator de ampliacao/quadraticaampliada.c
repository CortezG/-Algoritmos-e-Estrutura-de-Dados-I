#include <stdio.h>
#include <stdlib.h>

// Definição do TAD TabelaHash
typedef struct {
    int *tabela;
    int tamanho;
} TabelaHash;

TabelaHash *criar_tabela(int tamanho) {
    TabelaHash *tabela = malloc(sizeof(TabelaHash));
    tabela->tabela = calloc(tamanho, sizeof(int));
    tabela->tamanho = tamanho;
    return tabela;
}

int hash_sondagem_quadratica_ampliada(int chave, int i, int tamanho) {
    return (chave + 2 * i + i * i) % tamanho;
}

void inserir(TabelaHash *tabela, int chave) {
    int i = 0;
    int indice = hash_sondagem_quadratica_ampliada(chave, i, tabela->tamanho);

    while (tabela->tabela[indice] != 0) {
        i++;
        indice = hash_sondagem_quadratica_ampliada(chave, i, tabela->tamanho);
    }

    tabela->tabela[indice] = chave;
}

void imprimir_tabela(TabelaHash *tabela) {
    for (int i = 0; i < tabela->tamanho; i++) {
        printf("Índice %d: ", i);
        if (tabela->tabela[i] != 0) {
            printf("%d", tabela->tabela[i]);
        }
        printf("\n");
    }
}

void liberar_tabela(TabelaHash *tabela) {
    free(tabela->tabela);
    free(tabela);
}

int main() {
    int tamanho_tabela = 11;

    // Cria a tabela hash
    TabelaHash *tabela = criar_tabela(tamanho_tabela);

    // Chaves a serem inseridas
    int chaves[] = {365, 112, 180, 213, 13, 27};
    int num_chaves = sizeof(chaves) / sizeof(chaves[0]);

    // Insere as chaves na tabela
    for (int i = 0; i < num_chaves; i++) {
        inserir(tabela, chaves[i]);
    }

    // Imprime a tabela hash
    imprimir_tabela(tabela);

    // Libera a memória alocada
    liberar_tabela(tabela);

    return 0;
}
