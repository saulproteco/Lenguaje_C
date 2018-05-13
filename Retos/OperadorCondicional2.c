/*===========================*
 * Un radio de posibilidades *
 *===========================*/

#include <stdio.h>  // putchar, getchar
#include <stdlib.h> // EXIT_SUCCESS
#include <math.h>   // sqrt

/*
 * Trate de visualizar la lo que imprimirá el
 * siguiente código.
 */

#define ANCHO  40.0
#define ESCALA  2.0

int main(void)
{
    for (int x = 0; x <= ANCHO; x++) {
        int radio = ESCALA * sqrt(x * (ANCHO - x));

        for (int y = 0; y < ESCALA * ANCHO; y++) {
            putchar(y >= ANCHO / 2 * ESCALA - radio &&
                    y < ANCHO / 2 * ESCALA + radio ?
                    ((x + y) % 2) == 0 ? '(' : ')':
                    ((x + y) % 2) == 0 ? '*' : '-');
        }
        putchar('\n');
    }

    return EXIT_SUCCESS;
}
