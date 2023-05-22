#include <stdio.h>
#include "complexo.h"

int main() {
    Complexo* z1 = criarComplexo(2.0, 3.0);
    Complexo* z2 = criarComplexo(1.0, -2.0);

    Complexo* soma = somaComplexos(z1, z2);
    Complexo* subtracao = subtracaoComplexos(z1, z2);
    Complexo* multiplicacao = multiplicacaoComplexos(z1, z2);
    Complexo* divisao = divisaoComplexos(z1, z2);

    printf("Soma: %.2lf + %.2lfi\n", soma->real, soma->imag);
    printf("Subtração: %.2lf + %.2lfi\n", subtracao->real, subtracao->imag);
    printf("Multiplicação: %.2lf + %.2lfi\n", multiplicacao->real, multiplicacao->imag);
    printf("Divisão: %.2lf + %.2lfi\n", divisao->real, divisao->imag);

    destruirComplexo(z1);
    destruirComplexo(z2);
    destruirComplexo(soma);
    destruirComplexo(subtracao);
    destruirComplexo(multiplicacao);
    destruirComplexo(divisao);

    return 0;
}
