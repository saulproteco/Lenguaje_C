/*===============================================*
 * Sumando esfuerzos para multiplicar resultados *
 *===============================================*/

#include <stdio.h>

/*
 * Indique lo que va a imprimir
 * el siguiente código.
 */

int main(void)
{
    int a = 10, b = 7, c = 0;

    for (; a != 0; c % b ? 0 : (a > 0? a-- : a++))
        c += (a > 0) ? (b > 0) ? 1 : -1 : (b > 0) ? -1 : 1;

    printf("%d\n", c);
}
