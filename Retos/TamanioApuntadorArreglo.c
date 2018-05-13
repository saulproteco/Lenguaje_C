/*=====================================*
 * Apuntador pequeño, apuntador grande *
 *=====================================*/

// *** Código con comportamiento definido por la implementación ***

#include <stdio.h>

/*
 * Asumiendo las variables long y double tiene un tamaño de
 * 8 bytes. Indique la secuencia de impresiones del siguiente
 * código.
 *
 * ¿Qué imprime realmente en tu equipo?
 */

int main(void)
{
    int *pt;
    int (*ap)[sizeof(long)][sizeof(double)];

    printf("%zu\n", sizeof(pt));
    printf("%zu\n", sizeof(*pt));
    printf("%zu\n", sizeof(ap));
    printf("%zu\n", sizeof(*ap));
}
