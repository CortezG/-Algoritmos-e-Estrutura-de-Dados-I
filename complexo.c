#include "complexo.h"
#include <stdlib.h>

Complexo* criarComplexo(double real, double imag) {
    Complexo* complexo = (Complexo*)malloc(sizeof(Complexo));
    complexo->real = real;
    complexo->imag = imag;
    return complexo;
}

void destruirComplexo(Complexo* complexo) {
    free(complexo);
}

Complexo* somaComplexos(Complexo* c1, Complexo* c2) {
    Complexo* resultado = criarComplexo(0.0, 0.0);
    resultado->real = c1->real + c2->real;
    resultado->imag = c1->imag + c2->imag;
    return resultado;
}

Complexo* subtracaoComplexos(Complexo* c1, Complexo* c2) {
    Complexo* resultado = criarComplexo(0.0, 0.0);
    resultado->real = c1->real - c2->real;
    resultado->imag = c1->imag - c2->imag;
    return resultado;
}

Complexo* multiplicacaoComplexos(Complexo* c1, Complexo* c2) {
    Complexo* resultado = criarComplexo(0.0, 0.0);
    resultado->real = (c1->real * c2->real) - (c1->imag * c2->imag);
    resultado->imag = (c1->real * c2->imag) + (c1->imag * c2->real);
    return resultado;
}

Complexo* divisaoComplexos(Complexo* c1, Complexo* c2) {
    Complexo* resultado = criarComplexo(0.0, 0.0);
    double divisor = (c2->real * c2->real) + (c2->imag * c2->imag);
    resultado->real = ((c1->real * c2->real) + (c1->imag * c2->imag)) / divisor;
    resultado->imag = ((c1->imag * c2->real) - (c1->real * c2->imag)) / divisor;
    return resultado;
}
