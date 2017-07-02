/*
 * COdigo que usa la ecuaciOn cartesiana del circulo para imprimir su
 * forma y se usa la funciOn seno para imprimir una especie de ola
 * vertical.
 */
#include <stdio.h>
#include <math.h>

#define ANCHO 40.0

// Cambien la escala a lo que mejor se vea
#define ESCALA 1.5

int main(void) {
    int x, y;

    // Las grAficas que hacemos tienen el eje volteado
    //
    //  +-----------------> y
    //  |
    //  |
    //  |
    //  |
    //  |
    //  |
    //  v
    //  x

    // Circulo normal
    for (x = 0; x <= ANCHO; x++) {
        // Se obtiene el radio segUn la ecuaciOn del circulo despejada
        int radio = ESCALA * sqrt(x * (ANCHO - x));
        for (y = 0; y < ESCALA * ANCHO; y++) {
            putchar(y >= ANCHO / 2 * ESCALA - radio &&
                    y < ANCHO / 2 * ESCALA + radio ? '*' : ' ');
        }
        putchar('\n');
    }
    puts("Presiona una tecla para continuar . . ."); getchar();

    // Circulo invertido
    for (x = 0; x <= ANCHO; x++) {
        // Se obtiene el radio segUn la ecuaciOn del circulo despejada
        int radio = ESCALA * sqrt(x * (ANCHO - x));
        for (y = 0; y < ESCALA * ANCHO; y++) {
            putchar(y >= ANCHO / 2 * ESCALA - radio &&
                    y < ANCHO / 2 * ESCALA + radio ? ' ' : '*');
        }
        putchar('\n');
    }

    puts("Presiona una tecla para continuar . . ."); getchar();

    // Otra cosa rara
    for (x = 0; x <= ANCHO; x++) {
        // Se obtiene el radio segUn la ecuaciOn del circulo despejada
        int radio = ESCALA * sqrt(x * (ANCHO - x));
        for (y = 0; y < ESCALA * ANCHO; y++) {
            putchar(y >= ANCHO / 2 * ESCALA - radio &&
                    y < ANCHO / 2 * ESCALA + radio ?
                    ((x + y) % 2) == 0 ? '(' : ')':
                    ((x + y) % 2) == 0 ? '*' : '-');
        }
        putchar('\n');
    }
    return 0;
}
