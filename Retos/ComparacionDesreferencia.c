/*=====================================*
 * Comparación Apuntador-Desreferencia *
 *=====================================*/

// *** ######################################### ***
// *** ######################################################## ***
// (Anotaciones censuradas porque espoilean la respuesta del ejercicio)

#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS

// Indique que imprime el siguiente código y
// explique la razón de que el programa tenga
// dicho comportamiento.
//
// ¿El programa funcionará igual en cualquier plataforma? Si, no y porque

int main(void)
{
    int *apt = &apt;

    if (&apt == apt && &apt == *apt && apt == *apt)
        printf("Es verdad\n");
    else
        printf("Es mentira\n");
}
