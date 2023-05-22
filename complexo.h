#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct {
    double real;
    double imag;
} Complexo;

Complexo* criarComplexo(double real, double imag);
void destruirComplexo(Complexo* complexo);
Complexo* somaComplexos(Complexo* c1, Complexo* c2);
Complexo* subtracaoComplexos(Complexo* c1, Complexo* c2);
Complexo* multiplicacaoComplexos(Complexo* c1, Complexo* c2);
Complexo* divisaoComplexos(Complexo* c1, Complexo* c2);

#endif
