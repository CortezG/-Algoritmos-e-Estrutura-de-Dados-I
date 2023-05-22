#include <stdio.h>
#include "cubo.h"

int main() {
    Cubo cubo;
    double lado;

    printf("Digite o tamanho do lado do cubo: ");
    scanf("%lf", &lado);

    inicializarCubo(&cubo, lado);

    double tamanho = tamanhoLado(&cubo);
    double area = calcularArea(&cubo);
    double volume = calcularVolume(&cubo);

    printf("Tamanho do lado: %.2lf\n", tamanho);
    printf("Área: %.2lf\n", area);
    printf("Volume: %.2lf\n", volume);

    return 0;
}
