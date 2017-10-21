/*===========================================*
 * Demostración de los operadores lógicos en *
 *              el lenguaje C                *
 *===========================================*/

/**
 * Autor: Martínez Ortíz Saúl Axel
 * Dificultad: Básico.
 * Requisitos: Estructuras de control.
 * Estilo de código: GNU.
 */

#include <stdio.h>      // puts, printf
#include <stdlib.h>     // EXIT_SUCCESS
#include <stdbool.h>    // bool, false, true

static const char * verdarero_falso (bool condicion)
{
    if (condicion == true)  return "true";
    if (condicion == false) return "false";
}

int main (void)
{
    /* Los operadores lógicos sirven para entrelazar valores *
     * de verdad (los cuales pueden ser obtenidos mediante   *
     * operadores condicionales) de forma que se unan        *
     * condiciones individuales en una condición compuesta   */

    puts ("Tablas de verdad de los operadores lógicos:\n");

    puts ("Operador OR (||)");

    printf ("false || false = %s\n", verdarero_falso(false || false));
    printf ("false || true  = %s\n", verdarero_falso(false || true));
    printf ("true  || false = %s\n", verdarero_falso(true  || false));
    printf ("true  || true  = %s\n", verdarero_falso(true  || true));

    puts ("\nOperador AND (&&)");

    printf ("false && false = %s\n", verdarero_falso(false || false));
    printf ("false && true  = %s\n", verdarero_falso(false || true));
    printf ("true  && false = %s\n", verdarero_falso(true  || false));
    printf ("true  && true  = %s\n", verdarero_falso(true  || true));

    puts ("\nOperador NOT (!)");

    printf ("!false = %s\n", verdarero_falso(!false));
    printf ("!true  = %s\n", verdarero_falso(!true));

    /* Si se usan valores estrictamente booleanos, los operadores   *
     * de bits deberían tener el mismo efecto que los operadores    *
     * lógicos aunque serian un poco menos eficientes.              */

    return EXIT_SUCCESS;
}
