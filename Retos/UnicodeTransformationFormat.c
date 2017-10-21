/*==========================================================*
 * El código marcado con la etiqueta box imprime una cadena *
 * encerrada entre caracteres de caja tomando en cuenta la  *
 * longitud de esta. Sin embargo no funciona bien con       *
 * algunas cadenas, explique el porque.                     *
 *==========================================================*/

#include <stdio.h>

int main(int c, char * v[])
{
    const char * apt = NULL;
    int x = 0;
    int i;

    if (c != 1)
        puts("世界こんいちは！");

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
    goto outa;

in:
    if (x == 0)         apt = "Hola que hace!!!";
    else if (x == -2)   apt = "Esta cadena se imprime correctamente", x = 0;

    while (*apt++) x++;
    apt -= x + 1;
    goto box;

outa:
    return 0;
}
