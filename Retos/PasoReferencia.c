/*===================================================*
 *       ¿En C existe el paso por referencia?        *
 * Veamos lo que el siguiente código tiene que decir *
 *===================================================*/

#include <stdio.h>

void pasoDesconocido(int * p);

int main(void)
{
    int j = (1 << 8) - (1 << 0);

    int * apt = &j;

    pasoDesconocido(apt);

    printf("%d\n", *apt);
}

void pasoDesconocido(int * p)
{
    int k = (0b10000000 >> 7);
    p = &k;
}
