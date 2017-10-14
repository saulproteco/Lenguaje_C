/*===========================================*
 * Indique si el resultado de la comparación *
 * es verdadero o falso                      *
 *===========================================*/

#include <stdio.h>

int main(void)
{
    float a = 0.1 + 0.2 + 0.3;
    double b = 0.1 + 0.2 + 0.3;

    if ( a == b )
        puts("Es verdad\n");
    else
        puts("Es falso\n");

    getchar();

    return 0;
}
