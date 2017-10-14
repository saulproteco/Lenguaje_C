/*=====================================*
 * Comparación Apuntador-Desreferencia *
 *=====================================*/

#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS

// Indique el resultado de la comparación mostrada y
// explique las razones de dicho hecho.

int main(void)
{
    int *apt = &apt;

    if (&apt == apt && &apt == *apt && apt == *apt)
        printf("Es verdad\n");
    else
        printf("Es mentira\n");

    return EXIT_SUCCESS;
}
