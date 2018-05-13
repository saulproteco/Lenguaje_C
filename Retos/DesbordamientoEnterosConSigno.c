/*======================*
 * ¿Infinito == Finito? *
 *======================*/

// *** Código sujeto a comportamiento indefinido ***

#include <stdio.h>

/*
 * ¿Por qué termina el ciclo?
 */

int main(void)
{
    int n = 0;

    while (n >= 0) n++;

    puts("Nunca se debería llegar a este punto\n");
}
