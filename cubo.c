#include "cubo.h"

void inicializarCubo(Cubo *cubo, double lado) {
    cubo->lado = lado;
}

double tamanhoLado(Cubo *cubo) {
    return cubo->lado;
}

double calcularArea(Cubo *cubo) {
    double area = 6 * cubo->lado * cubo->lado;
    return area;
}

double calcularVolume(Cubo *cubo) {
    double volume = cubo->lado * cubo->lado * cubo->lado;
    return volume;
}
