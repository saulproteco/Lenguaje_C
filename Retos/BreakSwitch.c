/*====================*
 * Cayendo en cascada *
 *====================*/

#include <stdio.h>

/*
 * ¿Qué imprime el código si opción vale 6?
 * ¿Y Qué imprime si vale 1?
 */

int main(void)
{
    int opcion = 1;

    printf("Elija una opción entre 1 y 6\n");

    switch (opcion) {
        case 1:
            printf("En ");

        case 2:
            printf("un ");

        case 3:
            printf("lugar ");

        case 4:
            printf("de ");

        case 5:
            printf("la ");

        case 6:
            printf("mancha...");

    }
}
