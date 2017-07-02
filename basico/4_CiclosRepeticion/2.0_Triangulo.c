/*
 * COdigo de c que imprime un par de triangulos usando ciclos
 */

#include <stdio.h>

#define ANCHO 20.0
#define ESCALA 2.0

int main(void) {
    int x, y;

    for (x = 0; x <= ANCHO; x++) {
        for (y = 0; y < ESCALA * ANCHO; y++) {
            putchar(y <= x * ESCALA ? '*' : ' ');
        }
        putchar('\n');
    }

    putchar('\n');

    // Se invierte la secuencia de espacios y asteriscos
    // (si se quita el putchar anterior se juntan formando un rombo)
    for (x = 0; x <= ANCHO; x++) {
        for (y = 0; y < ESCALA * ANCHO; y++) {
            putchar(y <= x * ESCALA ? ' ' : '*');
        }
        putchar('\n');
    }

    getchar();
    return 0;
}
