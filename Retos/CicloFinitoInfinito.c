/*================================================*
 * Explique por que no termina el siguiente ciclo *
 *================================================*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned char caracter;

    for (caracter = 0; caracter < 256; caracter++)
        printf("El caracter %d es: %c\n", caracter, caracter);

    return EXIT_SUCCESS;
}
