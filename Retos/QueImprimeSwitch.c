/*===================================================*
 * ¿Qué imprime el código si el usuario ingrea un 6? *
 * ¿Y Qué imprime cuando el usuario ingresa 1?       *
 *===================================================*/

#include <stdio.h>

int main(void)
{
    int opcion = -1;
    char linea[100];

    printf("Elija una opción entre 1 y 6\n");

    while (1) {
        printf(" > ");
        fgets(linea, 100, stdin);
        if ( sscanf(linea, "%d", &opcion) && opcion >= 1 && opcion <= 6 )
            break;
    }

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
    return 0;
}
