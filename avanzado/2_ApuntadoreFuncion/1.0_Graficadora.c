#include <stdio.h>
#include <math.h>

#define ESCALA 1.7

void imprimirFuncionAlRevez(double (*f)(double x), double min, double max);

double equisCuadrada(double x) {
    return x * x / 10;
}

double circuloRadio50(double x) {
    if (x < 50) return (50 - sqrt(2500 - x * x));
    else        return 1000;
}

int main(void) {
    imprimirFuncionAlRevez(equisCuadrada, 0, 20);
    imprimirFuncionAlRevez(circuloRadio50, 0, 50);
    return 0;
}

void imprimirFuncionAlRevez(double (*f)(double x), double min, double max) {
    for (int x = min, y = f(min) / ESCALA; x < max; x++) {
        while ( y < f(x) / ESCALA) { putchar('\v'), y++; }
        putchar('*');
    }
    putchar('\n');
}

