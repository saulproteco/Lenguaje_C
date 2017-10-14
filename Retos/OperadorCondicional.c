/*=====================================*
 * Indique el resultado tras evalua el *
 *        operador condicional         *
 *=====================================*/

#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS

int main(void)
{
    int a = 10;
    int b;

    b = a % 2 ? a < 5 ? a >= 5 ? 1 : 2 : 3 : 4;

    puts("¿Cuál es el valor de b?");

    printf("b es: %d\n", b);

    return EXIT_SUCCESS;
}
