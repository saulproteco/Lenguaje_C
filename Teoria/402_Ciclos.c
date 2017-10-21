/*===========================================*
 * Ciclos de repetición en lenguaje C        *
 *                                           *
 * Descripción:                              *
 * Estructura básica de los ciclos de        *
 * repetición de lenguaje  C.                *
 *===========================================*/

/**
 * Autor: Martínez Ortíz Saúl Axel
 * Dificultad: Básico.
 * Requisitos: Bases de lenguaje C.
 * Estilo de código: Linux modificado (4 espacios por tab).
 */

#include <stdio.h>  // printf, puts
#include <stdlib.h> // EXIT_SUCCESS

int main(void)
{
    /* Los ciclos de repetición son estructuras que nos permite *
     * ejecutar de forma controlada un conjunto (o sola una)    *
     * instrucciones con base al valor de cierta condición.     *
     * La condición por lo general tendrá que modificarse a lo  *
     * largo de las repeticiones del ciclo de manera que este   *
     * pueda terminar. En algunas ocasiones hacer un ciclo que  *
     * no termina será un comportamiento deseable pero en la    *
     * mayoría de las ocasiones se tratará de un error lógico.  */

    // Ciclo while
    //
    // while (condición) instrucción;
    //
    // while (condición) { conjunto_instrucciones }

    int contador = 0;
    puts("\n===========================================================\n");
    puts("\n\t\t\tCiclo while\n");

    printf("Ciclo ascendente:\n");
    while (contador++ < 10)
        printf("Contador es: %d\n", contador);

    printf("\nCiclo descendiente:\n");
    while (contador > 1) {
        contador--;
        printf("Contador es: %d\n", contador);
    }

    printf("\nOtro ciclo ascendiente\n");
    while (printf("Contador es %d\n", contador), contador++ < 10)
        ;   // instrucción vacía (todo se hace dentro de la condición)

    // Ciclo for
    //
    // for (condiciones_iniciales; condicion_paro; cambio_por_iteracion)
    //      instrucción;
    //
    // for (condiciones_iniciales; condicion_paro; cambio_por_iteracion)
    // {
    //      conjunto_instrucciones
    // }
    puts("\n===========================================================\n");
    puts("\n\t\t\tCiclo for\n");

    printf("Los números del 1 al 10:\n");
    for (int otro_contador = 1; otro_contador <= 10; otro_contador++) {
        printf("El contador es: %d\n", otro_contador);
    }

    int indice;
    for (indice = 0; "¡Cadena salvaje aparece!"[indice]; indice++)
        ; // Instrucción vacía

    printf("La longitud de la cadena \"¡Cadena salvaje aparece!\" es: %d\n", indice);
    puts("(Toma en cuenta que los caracteres utf-8 como \"¡\" usan 2 bytes)");


    // Ciclo do-while (primero ejecuta y luego revisa la condición)
    //
    // Se puede usar de forma similar al while con la excepción de que
    // independientemente del valor de la condición, este ciclo siempre
    // se ejecuta una vez.
    //
    //  do instruccion; while(condición);
    //
    //  do {
    //      conjunto_instrucciones
    //  } while (condición);

    do {
        printf("No importa que la condición sea falsa desde el principio\n"
               "porque esto se va a ejecuar igualmente");
    } while (0);

    return EXIT_SUCCESS;
}
