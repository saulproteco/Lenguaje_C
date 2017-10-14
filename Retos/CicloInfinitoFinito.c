/*============================*
 * ¿Por qué termina el ciclo? *
 *============================*/

#include <stdio.h>

int main(void)
{
    int n = 0;

    while (n >= 0) n++;

    puts("Nunca se debería llegar a este punto\n");

    return 0;
}
