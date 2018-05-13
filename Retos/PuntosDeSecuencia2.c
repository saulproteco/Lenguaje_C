/*=========================*
 * Intercambios peligrosos *
 *=========================*/

// *** Código con comportamiento definido por la implementación ***
// *** Código sujeto a comportamiento indefinido ***

#include <stdio.h>

/*
 * Corrija el siguiente código para no caer en comportamiento indefinido
 * y para manejar valores especiales
 */

int main(void)
{
    int a = 10;
    int b = 20;

    a ^= b ^= a ^=b;

    printf("%d\n", a);
    printf("%d\n", b);
}
