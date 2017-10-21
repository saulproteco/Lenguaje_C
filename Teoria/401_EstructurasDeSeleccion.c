/*==========================*
 * Sentencias de control en *
 *        lenguaje C        *
 *==========================*/

/**
 * Autor: Martínez Ortíz Saúl Axel
 * Dificultad: Básico.
 * Requisitos: Bases de lenguaje C.
 * Estilo de código: Miscelaneo.
 */

#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS

int main(void)
{
    int a = 3;

    printf("El valor de a es %d\n", a);
    // Condicional if: Estructura que evaláa una condición y en caso
    // de cumplirse ejecuta una instrucción o conjunto de ellas.
    // Opcionalmente se pueden especificar que hacer en caso de no
    // cumplirse la condición con la palabra reservada else.

    printf("¿a es igual a 3?\n");

    if (a == 3)  // Si se cumple la condición, ejecuta la línea siguiente
        printf("si\n");
    else         // Si no se cumple, ejecuta el caso contrario, esto se puede omitir
        printf("no\n");

    // if-else-if: Estructura que puede evaluar múltiples condiciones
    // secuencialmente. La ejecución de los códigos especificados en
    // las codiciones es mutuamente excluyente.

    printf("¿a es algún número entre 1 y 5?\n");

    if (a == 1)
        printf("si, a es 1\n");
    else if (a == 2)
        printf("si, a es 2\n");
    else if (a == 3)
        printf("si, a es 3\n");
    else if (a == 4)
        printf("si, a es 4\n");
    else if (a == 5)
        printf("si, a es 5\n");
    else
        printf("no\n");     // Todos los demás casos

    // switch: Estructura que compara el valor de una variable
    // con un conjunto de casos preestablecidos no repetidos y
    // ejecuta un código asociado a ellos.
    // La ejecución de dicho código puede ser o no
    // mutuamente excluyente dependiendo de como se estructure.

    // Forma mutuamente excluyente ( cada caso termina con break ) :
    //  Solo se ejecuta uno de los casos.
    printf("¿a es algún número entre 1 y 5?\n");
    switch (a) {
        case 1:
            printf("si, a es 1\n");
            break;

        case 2:
            printf("si, a es 2\n");
            break;

        case 3:
            printf("si, a es 3\n");
            break;

        case 4:
            printf("si, a es 4\n");
            break;

        case 5:
            printf("si, a es 5\n");
            break;

        default:    // Todos los demás casos
            printf("no\n");
            break;
    }

    // Forma incluyente (se omiten los break) :
    //  Se ejecuta el caso correspondiente y la variable y también todos
    //  los que vienen después de este hasta que se encuentre un break.
    printf("¿Qué números entre 1 y 5 son mayores o iguales que a?\n");
    switch (a) {
        case 1:
            printf("1 es mayor o igual que a\n");

        case 2:
            printf("2 es mayor o igual que a\n");

        case 3:
            printf("3 es mayor o igual que a\n");

        case 4:
            printf("4 es mayor o igual que a\n");

        case 5:
            printf("5 es mayor o igual que a\n");

        // El caso por defecto se puede omitir
    }

    return EXIT_SUCCESS;
}
