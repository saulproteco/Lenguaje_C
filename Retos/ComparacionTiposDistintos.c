/*=========================================*
 * Cuando el ciclo for se reusa a trabajar *
 *=========================================*/

#include <stdio.h>

#define L(z) (sizeof(z) / sizeof(*z))

/*
 * Encuentre el error al imprimir
 * el arreglo y explíquelo.
 */

int main(void)
{
    int a[] = { 1, 2, 4, 5, 6, 7, 8 };

    for (int i = -1; i < L(a) - 1; ++i)
        printf("%d\n", a[i + 1]);
}
