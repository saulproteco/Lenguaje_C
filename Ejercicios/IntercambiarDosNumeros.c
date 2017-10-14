/*==================================*
 *       Respuestas Tarea 1         *
 * Intercambiar dos números enteros *
 *==================================*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * restrict argv[])
{
    int a, b;

    if ( argc == 3 ) {

        if ( !sscanf(argv[1], "%d", &a) || !sscanf(argv[2], "%d", &b) ) {
            // Algún valor no era completamente entero
            fputs("Números inválidos", stderr);
            exit(EXIT_FAILURE);
        }

    } else {

        puts("Ingrese dos números");

        if ( scanf("%d %d", &a, &b) != 2 ) // Algún valor no se leyó correctamente
            fputs("Error al leer los números", stderr), exit(EXIT_FAILURE);

    }

    printf("El número 1 es: %d\n"
           "El número 2 es: %d\n",
                   a, b);

    // Intercambio: forma uno, usando una variable auxiliar
    int aux;

    aux = a;
    a = b;
    b = aux;

    printf("Se hizo un cambio, ahora los números son:\n"
           "\tNúmero 1: %d\n"
           "\tNúmero 2: %d\n",
                   a, b);

    // Intercambio: forma dos, sumas y restas sin variable auxiliar

    a = a + b;
    b = a - b;
    a = a - b;

    printf("Después de otro cambio los números son:\n"
            "\tNúmero 1: %d\n"
            "\tNúmero 2: %d\n",
                    a, b);

    // Intercambio: forma tres, operaciones de bits
    a ^= b;
    b ^= a;
    a ^= b;

    printf("Despúes del último cambio, los números son:\n"
           "\tNúmero 1: %d\n"
           "\tNúmero 2: %d\n",
                   a, b);
    return 0;
}
