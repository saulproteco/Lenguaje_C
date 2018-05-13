/*====================*
 * ¿255 == Infinito ? *
 *====================*/

#include <stdio.h>

/*
 * Explique por que no termina el siguiente ciclo
 */

int main(void)
{
    unsigned char caracter;

    for (caracter = 0; caracter < 256; caracter++)
        printf("El carácter %d es: %c\n", caracter, caracter);
}
