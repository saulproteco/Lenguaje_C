/*=================================*
 * Paso por valor y por referencia *
 *=================================*/

#include <stdio.h>

/*
 * ¿Cuál es la salida del siguiente código?
 * ¿En C existe el paso por referencia?
 */

void pasoDesconocido(int * p);

int main(void)
{
    int j = 1;

    int * apt = &j;

    pasoDesconocido(apt);

    printf("%d\n", *apt);
}

void pasoDesconocido(int * p)
{
    static int k = 2;
    p = &k;
}
