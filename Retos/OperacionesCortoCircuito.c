/*==========================*
 * Alerta de corto circuito *
 *==========================*/

#include <stdio.h>

/*
 * Explique por que las siguientes sentencias
 * se ejecutan de forma diferente con operaciones de
 * y con operaciones lógicas.
 */

int main(void)
{
    printf("1.- Hola ") || printf("mundo\n");

    putchar('\n');
    printf("2.- Hola ") | printf("mundo\n");

    putchar('\n');
    printf("%*s", 0, "") && printf("1.- ¿Cómo estas?");

    putchar('\n');
    printf("%*s", 0, "") &  printf("2.- ¿Cómo estas?");

}
