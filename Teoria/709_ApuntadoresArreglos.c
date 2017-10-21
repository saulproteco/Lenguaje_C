/*===========================================*
 * Representación en memoria de los arreglos *
 * y como referenciarlos con apuntadores.    *
 *===========================================*/

#include <stdio.h>

int main(void)
{
    /* Los arreglos siempre se almacenan en espacios congios de memoria *
     * sin importar su dimensión. Esto es contrario a lo que pasa con   *
     * los pseudo-arreglos reservados con memoria dinámica que pueden   *
     * estar esparcidos en memoria dado que en un inicio se reserva una *
     * tira extra de apuntadores para referenciar los pedazos           *
     * esparcidos.                                                      *
     */

    int arreglo1[10];

    return 0;
}
