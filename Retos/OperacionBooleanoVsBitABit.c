/*=============================================*
 * Explique por que las siguientes sentencias  *
 * se ejecutan distinto con operaciones de     *
 * y con operaciones lógicas.                  *
 *=============================================*/

#include <stdio.h>

int main(void)
{
    printf("1.- Hola ") || printf("mundo\n");

    putchar('\n');
    printf("2.- Hola ") | printf("mundo\n");

    putchar('\n');
    printf("%*s", 0, "") && printf("1.- ¿Cómo estas?");

    putchar('\n');
    printf("%*s", 0, "") &  printf("2.- ¿Cómo estas?");
    return 0;
}
