/*=========================*
 * ¿Codificación multi que? *
 *=========================*/

// *** El código asume que se usa la codificación UTF-8 ***

#include <stdio.h>
#include <stdlib.h>

/*
 * El código marcado con la etiqueta box imprime una cadena
 * encerrada entre caracteres de caja tomando en cuenta la
 * longitud de dicha cadena. Sin embargo no funciona bien con
 * algunas cadenas, explique el porque.
 */

int main(void)
{
    const char * apt = NULL;
    int x = 0;
    int i;

box:
    if (!apt) goto in;

    putchar('+');
    for (i = x; x >= -1; x--)
        putchar('-');
    putchar('+');
    printf("\n| %s |\n", apt);
    putchar('+');
    for (x = i; x >= -1; x--)
        putchar('-');
    puts("+");

    if (i == sizeof("こんにちは")) goto in;
    goto out;

in:
    if (x == 0)         apt = "Hola que hace!!!";
    else if (x == -2)   apt = "こんにちは", x = 0;

    while (*apt++) x++;
    apt -= x + 1;
    goto box;

out:
    return EXIT_SUCCESS;
}
